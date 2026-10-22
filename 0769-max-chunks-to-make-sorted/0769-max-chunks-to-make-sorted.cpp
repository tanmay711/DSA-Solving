class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxy=0;
        int chunks=0;
        for(int i=0;i<arr.size();i++)
        {
            maxy = max(maxy, arr[i]);
            if(maxy==i)
            {
                chunks++;
            }
        }
        return chunks;
    }
};