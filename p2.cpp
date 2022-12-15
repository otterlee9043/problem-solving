#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[100][100];
int t, n, m, k;
int answer = 0;

int simulate(int matrix[][100], int depth, int max_value)
{
    for (int dir = 0; dir < 4; dir++)
        {
            int copied[100][100];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    copied[i][j] = matrix[i][j];
                }
            }

            switch (dir)
            {
            case 0:
                for (int i = 0; i < n; i++)
                {
                    for (int j = m-1; j >= 0; j--)
                    {
                        if (copied[i][j] != 0) { // 바람을 제일 먼저 맞는 구역
                            if (j == 0) continue;
                            copied[i][j-1] = copied[i][j-1] == 0? copied[i][j] : copied[i][j] + copied[i][j-1];
                            copied[i][j] = 0;
                            break;
                        }
                    }
                }
                break;
            case 1:
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (copied[i][j] != 0) { // 바람을 제일 먼저 맞는 구역
                            if (j == m-1) continue;
                            copied[i][j+1] = copied[i][j+1] == 0? copied[i][j] : copied[i][j] + copied[i][j+1];
                            copied[i][j] = 0;
                            break;
                        }
                    }
                }
                break;
            case 2:
                for (int j = 0; j < m; j++)
                {
                    for (int i = n-1; i >= 0; i--){
                        if (copied[i][j] != 0) { // 바람을 제일 먼저 맞는 구역
                            if (i == 0) continue;
                            copied[i-1][j] = copied[i-1][j] == 0? copied[i][j] : copied[i][j] + copied[i-1][j];
                            copied[i][j] = 0;
                            break;
                        }
                    }
                    
                }
                break;
            case 3:
                for (int j = 0; j < m; j++)
                {
                    for (int i = 0; i < n; i++){
                        if (copied[i][j] != 0) { // 바람을 제일 먼저 맞는 구역
                            if (i == n-1) continue;
                            copied[i+1][j] = copied[i+1][j] == 0? copied[i][j] : copied[i][j] + copied[i+1][j];
                            copied[i][j] = 0;
                            break;
                        }
                    }
                    
                }
                break;
            }


            for (int q = 0; q < n; q++)
            {
                for (int w = 0; w < m; w++)
                {

                    cout << copied[q][w] << " ";
                }
                cout << endl;
            }
            cout << "-----------------------------" << endl;
            // print_matrix();
            // init_matrix();
        }

}

void print_matrix()
{
    for (int j = 0; j < n; j++)
    {
        for (int u = 0; u < m; u++)
        {

            cout << matrix[j][u] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}

void init_matrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void copy_matrix(int **new_matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            new_matrix[i][j] = matrix[i][j];
        }
    }
}

int main()
{
    // memset(matrix, 0, sizeof(matrix));
    int num;
    cin >> t;
    for (int index = 0; index < t; index++)
    {
        // 행렬 생성
        cin >> n >> m >> k;
        cout << "n: " << n << " m: " << m << " k: " << k << endl;
        for (int j = 0; j < n; j++)
        {
            for (int u = 0; u < m; u++)
            {
                cin >> num;
                matrix[j][u] = num;
            }
        }

        cout << simulate(matrix, k, 0);
        init_matrix();
    }


    return 0;
}