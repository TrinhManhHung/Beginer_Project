//Hexadoku (Sudoku 16x16) Solver

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

char a[16][16];
vector<char> hang[16];
vector<char> cot[16];

void Init(){
	cout << "Line 1 to Line 16 : 16 characters in the range A..P or . (empty cell)" << endl;
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			cin >> a[i][j];
			if(a[i][j] != '.'){
				hang[i].pb(a[i][j]);
				cot[j].pb(a[i][j]);
			}
		}
	}
}
bool CheckValid(char alpha, int cur_i, int cur_j){
	//check row
	for(char x : hang[cur_i]){
		if(alpha == x) return false;
	}
	//check column
	for(char x : cot[cur_j]){
		if(alpha == x) return false;
	}
	//check block
	int block_i = (cur_i / 4) * 4;
	int block_j = (cur_j / 4) * 4;
	for(int k = block_i; k < block_i + 4; k++){
		for(int l = block_j; l < block_j + 4; l++){
			if(alpha == a[k][l]) return false;
		}
	}
	return true;
}

void BacktrackToNext(int i, int j);
bool isFinish = false;

void Display(){
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			cout << a[i][j];
		}
		cout << endl;
	}
}
void Backtracking(int cur_i, int cur_j){
	if(cur_i == 16 && cur_j == 0){
		Display();
	}
	if(isFinish) return;
	if(cur_i >=0 && cur_j >=0 && cur_i <16 && cur_j <16){
		if(a[cur_i][cur_j] == '.'){
			for(char k = 'A'; k <= 'P'; k++){
				if(CheckValid(k, cur_i, cur_j)){
					a[cur_i][cur_j] = k;
					hang[cur_i].pb(k);
					cot[cur_j].pb(k);
					
					BacktrackToNext(cur_i, cur_j);
					
					a[cur_i][cur_j] = '.';
					hang[cur_i].pop_back();
					cot[cur_j].pop_back();
				}
			}
		}
		else{
			BacktrackToNext(cur_i, cur_j);
		}
	}
}
void BacktrackToNext(int i, int j){
	int next_i = i, next_j = j;
	if(j < 15){
		next_i = i;
		next_j = j+1;
	}
	if(j == 15){
		next_i = i+1;
		next_j = 0;
	}
	Backtracking(next_i, next_j);
}
int main(){
	Init();
	Backtracking(0, 0);
	return 0;
}
//Input
//.LEK.G.....NO.C.
//..M.H.JOBDG.FENK
//J..C.BAN.EK....I
//.BG..K..C.J..DPM
//.HA.FL..K..M.P..
//...OA.....D.IK.G
//..KDJ.CBFAIG.MHL
//.M.....EPJNO.A..
//G...IA.DE.CJP...
//AK....GHNM..LIJ.
//..DJON..GL.BKH.F
//.N...J.K.F...GAB
//D..A..FJ..LIM.K.
//E.LFCDB.O.M.N.I.
//.JI....PD.....L.
//.....H.IJ....CBA
//
//Output
//HLEKDGMFAIPNOBCJ
//IAMPHCJOBDGLFENK
//JDOCPBANMEKFHLGI
//FBGNEKILCOJHADPM
//CHAIFLDGKBEMJPON
//BEJOAPNMLHDCIKFG
//NPKDJOCBFAIGEMHL
//LMFGKIHEPJNOBADC
//GFHBIALDEKCJPNMO
//AKCEBFGHNMOPLIJD
//MIDJONPCGLABKHEF
//ONPLMJEKIFHDCGAB
//DCBAGEFJHNLIMOKP
//EGLFCDBAOPMKNJIH
//KJIHNMOPDCBAGFLE
//PONMLHKIJGFEDCBA
