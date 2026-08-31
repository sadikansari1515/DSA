class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int Max = -1;
        for(int i=arr.size()-1; i>=0; i--) {
            int temp = arr[i];
            arr[i] = Max;
            Max = max(temp, Max);
        }
        return arr;
    }
};