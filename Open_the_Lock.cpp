#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int openLock(vector<string>&deadends, string target){
			unordered_set<string>dead(deadends.begin(), deadends.end());
			unordered_set<string>visited;
			queue<string>q;
			q.push("0000");
			int length=0;
			
			while(!q.empty()){
				int n=q.size();
				for(int i=0; i<n; i++){
					string current = q.front();
					q.pop();
					
					if(current==target) return length;
					if(dead.count(current) || visited.count(current)) continue;
					
					visited.insert(current);
					findnode(current, q);
				}
				length++;
			}
			return -1;
		}
		
		void findnode(string s, queue<string>&q){
			for(int i=0; i<4; i++){
				char c=s[i];
				s[i]=(c-'0'+1)%10+'0';
				q.push(s);
				s[i]=(c-'0'-1+10)%10+'0';
				q.push(s);
				s[i]=c;
			}
		}
};

int main(){
	
	vector<string>deads;
	string target;
	int n; string element;
	cout<<"How many deadends ? "<<endl;
	cin>>n;
	cout<<"Enter the deadends "<<endl;
	for(int i=0; i<n; i++){
		cin>>element;
		deads.push_back(element);
	}
	cout<<"Enter the target "<<endl;
	cin>>target;
	Solution ob;
	
	int ans = ob.openLock(deads, target);
	cout<<"minimum total number of turns required to open the lock "<<ans;
	
	return 0;
}
