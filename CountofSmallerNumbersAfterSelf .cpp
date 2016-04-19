class Solution {
public:
    struct FTree
    {
    private:    
        vector<int> data;
        int maxVal;
    
    public:
        
        FTree(int n)
            : data(n + 1, 0)
            , maxVal(n)
        {
            
        }
        
        int get(int id)
        {
            int sum = 0;
            while (id > 0)
            {
                sum += data[id];
                id -= (-id & id);
            }
            
            return sum;
        }
        
        void Inc(int id)
        {
            while (id <= maxVal)
            {
                ++data[id];
                id += (-id & id);
            }
        }
    };

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        result.resize(nums.size());
        FTree f(nums.size());
        
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int index = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            index++;
            result[i] = f.get(index);
            f.Inc(index + 1);
        }
        
        return result;
    }
};