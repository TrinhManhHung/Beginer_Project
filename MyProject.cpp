#include<bits/stdc++.h>
using namespace std;

class TaiKhoan{
	private:
		string name, birth, tk, mk;
		long long money;
	public:
		friend void TaoTK();
		friend void DangNhap();
		friend void NapTien();
		friend void RutTien();
		friend void ChuyenTien();
		friend void KTSoDu();
};

map<string,TaiKhoan> DsTK;

//1.Tao tai khoan 
void TaoTK(){
	system("color 6");
	TaiKhoan a;
	cout <<"Nhap ho ten: ";
	scanf("\n"); getline(cin,a.name);
	cout <<"Nhap tuoi: ";
	cin >> a.birth;
	cout <<"Nhap tai khoan (khong co dau cach): ";
	cin >> a.tk;
	while(DsTK.count(a.tk) != 0){
		cout << "Tai khoan da ton tai. Vui long nhap lai." << endl;
		cout <<"Nhap tai khoan (khong co dau cach): ";
		cin >> a.tk;
	}
	cout <<"Nhap mat khau (khong co dau cach): ";
	cin >> a.mk;
	a.money = 0;
	DsTK[a.tk] = a;
	cout << "\nChuc mung ban " <<a.name <<" da lap tai khoan thanh cong" << endl;
	cout << "Tai khoan: " << a.tk <<"\nMat khau: " << a.mk <<"\nSo du: " << a.money << endl;
}

//2.Dang nhap
void DangNhap(){
	system("color A");
	string Tk, Mk;
	cout << "Nhap tai khoan: ";
	cin >> Tk;
	cout << "Nhap mat khau: ";
	cin >> Mk;
	if(DsTK[Tk].mk == Mk){
		cout << "\nChuc mung ban da dang nhap thanh cong" << endl;
		cout << "Tai khoan: " << Tk << endl;
		cout << "So du: " << DsTK[Tk].money << endl;
	}
	else{
		cout << "\nNhap sai. Vui long thu lai." << endl;
	}
}

vector<pair<string,string>> LSu;

//3.Nap tien 
void NapTien(){
	system("color D");
	string Tk;
	cout << "Nhap tai khoan: ";
	cin >> Tk;
	if(DsTK.count(Tk) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	else{
		long long m;
		cout << "Nhap so tien muon nap: ";
		cin >> m;
		DsTK[Tk].money += m;
		cout <<"\nChuc mung ban da nap thanh cong: " << m << endl;
		cout << "So du hien tai: " << DsTK[Tk].money << endl;
		
		string tien = "bien dong so du: +" + to_string(m) + ".Hinh thuc: Nap tien";
		LSu.push_back({Tk, tien});
	}
	
}

//4. Rut tien
void RutTien(){
	system("color 4");
	string Tk;
	cout << "Nhap tai khoan: ";
	cin >> Tk;
	if(DsTK.count(Tk) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	else{
		long long m;
		cout << "Nhap so tien muon rut: ";
		cin >> m;
		if(m > DsTK[Tk].money){
			cout << "\nTai khoan quy khach khong du tien.\n";
		}
		else{
			DsTK[Tk].money -= m;
			cout << "Rut tien thanh cong: -" << m << "\n"; 
			cout << "So du hien tai: " << DsTK[Tk].money << endl;
			string tien = "bien dong so du: -" + to_string(m) + ".Hinh thuc: Rut tien";
			LSu.push_back({Tk, tien});
		}
	}
}

//5. Chuyen tien
void ChuyenTien(){
	system("color 3");
	string Tk1;
	cout << "Nhap tai khoan: ";
	cin >> Tk1;
	if(DsTK.count(Tk1) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	string Tk2;
	cout << "Tai khoan thu huong: ";
	cin >> Tk2;
	if(DsTK.count(Tk2) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	else{
		long long m;
		cout << "Nhap so tien muon chuyen: ";
		cin >> m;
		if(m > DsTK[Tk1].money){
			cout << "\nTai khoan quy khach khong du tien.\n";
		}
		else{
			DsTK[Tk1].money -= m;
			DsTK[Tk2].money += m;
			cout << "Chuyen tien thanh cong: -" << m <<" den " << Tk2 <<"\n"; 
			cout << "So du hien tai: " << DsTK[Tk1].money << endl;
			string tien1 = "bien dong so du: -" + to_string(m) + ".Hinh thuc: Chuyen tien den " + Tk2 + ".";
			LSu.push_back({Tk1, tien1});
			string tien2 = "bien dong so du: +" + to_string(m) + ".Hinh thuc: " + Tk1 + " chuyen tien.";
			LSu.push_back({Tk2, tien2});
		}
	}
	
}

//6.Kiem tra so du
void KTSoDu(){
	system("color C");
	string Tk;
	cout << "Nhap tai khoan: ";
	cin >> Tk;
	if(DsTK.count(Tk) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	else{
		cout << "\nSo du kha dung: " << DsTK[Tk].money << endl;
	}
}
//7.Lich su giao dich 
void History(){
	system("color F");
	string Tk;
	cout << "Nhap tai khoan: ";
	cin >> Tk;
	if(DsTK.count(Tk) == 0){
		cout <<"\nTai khoan khong ton tai." << endl;
	}
	else{
		bool oke = false;
		for(int i=LSu.size()-1;i>=0;i--){
			if(LSu[i].first == Tk){
				cout << Tk << " " << LSu[i].second << endl;
				oke = true;
			}
		}
		if(!oke) cout << "\nKhong co giao dich nao.\n";
	}
}
int main(){
	TaiKhoan a;
	while(1){
		cout << "____________________________________________" << endl;
		cout << "__         *Chon 1 chuc nang bat ki*      __" << endl;
		cout << "__   1.Tao tai khoan                      __" << endl;
		cout << "__   2.Dang nhap                          __" << endl;
		cout << "__   3.Nap tien                           __" << endl;
		cout << "__   4.Rut tien                           __" << endl;
		cout << "__   5.Chuyen tien                        __" << endl;
		cout << "__   6.Kiem tra so du                     __" << endl;
		cout << "__   7.Lich su giao dich                  __" << endl;
		cout << "__   8.Thoat                              __" << endl;
		cout << "____________________________________________" << endl;
		string tmp; cin >> tmp;
		if(tmp == "1"){
			TaoTK();
		}
		else if(tmp == "2"){
			DangNhap();
		}
		else if(tmp == "3"){
			NapTien();
		}
		else if(tmp == "4"){
			RutTien();
		}
		else if(tmp == "5"){
			ChuyenTien();
		}
		else if(tmp == "6"){
			KTSoDu();
		}
		else if(tmp == "7"){
			History();
		}
		else if(tmp == "8"){
			cout << "Good bye. See you again.";
			break;
		}
		else {
			cout << "\nNhap sai. Vui long nhap lai.\n";
		}
	}
	return 0;
}
