class RandomizedSet {
    unordered_map<int,int> mp;//element,index as key value pair
    vector<int> nums;//for access in O(1)
public:
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //if the element already exists in the map,return false
        if(mp.find(val)!=mp.end())
            return false;
        //otherwise insert it in the vector & store it in the map as well
        nums.push_back(val);
        int idx = nums.size()-1;
        mp[val] = idx;
        return true;
    }
    
    bool remove(int val) {
        //if the element is not present in the map,return false
        if(mp.find(val)==mp.end())
            return false;
        //else remove it from the set in O(1) using vector
        /*
        In case of a vector the element at the last index or last inserted in the vector can be removed in O(1) time. So in order to remove the element val from the Randomized set in O(1) time we can swap it with element at last in O(1) time and then remove it & make the necessary update in the hashmap as well
        */
        int last = nums.back();
        //the element at the end would now be placed at the position where val was originally stored in nums
        mp[last] = mp[val];
        //mp[val] is the index where val was stored in the vector nums,now last element would be placed there
        nums[mp[val]] = last;
        nums.pop_back();
        //remove element from map
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int res = nums[rand() % nums.size()];
        return res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
