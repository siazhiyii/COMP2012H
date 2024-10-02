#pragma once

#include <cstddef>

struct Storage {
    int* data;
    size_t size;
    int ref_count;

    Storage(size_t size);
    ~Storage();
};

struct NDArray {
    Storage* storage;
    int* shape;
    int* strides;
    int ndim;
    bool writable;  // Copy-on-write flag

    NDArray(const int* data, const int* shape, int ndim);
    NDArray(const NDArray& other);
    ~NDArray();

    void ensure_writability();  // Copy-on-write mechanism

    int get(const int* indices) const;
    void set(const int* indices, int value);
    NDArray reshape(const int* new_shape, int new_ndim) const;
    NDArray add(const NDArray& other) const;
    NDArray subtract(const NDArray& other) const;
    NDArray multiply(const NDArray& other) const;
    NDArray matmul(const NDArray& other) const;
    void print() const;

    void compute_strides();
    size_t compute_size() const;
    size_t compute_offset(const int* indices) const;
};

// Factory function (similar to np.array)
NDArray array(const int* data, const int* shape, int ndim);

// Standalone concatenate function
NDArray concatenate(const NDArray& arr1, const NDArray& arr2, int axis);
