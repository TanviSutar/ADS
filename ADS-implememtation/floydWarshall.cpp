#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &matrix){
    int m = matrix.size();

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1) matrix[i][j] = INT_MAX;
        }
    }

    for(int k=0; k<m; k++){
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][k] != INT_MAX and matrix[k][j] != INT_MAX and matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == INT_MAX) matrix[i][j] = -1;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp;
            cin>>tmp;
            matrix[i].push_back(tmp);
        }
    }
    floydWarshall(matrix);
    cout<<"Output:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
i/p:
3
0 1 43
1 0 6
-1 -1 0

o/p:
0 1 7 
1 0 6 
-1 -1 0 
*/