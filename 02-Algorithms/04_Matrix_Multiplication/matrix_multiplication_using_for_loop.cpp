#include <iostream>
#include <vector>

int main(void)
{
    std::vector<std::vector<int>> m1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> m2 = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> res_mat = {{5, 6}, {7, 8}};

    int n = m1[0].size();


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            res_mat[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                res_mat[i][j] += m1[i][k] * m2[k][j];
            }
            printf("res_mat[i][j] = %d\n", res_mat[i][j]);
        }
    }


    return 0;
}