#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int>(static_cast<size_t>(TVector<int>::max_size + 1ull)));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> a(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    TMatrix<int> b(a);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> a(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    TMatrix<int> b(a);
    EXPECT_NE(&a[0], &b[0]);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> a(5);
    EXPECT_EQ(5, a.getSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> a(5);
    ASSERT_NO_THROW(a[2][2] = 5);
    EXPECT_EQ(5, a[2][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[-5][-2] = 2);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> a(5);
    ASSERT_ANY_THROW(a[15][10] = 2);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> a(5);
    ASSERT_NO_THROW(a = a);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> a(5), b(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    ASSERT_NO_THROW(a = b);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> a(5), b(3);
    b = a;
    EXPECT_EQ(a.getSize(), b.getSize());
    EXPECT_EQ(a.getSize(), 5);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> a(5), b(3);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    ASSERT_NO_THROW(a = b);
    EXPECT_EQ(a, b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> a(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    TMatrix<int> b(a);
    EXPECT_TRUE(a == b);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> a(5);
    for (int i = 0; i < 5; i++)
        for (int j = i; j < 5; j++)
            a[i][j] = i * 10 + j;
    EXPECT_TRUE(a == a);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> a(5), b(10);
    EXPECT_TRUE(a != b);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> a(5), b(5);

    a[2][2] = 5;
    b[2][2] = 50;

    ASSERT_NO_THROW(a + b);

    EXPECT_EQ((a + b)[2][2], 55);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> a(5), b(10);
    ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> a(5), b(5);

    a[2][2] = 5;
    b[2][2] = 50;

    ASSERT_NO_THROW(a - b);

    EXPECT_EQ((a - b)[2][2], -45);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> a(5), b(10);
    ASSERT_ANY_THROW(a - b);
}
