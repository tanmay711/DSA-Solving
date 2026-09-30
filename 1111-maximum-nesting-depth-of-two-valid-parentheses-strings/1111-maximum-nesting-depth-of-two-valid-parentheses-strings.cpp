// I have two piles. Distribute the items so that the largest pile is as small as possible

// distribute every parenthesis into group 0 or 1 so that the deepest nesting depth of either group is as small as possible.

// alternating the nested loop is the soln
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth=0;
        for(char ch : seq)
        {
            if(ch == '(')
            {
                depth++;
                ans.push_back(depth%2);
            }
            else
            {
                ans.push_back(depth%2);
                depth--;
            }
        }
        return ans;
    }
};