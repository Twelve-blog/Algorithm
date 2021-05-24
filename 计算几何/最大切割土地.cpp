#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
void solve(){
	char s[300];
	cin >> s;
	stack<char> q;
	int len = strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]!='(' && s[i] != ')') continue;
		if(q.empty()){
			if(s[i] == '('){
				q.push('(');
			}else{
				cout <<"NO" << endl;
				return;
			}
		}
		else{
			if(s[i] == '('){
				q.push('(');
			}
			else{
				q.pop();
			}
		}
	}
	if(q.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	solve();
}
