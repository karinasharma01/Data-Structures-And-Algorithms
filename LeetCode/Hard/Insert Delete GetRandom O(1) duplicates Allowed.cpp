class RandomizedCollection {
    unordered_map<int,vector<int>> mp;//element,indices at which the element occurs in the vector nums
    vector<pair<int,int>> nums;//element and the index at which it occurs in mp[val]
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = (mp.find(val)==mp.end());
        int idx = nums.size();
        mp[val].push_back(idx);
        //insert the pair into the vector nums
        nums.push_back(make_pair(val,mp[val].size()-1));
        return flag;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        //remve the element from the multiset in O(1) using vector nums
        pair<int,int> last = nums.back();
        mp[last.first][last.second] = mp[val].back();
        nums[mp[val].back()] = last;
        mp[val].pop_back();
        if(mp[val].empty())
            mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int res = nums[rand()%nums.size()].first;
        return res;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
