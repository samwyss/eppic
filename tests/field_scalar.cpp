#include <gtest/gtest.h>

#include "scalar.hpp"

// tests for successful Scalar3 constructor call with double as template parameter
TEST(field_scalar3, constructor_success_double)
{
    ASSERT_NO_THROW(Scalar3<double> test(3,3,3, 1.0));
}

// tests for successful Scalar3 constructor call with uint64_t as template parameter
TEST(field_scalar3, constructor_success_uint64_t)
{
    ASSERT_NO_THROW(Scalar3<uint64_t> test(3,3,3, 1));
}

// tests for cor

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}