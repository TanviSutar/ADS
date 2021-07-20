//matrix implementation of graph
#include<iostream>
#include<vector>
using namespace std;

void isPath(vector<vector<int>> mat, int n, int row, int col, int prow, int pcol, string ch,  string str, vector<string> &vec){
    if(row >= n or row < 0 or col >= n or col < 0) return;
    if(mat[row][col] == 0) return;
    if(row == n-1 and col == n-1){
        str += ch;
        vec.push_back(str);
        return;
    }
    cout<<str<<" "<<ch<<endl;
    if(row != prow or col+1 != pcol) isPath(mat, n, row, col+1, row, col, "R", str+ch, vec);
    if(row != prow or col-1 != pcol) isPath(mat, n, row, col-1, row, col, "L", str+ch, vec);
    if(row+1 != prow or col != pcol) isPath(mat, n, row+1, col, row, col, "D", str+ch, vec);
    if(row-1 != prow or col != pcol) isPath(mat, n, row-1, col, row, col, "U", str+ch, vec);
}

void findPath(vector<vector<int>> mat, int n, int row, int col, vector<vector<bool>> visited, string ch, string str, vector<string> &strvec){
    if(row < 0 or row >= n or col < 0 or col >= n) return;
    if(visited[row][col]) return;
    if(mat[row][col] == 0) return;
    visited[row][col] = true;
    if(row == n-1 and col == n-1){
        strvec.push_back(str+ch);
        return;
    }
    findPath(mat, n, row+1, col, visited, "D", str+ch, strvec);
    findPath(mat, n, row-1, col, visited, "U", str+ch, strvec);
    findPath(mat, n, row, col+1, visited, "R", str+ch, strvec);
    findPath(mat, n, row, col-1, visited, "L", str+ch, strvec);
    str.pop_back();
    visited[row][col] = false;
}

void find(int krow, int kcol, int trow, int tcol, int n, vector<vector<bool>> visited, int moves, int &minim){
    if(krow < 0 or krow >= n or kcol < 0 or kcol >= n) return;
    if(visited[krow][kcol]) return;
    if(krow == trow and kcol == tcol){
        minim = min(minim, moves+1);
        return;
    }
    visited[krow][kcol] = true;
    cout<<krow<<" "<<kcol<<endl;
    find(krow-2, kcol+1, trow, tcol, n, visited, moves+1, minim);
    find(krow-2, kcol-1, trow, tcol, n, visited, moves+1, minim);
    find(krow+2, kcol+1, trow, tcol, n, visited, moves+1, minim);
    find(krow+2, kcol-1, trow, tcol, n, visited, moves+1, minim);
    find(krow-1, kcol+2, trow, tcol, n, visited, moves+1, minim);
    find(krow-1, kcol-2, trow, tcol, n, visited, moves+1, minim);
    find(krow+1, kcol+2, trow, tcol, n, visited, moves+1, minim);
    find(krow+1, kcol-2, trow, tcol, n, visited, moves+1, minim);
    visited[krow][kcol] = false;
}

int minStepToReachTarget(vector<int> &knightpos,vector<int> &targetpos,int n)
{
    // Code here
    int minim = INT_MAX;
    vector<vector<bool>> visited(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            visited[i].push_back(false);
    }
    cout<<"here";
    find(knightpos[0]-1, knightpos[1]-1, targetpos[0]-1, targetpos[1]-1, n, visited, 0, minim);
}


int main(){
    int n, tmp; cin>>n;

    vector<vector<int>> mat(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tmp;
            mat[i].push_back(tmp);
        }
    }
    vector<string> strvec;
    vector<vector<bool>> visited(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i].push_back(false);
        }
    }
    findPath(mat, n, 0, 0, visited, "", "", strvec);

    for(auto a: strvec) cout<<a<<endl;

    return 0;
}