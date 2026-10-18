class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int r=0;
        int c=0;
        visited[0][0] = true;
        while(1)
        {
            int nr = r;
            int nc = c;
            char ch = grid[nr][nc];
            if(ch == 'L') nc--;
            else if(ch =='R')nc++;
            else if(ch == 'D') nr++;
            else nr--;

            if(nr <0 || nr>=m || nc <0 || nc>=n || visited[nr][nc])
            {
                break;
            }
            visited[nr][nc] = true;
            r = nr;
            c = nc;
        }
        return {r,c};
    }
};