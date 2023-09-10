#include<bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int LuckyNum = rand()%100+1;
	int oke=0; int cnt=5;
	 cout << "Welcome to the Number Guessing Game!" << endl;
	do{
		cout << "Enter your guess (between 1 and 100): ";
		int find; cin >> find;
		if(find > LuckyNum) cout << "Too high! Try again." << endl;
		if(find < LuckyNum) cout << "Too low! Try again." << endl;
		if(find == LuckyNum){
			cout << "Congratulate you!!! The Lucky Number is: " << LuckyNum << endl;
			oke = 1;
		}
		cnt--;
	}while(oke==0 && cnt!=0);
	return 0;
}
