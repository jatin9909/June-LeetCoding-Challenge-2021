#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxhorizontal = horizontalCuts[0];
        for(int i=1; i<horizontalCuts.size(); i++){
            maxhorizontal = max(maxhorizontal, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxhorizontal=max(maxhorizontal, h-horizontalCuts[horizontalCuts.size()-1]);
        
        int maxvertical = verticalCuts[0];
        for(int i=1; i<verticalCuts.size(); i++){
            maxvertical = max(maxvertical, verticalCuts[i]-verticalCuts[i-1]);
        }
        maxvertical=max(maxvertical, w-verticalCuts[verticalCuts.size()-1]);
        
        return (int) (((long)maxhorizontal *(long)maxvertical)%1000000007);
    }
};

int main(){
	int h,w;
	
	cout<<"Enter height and width "<<endl;
	cin>>h>>w;
	
	vector<int>horizontal; int hn;
	vector<int>vertical; int vn;
	int elements, elements1;
	cout<<"How many cuts in horizontal"<<endl;
	cin>>hn;
	cout<<"Enter the cuts in horizontal "<<endl;
	for(int i=0; i<hn; i++){
		cin>>elements;
		horizontal.push_back(elements);
	}
	
	cout<<"How many cuts in vertical"<<endl;
	cin>>vn;
	cout<<"Enter the cuts in vertical "<<endl;
	for(int i=0; i<vn; i++){
		cin>>elements1;
		vertical.push_back(elements1);
	}
	Solution ob;
	
	int ans = ob.maxArea(hn,vn,horizontal, vertical);
	cout<<"Maximum area "<<ans<<endl;
	return 0;
}
