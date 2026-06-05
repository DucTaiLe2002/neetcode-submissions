class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int max = -1000;
        int key_max = -1000;
        for(int i=0;i<k ;i++){
            for(const auto& pair : map){
                if(pair.second>max){
                    int check = 0;
                    for(int j =0;j<result.size();j++){
                        if(pair.first == result[j]){
                            check = 1;
                        }
                    }
                    if(!check){
                        max = pair.second;
                        key_max = pair.first;
                    }
                } 
            }
            result.push_back(key_max);
            max = -1000;
            key_max = -1000;
        }
        return result;
    }
};
