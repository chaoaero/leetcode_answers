/*==================================================================
 *   Copyright (C) 2016 All rights reserved.
 *   
 *   filename:     number_of_islands.cc
 *   author:       Meng Weichao
 *   created:      2016/03/21
 *   description:  
 *
 ================================================================*/

#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;

void tranverse(int a, int b, int *tag, vector<vector<char> >& grid, int sol ) { 
    int dx[4] = {-1, 0, 1, 0}; 
    int dy[4] = {0, 1, 0, -1};
    int row = grid.size();
    int col = grid[0].size();
    for(int i = 0; i < 4; i++) {
        int dir_x = a + dx[i];
        int dir_y = a + dy[i];
        if(dir_x >= 0 && dir_x < row && dir_y >= 0 && dir_y < col && grid[dir_x][dir_y] == '1' && tag[dir_x * col + dir_y] == 0) {
            cout<<dir_x<<"\t"<<dir_y<<endl;
            tag[dir_x * col + dir_y] = sol;
            tranverse(dir_x, dir_y, tag, grid, sol);
        }  

    }   
}

int numIslands(vector<vector<char> >& grid) {
    if(grid.size() == 0)
        return 0;
    int row = grid.size();
    int col = grid[0].size();
    int *tag;
    tag = (int *)malloc(row * col * sizeof(int));
    for(int i = 0; i< row; i++) 
        for(int j = 0; j< col ; j++)
            tag[i * col + j ] = 0;
    int sol = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(grid[i][j] == '1' && tag[i * col + j] == 0) {
                sol++;  
                tag[i * col + j] = sol;
                tranverse(i, j, tag, grid, sol);
            }   
        }   
    }  

    return sol;
}

int main() {

    vector<vector<char> > grid;
    for(int i = 0; i < 1; i++) {
        vector<char> tt;
        for(int j = 0; j < 2; j++)
            tt.push_back('1');
        grid.push_back(tt);
    }
    cout<<grid.size()<<"\t"<<grid[0].size()<<endl;
    cout<<numIslands(grid)<<endl;
    return 0;

}
