class Solution {
public:
    Solution() 
    {
        m_G.resize(10);
        
        auto it = 'a';
        for (int i = 2; i <= 9; ++i)
        {
            m_G[i].push_back(it++);
            m_G[i].push_back(it++);
            m_G[i].push_back(it++);
            if (i == 7 || i == 9)
                m_G[i].push_back(it++);    
        }
    }
    
    void dfs(string const &digits, int index, string &path, vector<string>& res)
    {
        if (index == digits.size())
        {
            if (!path.empty())
                res.push_back(path);
            return;
        }
        
        
        int digit = digits[index] - '0';
        for (auto it = m_G[digit].begin(); it < m_G[digit].end(); ++it)
        {
            path.push_back(*it);
            dfs(digits, index + 1, path, res);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string path;
        dfs(digits, 0, path, res);
        
        return res;
    }
    
    vector<vector<char>> m_G;
};