int minOperations(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
        int ans=0;
        for(auto it:mpp){
            if(it.second==1) return -1;
            else if(it.second%3==0){
                ans+=(it.second/3);
                //mpp[it.first]/=3;
            }
            else{
                ans+=(it.second/3)+1;
                //mpp[it.first]/=3;
            }
        }
        return ans; 
}
