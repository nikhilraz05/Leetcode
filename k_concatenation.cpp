class Solution {
public:
    long mod=1e9+7;
    // int max(int a,int b)
    // {
    //     if(a>b)
    //     {
    //         return a;
    //     }
    //     return b;
    // }
    int kadane(vector<int>& arr)
    {
        long curr=arr[0];
        long f=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            curr=max(arr[i]%mod,(curr+arr[i])%mod);
            f=max(f%mod,curr%mod);
        }
        if(f<0)
        {
            return 0;
        }
        return f%mod;
    }
    int find1(vector<int>& arr)
    {
        long mx=INT_MIN;
        long curr=0;
        for(int i=0;i<arr.size();i++)
        {
            curr=curr+arr[i]%mod;
            mx=max(mx,curr);
        }
        return mx%mod;
    }
    int find2(vector<int>& arr)
    {
        long n=arr.size();
        long mx=INT_MIN;
        long curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr=curr+arr[i]%mod;
            mx=max(mx,curr);
        }
        return mx%mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) 
    {
        long x=kadane(arr);
        if(k==1)
        {
            return x;
        }
        long sum=0;
        for(auto it:arr)
        {
            sum+=it;
        }
        long pre=find1(arr);
        long suff=find2(arr);
        if(sum>0)
        {
            return max(long(k-2)*sum%mod+pre%mod+suff%mod,x%mod)%mod;
        }
        else
        {
            return max(x%mod,pre%mod+suff%mod)%mod;
        }
    }
};
