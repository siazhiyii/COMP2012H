#include "numpy_lite.h"
#include <iostream>
#include <cstring>

// Helper functions
Storage::Storage(size_t size) : size(size), ref_count(1)
{
    data = new int[size]();
}

Storage::~Storage()
{
    delete[] data;
}

void NDArray::compute_strides()
{
    int stride = 1;
    for (int i = ndim - 1; i >= 0; --i)
    {
        strides[i] = stride;
        stride *= shape[i];
    }
}

void NDArray::ensure_writability()
{
    // This function is CRUCIAL for the copy-on-write mechanism
    if (!writable)
    {
        // Create a new storage and copy the data
        Storage *new_storage = new Storage(storage->size);
        std::memcpy(new_storage->data, storage->data, storage->size * sizeof(int));

        // Decrease the reference count of the old storage
        if (--storage->ref_count == 0)
        {
            delete storage;
        }

        // Update the storage and make it writable
        storage = new_storage;
        writable = true;
    }
}

size_t NDArray::compute_size() const
{
    size_t size = 1;
    for (int i = 0; i < ndim; ++i)
    {
        size *= shape[i];
    }
    return size;
}

size_t NDArray::compute_offset(const int *indices) const
{
    size_t offset = 0;
    for (int i = 0; i < ndim; ++i)
    {
        offset += indices[i] * strides[i];
    }
    return offset;
}

void NDArray::print() const
{
    if (ndim == 1)
    {
        std::cout << "[";
        for (int i = 0; i < shape[0]; ++i)
        {
            std::cout << storage->data[i];
            if (i < shape[0] - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    else if (ndim == 2)
    {
        std::cout << "[" << std::endl;
        for (int i = 0; i < shape[0]; ++i)
        {
            std::cout << "  [";
            for (int j = 0; j < shape[1]; ++j)
            {
                std::cout << storage->data[i * strides[0] + j];
                if (j < shape[1] - 1)
                    std::cout << ", ";
            }
            std::cout << "]";
            if (i < shape[0] - 1)
                std::cout << "," << std::endl;
        }
        std::cout << std::endl
                  << "]" << std::endl;
    }
    else if (ndim == 3)
    {
        std::cout << "[" << std::endl;
        for (int i = 0; i < shape[0]; ++i)
        {
            std::cout << " [" << std::endl;
            for (int j = 0; j < shape[1]; ++j)
            {
                std::cout << "  [";
                for (int k = 0; k < shape[2]; ++k)
                {
                    std::cout << storage->data[i * strides[0] + j * strides[1] + k];
                    if (k < shape[2] - 1)
                        std::cout << ", ";
                }
                std::cout << "]";
                if (j < shape[1] - 1)
                    std::cout << "," << std::endl;
            }
            std::cout << std::endl
                      << " ]";
            if (i < shape[0] - 1)
                std::cout << "," << std::endl;
        }
        std::cout << std::endl
                  << "]" << std::endl;
    }
    else
    {
        std::cout << "Array with " << ndim << " dimensions" << std::endl;
    }
}

int NDArray::get(const int *indices) const
{
    return storage->data[compute_offset(indices)];
}

void NDArray::set(const int *indices, int value)
{
    ensure_writability();
    storage->data[compute_offset(indices)] = value;
}

// A factory function similar to np.array
NDArray array(const int *data, const int *shape, int ndim)
{
    return NDArray(data, shape, ndim);
}

NDArray::NDArray(const int *data, const int *shape, int ndim) : ndim(ndim), writable(true)
{
    this->shape = new int[ndim];
    std::memcpy(this->shape, shape, ndim * sizeof(int));

    size_t size = compute_size();
    storage = new Storage(size);
    std::memcpy(storage->data, data, size * sizeof(int));

    strides = new int[ndim];
    compute_strides();
}

NDArray::NDArray(const NDArray &other) : ndim(other.ndim), writable(false)
{
    shape = new int[ndim];
    std::memcpy(shape, other.shape, ndim * sizeof(int));

    strides = new int[ndim];
    std::memcpy(strides, other.strides, ndim * sizeof(int));

    storage = other.storage;
    storage->ref_count++;
}

NDArray::~NDArray()
{
    delete[] shape;
    delete[] strides;
    if (--storage->ref_count == 0)
    {
        delete storage;
    }
}

// TODO 1: Array reshaping
NDArray NDArray::reshape(const int *new_shape, int new_ndim) const
{
    // Please implement this
    size_t new_size = 1;
    for (int i = 0; i < new_ndim; ++i)
    {
        new_size *= new_shape[i];
    }

    if (new_size != (storage->size))
    {
        throw std::runtime_error("New shape is not compatible with the current data size");
    }

    NDArray reshaped_array = array(storage->data, new_shape, new_ndim);
    return reshaped_array;
}

// TODO 2: Array concatenation

NDArray concatenate(const NDArray &arr1, const NDArray &arr2, int axis)
{
    if (arr1.ndim != arr2.ndim)
    {
        throw std::runtime_error("Arrays must have the same number of dimensions");
    }

    for (int i = 0; i < arr1.ndim; ++i)
    {
        if (i != axis && (arr1.shape[i] != arr2.shape[i]))
        {
            throw std::runtime_error("Arrays must have the same shape except in the concatenation axis");
        }
    }

    if (arr1.ndim > 2 || arr2.ndim > 2)
    {
        throw std::runtime_error("Arrays must have at most 2 dimensions");
    }

    int new_shape[arr1.ndim];

    for (int i = 0; i < arr1.ndim; ++i)
    {
        if (i == axis)
        {
            new_shape[i] = arr1.shape[i] + arr2.shape[i];
        }
        else
        {
            new_shape[i] = arr1.shape[i];
        }
    }

    size_t new_size = arr1.storage->size + arr2.storage->size;

    Storage *new_storage = new Storage(new_size);

    size_t new_arr_i = 0;

    if (axis == 0)
    {
        for (int i = 0; i < arr1.storage->size; ++i)
        {
            new_storage->data[new_arr_i] = arr1.storage->data[i];
            new_arr_i++;
        }
        for (int i = 0; i < arr2.storage->size; ++i)
        {
            new_storage->data[new_arr_i] = arr2.storage->data[i];
            new_arr_i++;
        }
    }
    else if (axis == 1)
    {
        for (int i = 0; i < new_shape[0]; ++i)
        {
            for (int j = 0; j < arr1.shape[1]; ++j)
            {
                new_storage->data[new_arr_i] = arr1.storage->data[i * arr1.shape[1] + j];
                new_arr_i++;
            }
            for (int j = 0; j < arr2.shape[1]; ++j)
            {
                new_storage->data[new_arr_i] = arr2.storage->data[i * arr2.shape[1] + j];
                new_arr_i++;
            }
        }
    }

    NDArray concatenated_array = array(new_storage->data, new_shape, arr1.ndim);
    delete new_storage;
    return concatenated_array;
}

// TODO 3: Element-wise operations
NDArray NDArray::add(const NDArray &other) const
{
    // Please implement this
    if (shape[0] != other.shape[0] && shape[1] != other.shape[1])
    {
        throw std::runtime_error("Shapes are not the same");
    }

    NDArray add_array = array(storage->data, shape, ndim);

    int lenArr = 1;

    for (int i = 0; i < ndim; i++)
    {
        lenArr *= shape[i];
    }
    for (int i = 0; i < lenArr; i++)
    {
        add_array.storage->data[i] = storage->data[i] + other.storage->data[i];
    }

    return add_array;
}

NDArray NDArray::subtract(const NDArray &other) const
{
    // Please implement this
    if (shape[0] != other.shape[0] && shape[1] != other.shape[1])
    {
        throw std::runtime_error("Shapes are not the same");
    }

    NDArray sub_array = array(storage->data, shape, ndim);

    int lenArr = 1;

    for (int i = 0; i < ndim; i++)
    {
        lenArr *= shape[i];
    }
    for (int i = 0; i < lenArr; i++)
    {
        sub_array.storage->data[i] = storage->data[i] - other.storage->data[i];
    }

    return sub_array;
}

NDArray NDArray::multiply(const NDArray &other) const
{
    // Please implement this
    if (shape[0] != other.shape[0] && shape[1] != other.shape[1])
    {
        throw std::runtime_error("Shapes are not the same");
    }

    NDArray mul_array = array(storage->data, shape, ndim);

    int lenArr = 1;

    for (int i = 0; i < ndim; i++)
    {
        lenArr *= shape[i];
    }
    for (int i = 0; i < lenArr; i++)
    {
        mul_array.storage->data[i] = storage->data[i] * other.storage->data[i];
    }

    return mul_array;
}

// TODO 4: Matrix multiplication
NDArray NDArray::matmul(const NDArray &other) const
{
    // Please implement this
    if (shape[1] != other.shape[0])
    {
        throw std::runtime_error("Shapes are not compatible for matrix multiplication");
    }

    int new_shape[] = {shape[0], other.shape[1]};

    int new_size = new_shape[0] * new_shape[1];

    Storage *new_storage = new Storage(new_size);

    for (int i = 0; i < shape[0]; ++i)
    {
        for (int j = 0; j < other.shape[1]; ++j)
        {
            new_storage->data[i * other.shape[1] + j] = 0;
            for (int k = 0; k < shape[1]; ++k)
            {
                new_storage->data[i * other.shape[1] + j] += storage->data[i * shape[1] + k] * other.storage->data[k * other.shape[1] + j];
            }
        }
    }

    NDArray mulmat_array = array(new_storage->data, new_shape, ndim);

    return mulmat_array;
}

// int main()
// {
//     std::cout << "Testing concatenation..." << std::endl;
//     int data1[] = {1, 2, 3, 4,5,6};
//     int data2[] = {7,8,9,10};
//     int shape[] = {2, 3};
//     int shape2[] = {2, 2};

//     NDArray arr1 = array(data1, shape, 2);
//     NDArray arr2 = array(data2, shape2, 2);

//     NDArray concatenated = concatenate(arr1, arr2, 1);
//     concatenated.print();

// std::cout << "Concatenated array along axis 0:" << std::endl;
// concatenated.print();

// std::cout << "Expected ndim: 2, Actual ndim: " << concatenated.ndim << std::endl;
// std::cout << "Expected shape: [4, 2], Actual shape: [" << concatenated.shape[0] << ", " << concatenated.shape[1] << "]" << std::endl;

// int indices[] = {0, 0};
// std::cout << "Expected value at (0, 0): 1, Actual value: " << concatenated.get(indices) << std::endl;
// indices[0] = 3;
// indices[1] = 1;
// std::cout << "Expected value at (3, 1): 8, Actual value: " << concatenated.get(indices) << std::endl;

// // Test concatenation along axis 1
// NDArray concatenated2 = concatenate(arr1, arr2, 1);

// std::cout << "Concatenated array along axis 1:" << std::endl;
// concatenated2.print();

// std::cout << "Expected ndim: 2, Actual ndim: " << concatenated2.ndim << std::endl;
// std::cout << "Expected shape: [2, 4], Actual shape: [" << concatenated2.shape[0] << ", " << concatenated2.shape[1] << "]" << std::endl;

// indices[0] = 0;
// indices[1] = 0;
// std::cout << "Expected value at (0, 0): 1, Actual value: " << concatenated2.get(indices) << std::endl;
// indices[0] = 1;
// indices[1] = 3;
// std::cout << "Expected value at (1, 3): 8, Actual value: " << concatenated2.get(indices) << std::endl;

// std::cout << "Concatenation tests passed." << std::endl;

//     return 0;
// }