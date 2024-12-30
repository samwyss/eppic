#ifndef FIELDS_SCALAR3_HPP
#define FIELDS_SCALAR3_HPP

#include <cstddef>
#include <cstdint>

#include "triplet.hpp"

template <typename T>
class Scalar3
{
public:
    /*!
     * Scalar3 constructor
     * @param num_x number of cells in the x-direction
     * @param num_y number of cells in the y-direction
     * @param num_z number of cells in the z-direction
     * @param value initial value to instantiate all field values to
     */
    Scalar3(size_t num_x, size_t num_y, size_t num_z, T value);

    /*!
     * Scalar3 destructor
     */
    ~Scalar3();

    /*!
     * Scalar3 overloaded () operator for read-write access
     * @param i index into x-direction elements
     * @param j index into y-direction elements
     * @param k index into z-direction elements
     * @return pointer to element at desired index
     */
    T* operator()(size_t i, size_t j, size_t k);

    /*!
     * Scalar3 overloaded () operator for read access
     * @param i index into x-direction elements
     * @param j index into y-direction elements
     * @param k index into z-direction elements
     * @return pointer to element at desired index
     */
    const T& operator()(size_t i, size_t j, size_t k) const;

    /*!
     * Scalar3 overloaded assignment operator to spatially constant scalar value
     * @param rhs spatially constant scalar value
     * @return reference to existing Scalar3
     */
    Scalar3& operator=(const T& rhs);

private:
    /// 1D array in row-major format containing field data
    T* data;

    /// number of cells in each direction
    const Triplet<size_t> num_cells;

    /// number of cells in each row
    const size_t row_cells;

    /// number of cells in each plane
    const size_t plane_cells;

    /// number of cells in volume
    const size_t vol_cells;
};


#endif //FIELDS_SCALAR3_HPP