// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        
        
        
        int  n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> > q;
        
        int freshOrange = 0;
        int minTime = 0;
        
        for(int i = 0; i< n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                
                if(grid[i][j] == 1){
                    freshOrange++;
                }
            }
        }
        
        while(!q.empty()){
            int currentSize = q.size();
            
            
            for(int i = 0; i< currentSize;i++){
                pair<int,int> p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                
                if(x > 0 and grid[x-1][y] ==1){
                    freshOrange--;
                    grid[x-1][y] =2;
                    q.push({x-1,y});
                    
                    
                }
                if(y > 0 and grid[x][y-1] ==1){
                    freshOrange--;
                    grid[x][y-1] =2;
                    q.push({x,y-1});
                    
                    
                }
                
                
                if(x < n - 1 && grid[x + 1][y] == 1) {
                    freshOrange--;
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                }
                
                if(y < m - 1 && grid[x][y+1] == 1) {
                    freshOrange--;
                    grid[x][y+1] = 2;
                    q.push({x, y+1});
                }
                
                
                
                
                
            }
            
           if(!q.empty()){ minTime++;}
            
            
        }
        
        
        
        
        
        return freshOrange == 0 ? minTime : -1;
        
        
        
        
        
        
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
