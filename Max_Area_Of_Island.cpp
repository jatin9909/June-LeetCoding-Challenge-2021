#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int maxsize=0;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j])
                    maxsize=max(maxsize,area(i,j,grid));
            }
        }
        return maxsize;
    }
    
    int area(int rows, int cols, vector<vector<int>>& grid){
        if(rows<0 || cols<0 || rows>=grid.size()||cols>=grid[0].size()||grid[rows][cols]==0)
            return 0;
        
        grid[rows][cols]=0;
        
        return (1+area(rows+1, cols, grid)+area(rows-1,cols,grid)+area(rows,cols+1,grid)+area(rows,cols-1,grid));
    }
};

int main()
{
    int in;
    int temp; int col;
        vector<vector<int>> d;
        cout<<"Enter number of row "<<endl;
        cin>>in;
        cout<<"Enter number of column "<<endl;
    	cin>>col;
        for(int i=0; i<in; i++){ 
    		cout<<"row"<<i+1<<":"<<' ';
    		vector<int> row;
    		for(int j=0; j<col; j++){
      			cin>>temp;
      			row.push_back(temp);
    		}
    	d.push_back(row);
		}
        cout<<endl;
        
        Solution ob; 
		int ans = ob.maxAreaOfIsland(d);
    	
    	cout<<"Maximum area of island "<<ans<<endl;
    	
    return 0;
} 
