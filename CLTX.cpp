#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;
//So du hien tai: 
//Cac che do:
//1. Choi tai xiu
//2. Choi chan le
//3. Nap tien
//4. Thoat Game
//Chon Che Do:
long long money=0;
bool oke;
void Mode1(){
	int dice1 = rand()%6+1;
	int dice2 = rand()%6+1;
	int dice3 = rand()%6+1;
	cout << "Nhap so tien cuoc: ";
	long long n; cin >> n;
	if(n>money) cout <<"Khong du tien cuoc, Vui long nap them tien vao tai khoan de tiep tuc." << endl;
	else{
		money -= n;
		
		cout << "Vui long chon cua cuoc: ";
		string s; cin >> s;
		for(int i=0;i<s.size();i++) s[i] = tolower(s[i]);
		
		cout <<"TUNG XUC XAC: "<< dice1 << " " << dice2 << " " << dice3 << endl;
		if(dice1 + dice2 + dice3 > 9 && s=="tai" || dice1 + dice2 + dice3 <= 9 && s=="xiu"){
			money += 2*n;
			cout << "Chuc mung ban da thang! So du tai khoan: " << money << endl; 
		}
		else{
			cout <<"So du tai khoan: " << money << endl;
		}
	}
}
void Mode2(){
	int dice1 = rand()%6+1;
	int dice2 = rand()%6+1;
	int dice3 = rand()%6+1;
	cout << "Nhap so tien cuoc: ";
	long long n; cin >> n;
	if(n>money) cout <<"Khong du tien cuoc, Vui long nap them tien vao tai khoan de tiep tuc.\n";
	else{
		money -= n;
		
		cout << "Vui long chon cua cuoc: ";
		string s; cin >> s;
		for(int i=0;i<s.size();i++) s[i] = tolower(s[i]);
		
		cout <<"TUNG XUC XAC: "<< dice1 << " " << dice2 << " " << dice3 << endl;
		if((dice1+dice2+dice3)%2==0 && s=="chan" || (dice1+dice2+dice3)%2==1 && s=="le"){
			money += 2*n;
			cout << "Chuc mung ban da thang! So du tai khoan: " << money << endl;
		}
		else{
			cout <<"So du tai khoan: " << money << endl;
		}
	}
}
void Mode3(){
	cout << "Nhap so tien muon nap: " ;
	long long n;
	cin >> n;
	money += n;
	cout <<"Chuc mung ban vua nap thanh cong " << n << " vao tai khoan" ;
	cout << "\nSo du tai khoan: " << money << endl;
}
void Mode4(){
	oke = 0;
	cout << "CO BAC\nNguoi khong choi la nguoi thang" << endl;
	cout << "Nguoi choi khong bao gio thang. " << endl;
	cout << "Xin cam on!" << endl;
}
int main(){
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "++    CHAO MUNG DEN VOI TAI XIU HUNGDZCLTX     ++" << endl;
	cout << "++   Vui long an mot nut bat ki de tiep tuc    ++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++ MENU +++++++" << endl;
	cout << "1. Choi Tai Xiu" << endl;
	cout << "2. Choi Chan Le" << endl;
	cout << "3. Nap Tien" << endl;
	cout << "4. Thoat Game" << endl;
	cout << "+++++++++++++++++++" << endl;
	oke = 1;
	while(oke){
		cout <<"CHON CHE DO: ";
		int x; cin >> x;
		if(x==1) Mode1();
		else if(x==2) Mode2();
		else if(x==3) Mode3();
		else if(x==4) Mode4();
	}
	return 0;
}
