// GFG POTD -> 11/07/2024
// Maximum Connected group
// Approach -> Take a cnt vector of vector and then count the number of components and store them in a vector called cnt and map mpp using BFS. Then using the check function and add the value as components.

class Solution {
  public:
    int solver(vector<vector<int>> &grid , vector<vector<int>> &cnt , int i , int j , int c){
        queue<pair<int,int>> q;
        q.push({i,j});
        cnt[i][j] = c;
        int val = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(y + 1 < grid.size() and grid[x][y+1] != 0 and !cnt[x][y+1]){
                q.push({x,y+1});
                cnt[x][y+1] = c;
                val++;
            }
            if(x + 1 < grid.size() and grid[x+1][y] != 0 and !cnt[x+1][y]){
                q.push({x+1,y});
                cnt[x+1][y] = c;
                val++;
            }
            if(y - 1 >= 0 and grid[x][y-1] != 0 and !cnt[x][y-1]){
                q.push({x,y-1});
                cnt[x][y-1] = c;
                val++;
            }
            if(x - 1 >= 0 and grid[x-1][y] != 0 and !cnt[x-1][y]){
                q.push({x-1,y});
                cnt[x-1][y] = c;
                val++;
            }
        }
        return val;
    }
    int check(int i , int j , unordered_map<int,int> &mpp , vector<vector<int>> &cnt){
        unordered_map<int,int> mp;
        if(i-1 >= 0 and cnt[i-1][j]) mp[cnt[i-1][j]] = 1;
        if(j-1 >= 0 and cnt[i][j-1]) mp[cnt[i][j-1]] = 1;
        if(j+1 < cnt.size() and cnt[i][j+1]) mp[cnt[i][j+1]] = 1;
        if(i+1 < cnt.size() and cnt[i+1][j]) mp[cnt[i+1][j]] = 1;
        int ans = 1;
        for(auto it : mp){
            ans += mpp[it.first];
        }
        return ans;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        vector<vector<int>> cnt(n , vector<int>(n,0));
        unordered_map<int,int> mpp;
        int ans = 0 , c = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] and cnt[i][j] == 0){
                    int val = solver(grid, cnt , i , j , c);
                    ans = max(ans , val);
                    mpp[c] = val;
                    c++;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(!grid[i][j]){
                    ans = max(ans , check(i , j , mpp , cnt));
                }
            }
        }
        return ans;
    }
};
