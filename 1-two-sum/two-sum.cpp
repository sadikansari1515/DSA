class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target){
        vector<int> ans;
        int n = arr.size(); 
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(target-arr[i]==arr[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
                
            }
        } 
        return ans;      
    }
};