#include<bits/stdc++.h>
using namespace std;
int main(){
	int cnt = 0;
	for(int i=0;i<=120;i++){
		if(i%2==0 || i%3==0 || i%6==0) ++ cnt;
	}
	cout << cnt;
	return 0;
}
