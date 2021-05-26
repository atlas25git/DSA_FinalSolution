class Solution{
    public:
    vector<int> findOrder(int numCourses,vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> cnt(numCourses);
        for(vector<int> p: prerequisites)
            adj[p[1]].push_back(p[0]),cnt[p[0]]++;

            set<pair<int,int>> indeg_i;

            for(int i=0;i<numCourses;++i)
                indeg_i.insert({cnt[i],i});

            vector<int> ans;

            while(!indeg_i.empty())
            {
                auto p = *indeg_i.begin();
                if(p.first)
                {
                    ans.clear();
                    break;
                }
                ans.push_back(p.second);
                indeg_i.erase(p);

                for(int i: adj[p.second])
                    if(cnt[i])
                        indeg_i.erase({cnt[i],i}),
                        cnt[i]--,
                        indeg.insert({cnt[i],i});

            }
            return ans;
    }
}