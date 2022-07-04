//Approach 1 (Brute Force)

class Solution {
public:
    int setBit(int n)
    {
        int count = 0;
        while(n){
            
            if(n % 2 != 0)
                count += 1;
            if(n==1)
                break;
            n/=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0 ; i<=n ; i++){
            ans.push_back(setBit(i));
        }
        return ans;
    }
};


