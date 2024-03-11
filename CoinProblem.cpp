#include<bits/stdc++.h>
using namespace std;
//Ngan hang xyz hien co N to tien co menh gia khac nhau duoc 
//luu vao mang C[], ban hay tim cach doi so tien la S sao cho
//so to tien can dung la it nhat. Ban duoc su dung mot menh gia
//khong gion han
//Input: Dong dau tien chua 2 so N va S, dong thu 2 chua N so la 
//menh gia cac to tien
//1 <= N <= 100; 1 <= S <= 10^6; 1 <= C[i] <= 10^6;
//Output: In ra so to tien nho nhat can doi. Neu khong the doi 
//in ra -1
long long F[1000005]; //F[i] luu so tien it nhat de tao thanh menh gia i
int main(){
	int n, s; cin >> n >> s;
	int c[n];
	for(auto &x : c) cin >> x;
	F[0] = 0;
	for(int i=1; i<=s; i++){
		F[i] = 1e9;
		for(int j=0; j<n; j++){
			if(i >= c[j]){
				F[i] = min(F[i], F[i - c[j]] + 1);
			}
		}
	}
	cout << F[s] << endl;
	return 0;
}
