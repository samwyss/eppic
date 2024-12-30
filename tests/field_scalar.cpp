#include <gtest/gtest.h>

#include "scalar.hpp"
#include "triplet.hpp"

/// number of cells in x-direction for simple Scalar3<T>
constexpr size_t NUM_X = 1;

/// number of cells in y-direction for simple Scalar3<T>
constexpr size_t NUM_Y = 2;

/// number of cells in z-direction for simple Scalar3<T>
constexpr size_t NUM_Z = 3;

/*!
 * sets up a simple Scalar3
 * @tparam T Scalar3 template parameter
 * @return Scalar3<T>
 */
template <typename T>
Scalar3<T> setup_scalar3()
{
    // simple geometry and initial values
    constexpr auto VAL = 4; // this will implicit cast

    // construct a Scalar3<T>
    Scalar3<T> scalar3(NUM_X, NUM_Y, NUM_Z, VAL);

    // return Scalar3<T>
    return scalar3;
}

/// tests for successful Scalar3 constructor call with double as template parameter
TEST(field_scalar3, constructor_success_double)
{
    // constructor should not fail with template parameter as double
    ASSERT_NO_THROW(setup_scalar3<double>());
}

/// tests for successful Scalar3 constructor call with uint64_t as template parameter
TEST(field_scalar3, constructor_success_uint64_t)
{
    // constructor should not fail with template parameter as uint64_t
    ASSERT_NO_THROW(setup_scalar3<uint64_t>());
}

/// tests for correct initialization of num_cells member
TEST(field_scalar3, constructor_correct_num_cells)
{
    // construct Scalar3<T>
    const auto scalar3 = setup_scalar3<double>();

    // construct Triplet<T>
    constexpr Triplet<size_t> triplet{NUM_X, NUM_Y, NUM_Z};

    // assert all members are equal to constructed Triplet<T>
    ASSERT_EQ(triplet.x, scalar3.get_num_cells().x);
    ASSERT_EQ(triplet.y, scalar3.get_num_cells().y);
    ASSERT_EQ(triplet.z, scalar3.get_num_cells().z);
}

/// tests for correct initialization of row_cells member
TEST(field_scalar3, constructor_correct_row_cells)
{
    // construct Scalar3<T>
    const auto scalar3 = setup_scalar3<double>();

    // assert row_cells == NUM_Z
    ASSERT_EQ(scalar3.get_row_cells(), NUM_Z);
}

/*!
 * main field/scalar testing driver function
 * @param argc argument count
 * @param argv argument vector
 * @return RUN_ALL_TESTS() return value
 */
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
