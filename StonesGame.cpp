//BOC SOI
//You will join a game. Your mission is to win against the Bot.
//With each match, there are n stones. You can take 1,2,3,...,m stones.
//You get to play first, then the Bot play.
//Input: two intergers n, m. 
//Request: Check if you won the match.
//Output: You win or Bot win.

#include<bits/stdc++.h>
using namespace std;
int n, m;
void UserPlay(){
	int x;
	cout << "You take: x="; cin >> x;
	if(x > n || x > m){
		UserPlay();
	}
	else if(x <= m){
		n -= x;
	}
}
void BotPlay(){
	int x;
	if(n % (m+1) == 0) x = 1;
	else x = n % (m+1);
	cout << "Bot take: x=" << x << endl;
	n -= x;
}
void Display(){
	cout << "Current number of stones: " << n << endl;
}
int main(){
	cout << "Enter the number of stones: n="; cin >> n;
	cout << "Enter the max number of stones you can take: m="; cin >> m;
	while(1){
		UserPlay();
		Display();
		if(n == 0){
			cout << "You Win";
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1)); // Make the Bot run 1s slower
		BotPlay();
		Display();
		if(n == 0){
			cout << "Bot Win";
			break;
		}
	}
	return 0;
}
