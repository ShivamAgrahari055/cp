
#generate all permutations
class Solution {
public:

   vector<vector<int>> ans ;
   vector<int> temp ;

   void help(vector<int> &nums,vector<int> &used){



    if(temp.size() == nums.size()){
        ans.push_back(temp);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]) continue ;

        used[i]= 1 ;

        temp.push_back(nums[i]) ;

        help(nums,used);

        temp.pop_back();
        used[i] = 0 ;
    }

   }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(),0);

        help(nums,used);
        return ans ;
        
    }
};