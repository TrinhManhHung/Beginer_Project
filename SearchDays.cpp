#include<bits/stdc++.h>
using namespace std;
int MaNgay(int ngay){
	return ngay%7;
}
int MaThang(int thang){
	if(thang==9) return 0;
	if(thang==11) return 5;
	if(thang%2==0) return 12 - thang;
	if(thang%2==0) return 12 - thang - 4;
}
int MaNam(int nam){
	int du = nam%100;
	int Ma=du%7+du/4;
	return Ma;
}
int MaTK(int nam){
	int TK = nam/100;
	int Ma = (TK%4)*5;
	return Ma;
}
int Nhuan(int nam){
	if((nam%4==0 && nam%100!=0) || nam%400==0) return 1;
	return 0;
}
int MaSaiSo(int thang,int nam){
	if(thang > 2) return -2;
	if(thang <=2 && Nhuan(nam)) return -1;
	return 0; 
}
string Days(int thu){
	vector<string> v = {"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	return v[thu];
}
int main(){
	cout << "Nhap so ngay ban muon tra: ";
	int t; 
	cin >> t;
	while(t--){
		cout << "Nhap ngay, thang, nam (YC:nhap dung): ";
		int ngay,thang,nam;
		cin >> ngay >> thang >> nam;
		//	cout << MaNgay(ngay) << " " << MaThang(thang) << " " << MaTK(nam) << " " << MaNam(nam) << " " <<MaSaiSo(thang,nam) << endl; 
		int KetQua = MaNgay(ngay) + MaThang(thang) + MaTK(nam) + MaNam(nam) + MaSaiSo(thang,nam);
		int thu = KetQua%7;
		cout << Days(thu) << endl;
		}
	return 0; 
}
