//DE BAI: Tren ban co kich thuoc nxn hay dat n quan hau. Moi quan tren mot hang sao cho khong co quan nao an duoc nhau

#include<bits/stdc++.h>
using namespace std;
int n; int a[100];
bool cheo1[100];
bool cheo2[100];
bool cot[100];
void display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==j) cout <<"O";
			else cout <<"*";
		}
		cout <<endl;
	}
	cout << endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(cheo1[i+j-1] && cheo2[i-j+n] && cot[j]){
			a[i]=j;
			cheo1[i+j-1]=false;
			cheo2[i-j+n]=false;
			cot[j]=false;
			if(i==n) display();
			else Try(i+1);
			cheo1[i+j-1]=true;
			cheo2[i-j+n]=true;
			cot[j]=true;
		}
	}
}
int main(){
	memset(cheo1,true,sizeof(cheo1));
	memset(cheo2,true,sizeof(cheo2));
	memset(cot,true,sizeof(cot));
	cout << "Nhap kich thuoc ban co: ";
	cin >> n;
	Try(1);
	return 0;
}
