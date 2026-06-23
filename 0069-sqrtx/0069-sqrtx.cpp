class Solution {
public:
    long long int mySqrt(int x) {
        int s=0;
        int e=x;
        int mid=s+(e-s)/2;

        long long int ans=-1;
        while(s<=e){
            long long int sq=(long long)mid*mid;
            if(sq==x){
               return mid;
            }
            if(sq<x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;

        }
        return ans;
    }
};