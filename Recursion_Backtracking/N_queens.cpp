#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& queens, int row, int col) {
    // Check row on the left
    for (int i = 0; i < col; i++) {
        if (queens[row][i] == 1) return false;
    }

    // Check upper left diagonal
    int i = row;
    int j = col;
    while(i >= 0 && j >= 0) {
        if (queens[i][j] == 1) return false;
        i--;
        j--;
    }

    // Check lower left diagonal
    i = row;
    j = col;
    while(i < queens.size() && j >= 0) {
        if (queens[i][j] == 1) return false;
        i++;
        j--;
    }

    return true;
}
void solve(vector<vector<int>>&queens,int col,int &count)
{
    if(col == queens.size())
    {
        count++;
        return;
    }

    for(int row = 0 ; row < queens.size() ; row++)
    {
        if(isSafe(queens,row,col))
        {
            queens[row][col] = 1;
            solve(queens,col+1,count);
            queens[row][col] = 0;
        }
    }
}
int main()
{
    vector<vector<int>>queens(4,vector<int>(4,0));
    int count = 0;
    solve(queens,0,count);
    cout<<count<<endl;
    return 0;
}