#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dp;
    bool check(string a, string b, string c, int i, int j, int k){
        int na = a.size();
        int nb = b.size();
        int nc = c.size();
        
        if(i==na && j==nb && k==nc){
            return true;
        }
        else if(k==nc){
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        bool res=false;
        if(i<na && a[i]==c[k]){
            res=res||check(a,b,c,i+1,j,k+1);
        }
        
        if(j<nb && b[j]==c[k]){
            res=res||check(a,b,c,i,j+1,k+1);
        }
        
        return dp[i][j]=res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int na = s1.size();
        int nb = s2.size();
        int nc = s3.size();
        dp.assign(na+1, vector<int>(nb+1, -1));
        return check(s1,s2,s3,0,0,0);
    }
};

int main()
{
    	cout<<"Enter the string 1 "<<endl;
    	string s1;
    	cin>>s1;
    	
    	cout<<"Enter the string 2 "<<endl;
    	string s2;
    	cin>>s2;
    	
    	cout<<"Enter the string 3 "<<endl;
    	string s3;
    	cin>>s3;
        
        Solution ob; 
		bool ans = ob.isInterleave(s1,s2,s3);
    	
    	cout<<ans<<endl;
    	
    return 0;
} 
