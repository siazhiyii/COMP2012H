#include "numpy_lite.h"
#include <iostream>
#include <cassert>
#include <cmath>

// Helper function to check if two NDArrays are equal
bool are_equal(const NDArray &a, const NDArray &b)
{
    if (a.ndim != b.ndim)
        return false;
    for (int i = 0; i < a.ndim; ++i)
    {
        if (a.shape[i] != b.shape[i])
            return false;
    }
    for (int i = 0; i < a.compute_size(); ++i)
    {
        if (a.storage->data[i] != b.storage->data[i])
            return false;
    }
    return true;
}

void test_creation_and_access()
{
    std::cout << "Testing array creation and element access..." << std::endl;
    int data[] = {1, 2, 3, 4, 5, 6};
    int shape[] = {2, 3};
    NDArray arr = array(data, shape, 2);

    int indices1[] = {0, 0};
    int indices2[] = {1, 2};
    int indices3[] = {0, 1};

    assert(arr.get(indices1) == 1);
    assert(arr.get(indices2) == 6);

    arr.set(indices3, 10);
    assert(arr.get(indices3) == 10);

    std::cout << "Array creation and access tests passed." << std::endl;
}

void test_reshape()
{
    std::cout << "Testing reshape..." << std::endl;
    int data[] = {1, 2, 3, 4, 5, 6};
    int shape[] = {2, 3};
    NDArray arr = array(data, shape, 2);

    int new_shape[] = {3, 2};
    NDArray reshaped = arr.reshape(new_shape, 2);

    int indices1[] = {0, 0};
    int indices2[] = {2, 1};
    assert(reshaped.ndim == 2);
    assert(reshaped.shape[0] == 3 && reshaped.shape[1] == 2);
    assert(reshaped.get(indices1) == 1 && reshaped.get(indices2) == 6);

    std::cout << "Reshape tests passed." << std::endl;
}

void test_arithmetic()
{
    std::cout << "Testing arithmetic operations..." << std::endl;
    int data1[] = {1, 2, 3, 4};
    int data2[] = {5, 6, 7, 8};
    int shape[] = {2, 2};

    NDArray arr1 = array(data1, shape, 2);
    NDArray arr2 = array(data2, shape, 2);

    NDArray sum = arr1.add(arr2);
    int indices[] = {0, 0};
    assert(sum.get(indices) == 6);
    indices[0] = 1;
    indices[1] = 1;
    assert(sum.get(indices) == 12);

    NDArray diff = arr2.subtract(arr1);
    indices[0] = 0;
    indices[1] = 0;
    assert(diff.get(indices) == 4);
    indices[0] = 1;
    indices[1] = 1;
    assert(diff.get(indices) == 4);

    NDArray prod = arr1.multiply(arr2);
    indices[0] = 0;
    indices[1] = 0;
    assert(prod.get(indices) == 5);
    indices[0] = 1;
    indices[1] = 1;
    assert(prod.get(indices) == 32);

    std::cout << "Arithmetic operation tests passed." << std::endl;
}

void test_matmul()
{
    std::cout << "Testing matrix multiplication..." << std::endl;
    int data1[] = {1, 2, 3, 4};
    int data2[] = {5, 6, 7, 8};
    int shape[] = {2, 2};

    NDArray arr1 = array(data1, shape, 2);
    NDArray arr2 = array(data2, shape, 2);

    NDArray result = arr1.matmul(arr2);
    int indices[] = {0, 0};
    assert(result.get(indices) == 19);
    indices[1] = 1;
    assert(result.get(indices) == 22);
    indices[0] = 1;
    indices[1] = 0;
    assert(result.get(indices) == 43);
    indices[1] = 1;
    assert(result.get(indices) == 50);

    std::cout << "Matrix multiplication tests passed." << std::endl;
}

int main()
{
    test_creation_and_access();
    test_reshape();
    test_arithmetic();
    test_matmul();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}