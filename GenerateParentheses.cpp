class Solution {
public:
    string generateFirst(int n)
    {
        string res(n, '(');
        res.append(n, ')');
        return res;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string it = generateFirst(n);
        bool bValid = true;
        while (bValid)
        {
            result.push_back(it);
            
            int count = 0;
            int close = 0;
            int i = 2 * n - 1;
            for (; i >= 0; --i)
            {
                if (it[i] == '(')
                {
                    --count;
                }
                else
                {
                    ++count;
                    ++close;
                }
                
                if (it[i] == '(' && count > 0)
                {
                    it[i] = ')';
                    --close;   
                        
                    for (int j = 2 * n - 1; j >= 2 * n - close; --j)
                        it[j] = ')';
                        
                    for (int j = 2 * n - close - 1; j > i; --j)
                        it[j] = '(';
                                        
                    break;
                }
            }
            if (i == -1)
                bValid = false;
        }
        
        return result;
        
    }
};