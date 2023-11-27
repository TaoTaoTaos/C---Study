#include <stdio.h>

// 题目要求：创建一个稀疏矩阵，然后用三元组存储他，然后包含一个转置函数

// 思路：首先，我们需要创建一个稀疏矩阵。然后，我们将使用三元组（行，列，值）来存储非零元素。最后，我们将实现一个转置函数，该函数将行和列互换，从而实现矩阵的转置。

// 定义三元组结构体
typedef struct
{
    int row; // 行
    int col; // 列
    int val; // 值

} Triplet;

// 创建稀疏矩阵
void createSparseMatrix(Triplet matrix[], int m, int n, int num)
{
    // 初始化矩阵的行数、列数和非零元素个数
    matrix[0].row = m;
    matrix[0].col = n;
    matrix[0].val = num;
}

// 转置稀疏矩阵
void transpose_SparseMatrix(Triplet matrix[], Triplet transposedMatrix[])
{
    // 初始化转置矩阵的行数、列数和非零元素个数
    transposedMatrix[0].row = matrix[0].col;
    transposedMatrix[0].col = matrix[0].row;
    transposedMatrix[0].val = matrix[0].val;

    // 转置矩阵
    int k = 1;
    for (int i = 0; i < matrix[0].col; i++)
    {
        for (int j = 1; j <= matrix[0].val; j++)
        {
            if (matrix[j].col == i)
            {
                transposedMatrix[k].row = matrix[j].col;
                transposedMatrix[k].col = matrix[j].row;
                transposedMatrix[k].val = matrix[j].val;
                k++;
            }
        }
    }
}

int main()
{
    // 创建稀疏矩阵
    Triplet matrix[100];
    createSparseMatrix(matrix, 5, 5, 3);
    matrix[1] = (Triplet){0, 0, 1};
    matrix[2] = (Triplet){1, 1, 2};
    matrix[3] = (Triplet){2, 2, 3};

    // 转置稀疏矩阵
    Triplet transposedMatrix[100];
    transposeSparseMatrix(matrix, transposedMatrix);

    return 0;
}

// 总结：本题主要考察了稀疏矩阵的存储和转置。稀疏矩阵是一种大部分元素为零的矩阵，可以使用三元组（行，列，值）的方式进行存储，从而节省空间。转置则是将矩阵的行和列互换，可以通过遍历原矩阵，将每个元素的行和列互换来实现。
// 关键注释：
// 1. 创建稀疏矩阵：我们首先需要创建一个稀疏矩阵。这可以通过定义一个三元组数组来实现，其中每个三元组表示一个非零元素的行、列和值。
// 2. 转置稀疏矩阵：转置是将矩阵的行和列互换。我们可以通过遍历原矩阵，将每个元素的行和列互换来实现。这需要我们创建一个新的三元组数组来存储转置后的矩阵。
