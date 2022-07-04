//Approach 1 (Brute Force)
//O(nlogn)

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

//EFFICIENT APRROACH
//O(N)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        v.push_back(0);
        if(n==0)
            return v;
        v.push_back(1);
        
        for(int i=2 ; i<=n ; i++)
        {
            if(i%2)
                v.push_back(v[i/2] +1);
            else
                v.push_back(v[i/2]);
        }
        return v;
    }
};


