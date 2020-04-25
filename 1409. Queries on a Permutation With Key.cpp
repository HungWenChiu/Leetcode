class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        
        vector<int> result;
        vector<int> p(m, 0);
        
        for(int i = 0; i < p.size(); i++)
            p[i] = i + 1; //initialize
        
        for(int i = 0; i < queries.size(); i++)
            for(int j = 0; j < p.size(); j++)
            {
                if(queries[i] == p[j])
                {
                    result.push_back(j);
                    p.erase(p.begin() + j);
                    p.insert(p.begin(), queries[i]);
                    break;
                }
                   
            }   
        return result;
    }
};