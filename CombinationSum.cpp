class Solution {
public:
    void dfs(vector<int> const &candidates, int index, int prevSum, int target, vector<int>& path, vector<vector<int>>& result)
    {
        int sum = prevSum + candidates[index];
        path.push_back(candidates[index]);

        if (sum == target)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }
        else if (sum > target)
        {
            path.pop_back();
            return;
        }
        
        for (int i = index; i < candidates.size(); ++ i)
            dfs(candidates, i, sum, target, path, result);
        
        path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        
        vector<int> path;
        for (int index = 0; index < candidates.size(); ++index)
            dfs(candidates, index, 0, target, path, result);
        return result;
    }
};