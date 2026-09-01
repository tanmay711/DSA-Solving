class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int water = capacity;
        int step =0;
        for(int i=0;i<n;i++)
        {
            if(plants[i]<=water)
            {
                water = water - plants[i];
                step++;
            }
            else
            {
                step += 2*i;
                water = capacity;

                water = water - plants[i];
                step++;

            }
        }
        return step;
    }
};