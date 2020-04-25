#include <iostream>
#include <math.h>
using namespace std;

bool canPlace(int mat[][25], int n, int i, int j, int number){
    //Checks in row and column
    for (int x = 0; x < n; x++){
        if (mat[x][j] == number || mat[i][x]==number){
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (i/3)*rn; //sx is first x index of subgrid
    int sy = (j/rn)*rn;
    /// for (int x = sx; x < sx+rn; sx++){
    for (int x = sx; x < sx+rn; x++){
        for (int y = sy; y < sy+rn; y++){
            if (mat[x][y] == number){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][25], int n, int i, int j){
    //Base Case
    if (i==n){
        for (int p = 0; p < n; p++){
            for (int q = 0; q < n; q++){
                cout << mat[p][q] << " ";
            }
            cout << endl;
        }
        return true;
    }
    //Case Row end
    if (j==n){
        return solveSudoku(mat, n, i+1, 0);
    }
    //Skip Prefilled Rows
    if (mat[i][j] != 0){
        return solveSudoku(mat, n, i, j+1);
    }
    
    //Recursive Case
    //Fill the current cell with all possible options
    else{for (int number = 1; number <= n; number++){
        if (canPlace(mat, n, i, j, number)){
            //Assume number is placed on right spot
            mat[i][j] = number;
            
            //bool couldWeSolve = solveSudoku(mat, n, i, j+1);
            //if (couldWeSolve == true){
            if(solveSudoku(mat,n,i,j+1)){
                return true;
            }
        }
    }
        //Backtrack if number assumption is false
        mat[i][j] = 0;
        return false;
    }
}


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int mat[25][25];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    cout << endl;
    solveSudoku(mat, n, 0, 0);
    
    return 0;
}
