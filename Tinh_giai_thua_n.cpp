#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
		cout << "Nhap so test case: ";
		int t; cin >> t;
		while(t--){
		cout << "Nhap n: ";
		int n; cin >> n;
		int a[50000];
		memset(a,0,sizeof(a));
		int q,r = 0;
		a[0]=1;
		int m = 1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<m;j++){
				q = r;
				r = (a[j]*i + r)/10;
				a[j] = (a[j]*i+q)%10;
			}
			while(r>0){
	          a[m]=r%10;
	          m++;
	          r=r/10;
			}
		}
		cout << "n! = ";
		for(int i=m-1;i>=0;i--){
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
