/* Brute Force Approach Solution 
traverse the matrix to find Non-zero numbers -> O(N*M)
set the row and column to -1 -> O(N+M)
traverse through the matrix to set elements to zero -> O(N*M) 
 
 Time Complexity : O((N*M)*(N + M)) + O(N*M) where N= No.of rows, M=No.    of   Columns

 Space Complexity : O(1)

Note: this solution works only when matrix does not contain any negative numbers.
 */

class Solution {
public:
    
    //mark the non-zero values of i-th row to -1 
    void markRow(vector<vector<int>> &matrix,int n,int m,int i)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }
     
    //mark the non-zero values of j-th column to -1  
    void markColumn(vector<vector<int>> &matrix,int n,int m,int j)
    {
        for(int i=0;i<n;i++)
        {
            if(matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    markRow(matrix,n,m,i);
                    markColumn(matrix,n,m,j);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};




/* Better Approach Solution 
traverse the matrix to find Non-zero numbers -> O(N*M)

traverse through the matrix to set elements to zero -> O(N*M) 
 
 Time Complexity :  O(N*M) where N= No.of rows, M=No.    of   Columns

 Space Complexity : O(N)+O(M)
 O(N) -> row array
 O(M) -> column array

 */

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int row[n];
        int column[m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                   row[i] = 1;
                   column[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==1 || column[j]==1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};





/* Optimal solution by using hashmap inside of matrix to reduce space complexity  
Used first row and first column of matrix as hashmap
Time Complexity : O(n * m), where n = no.of rows and m = no. of columns
Space Complexity : O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int col0 = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;

                    if(j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                    {
                        col0 = 0;
                    }
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j] != 0)
                {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};