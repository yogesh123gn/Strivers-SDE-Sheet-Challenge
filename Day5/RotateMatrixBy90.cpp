/* Problem : rotate the Matrix in 90 degrees

Type I :
Input:  [1,2,3]
        [4,5,6]
        [7,8,9]
Output: [7,4,1]
        [8,5,2]
        [9,6,3]
        
Approach : Do transpose of given matrix and reverse each row to Get required result.

Time Complexity : O(N * N)
Space Complexity : O(1);
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if( i == j)
            {
                continue;
            }
            if (i != j) {
              swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
      for(int i = 0;i<n;i++)
        {
            reverse(&matrix[i][0],&matrix[i][n]);
        }
    }
};

/*
Type II :
Input:  [1,2,3]
        [4,5,6]
        [7,8,9]
Output: [4,1,2]
        [7,5,3]
        [8,9,6]
        
Approach : Use Four Pointer called left = 0,right = (rowSize -1),top = 0 and bottom = ColumnSize -1

Time Complexity: O(N)
Space Complexity: O(1)

*/

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)

{

    // Write your code here

     int i,j,left,right,top,bottom,k,temp;

     left=0;top=0;right=m-1;bottom=n-1;

     while(top<bottom&&left<right)

     {

         temp=mat[top][left];

         for(i=left+1;i<=right;i++)

         {

             k= mat[top][i];

             mat[top][i]=temp;

             temp=k;

         }

         top++;

         for(i=top;i<=bottom;i++)

         {

                k=mat[i][right];

                mat[i][right]=temp;

                temp=k;

 

         }

         right--;

         for(i=right;i>=left;i--)

         {

             k=mat[bottom][i];

             mat[bottom][i]=temp;

             temp=k;

         }

         bottom--;

         for(i=bottom;i>=top;i--)

         {

             k=mat[i][left];

             mat[i][left]=temp;

             temp=k;

         }

         left++;

         mat[top-1][left-1]=temp;

     }

}    
        


