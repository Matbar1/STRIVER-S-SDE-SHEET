

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int,int> _map;
        for(int i=0; i<nums.size(); i++)
        {
            int num=nums[i];
            int compliment=target-num;
            auto it=_map.find(compliment);
            if(it!=_map.end()){
                return {it->second,i};
            }
            _map[num]=i;
        }
        return{};
    }
};
       
     /*  for(int i=0; i<nums.size(); i++)
       {
           for(int j=i+1; j<nums.size(); j++)
           {
               if(nums[i]+nums[j]==target)
               {
                   return {i,j};
               }
           }
       }
       return {-1,-1};
    }
};*/
    