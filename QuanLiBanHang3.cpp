#include<bits/stdc++.h>
using namespace std;
class KhachHang; class MatHang;

map<string, KhachHang> KH;
map<string, MatHang> MH;
class KhachHang{
	private:
		static int cnt1;
	public:
		string ma, ten, sex, ngaysinh, diachi;
		friend istream& operator >> (istream &in, KhachHang &a){
			a.cnt1++;
			a.ma = "KH" + string(3-to_string(a.cnt1).size(),'0') + to_string(a.cnt1);
			getline(in,a.ten);
			getline(in,a.sex);
			getline(in,a.ngaysinh);
			getline(in,a.diachi);
			KH[a.ma] = a;
			return in;
		}	
};
int KhachHang::cnt1 = 0;

class MatHang{
	private:
		static int cnt2;
	public:
		string ma, ten, donvi, sell, buy;
		long long mua, ban;
		friend istream& operator >> (istream &in, MatHang &a){
			a.cnt2++;
			a.ma = "MH" + string(3-to_string(a.cnt2).size(),'0') + to_string(a.cnt2);
			getline(in,a.ten);
			getline(in,a.donvi);
			getline(in,a.buy); a.mua = stoll(a.buy);
			getline(in,a.sell); a.ban = stoll(a.sell);
			MH[a.ma] = a;
			return in;
		}
};
int MatHang::cnt2 = 0;


class HoaDon{
	private:
		static int cnt3;
	public:
		string ma, maKH, maMH;
		int SoLuong;
		friend istream& operator >> (istream &in, HoaDon &a){
			a.cnt3++;
			a.ma = "HD" + string(3-to_string(a.cnt3).size(),'0') + to_string(a.cnt3);
			in >> a.maKH >> a.maMH >> a.SoLuong;
			return in;
		}
		friend ostream& operator << (ostream &out, HoaDon a){
			out << a.ma << " " << KH[a.maKH].ten << " " << KH[a.maKH].diachi << " " << MH[a.maMH].ten
			    <<" " <<MH[a.maMH].donvi << " " << MH[a.maMH].mua << " " << MH[a.maMH].ban <<" " << a.SoLuong << " " << MH[a.maMH].ban * a.SoLuong << endl;
		    return out;
		}
};
int HoaDon::cnt3 = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	fstream in1; in1.open("KH.in",ios::in);
	fstream in2; in2.open("MH.in",ios::in);
	fstream in3; in3.open("HD.in",ios::in);
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    string s;
    int N,M,K,i;
	getline(in1, s); N = stoi(s);
    for(i=0;i<N;i++) in1 >> dskh[i];
    getline(in2, s); M = stoi(s);
    for(i=0;i<M;i++) in2 >> dsmh[i];
	getline(in3, s); K = stoi(s);
    for(i=0;i<K;i++) in3 >> dshd[i];

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}
///////////Input

//////File KH.in
//2
//Nguyen Van Nam
//Nam
//12/12/1997
//Mo Lao-Ha Dong-Ha Noi
//Tran Van Binh
//Nam
//11/14/1995
//Phung Khoang-Nam Tu Liem-Ha Noi

//////File MH.in
//2
//Ao phong tre em
//Cai
//2500
//41000
//Ao khoac nam
//Cai
//240000
//515000

//////File HD.in
//3
//KH001 MH001 2
//KH001 MH002 3
//KH002 MH002 4

///////////Output
//HD001 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao phong tre em Cai 25000 41000 2 82000
//HD002 Nguyen Van Nam Mo Lao-Ha Dong-Ha Noi Ao khoac nam Cai 240000 515000 3 1545000
//HD003 Tran Van Binh Phung Khoang-Nam Tu Liem-Ha Noi Ao khoac nam Cai 240000 515000 4 2060000


