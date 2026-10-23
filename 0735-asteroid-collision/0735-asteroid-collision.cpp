// if we use stack then we would have to reverse the element in it, so instead we will use list...

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> ls;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
            {
                ls.push_back(asteroids[i]);
            }
            else
            {
                while(!ls.empty() && ls.back()<abs(asteroids[i]) && ls.back() >0) // if the encounred no is negative and create than last element in list
                {
                    ls.pop_back();
                }
                if(!ls.empty() && ls.back()==abs(asteroids[i]))
                {
                    ls.pop_back();
                }

                else if(ls.empty() || ls.back()<0)
                {
                    ls.push_back(asteroids[i]);
                }
            }
        }
        return vector<int>(ls.begin(),ls.end());
    }
};