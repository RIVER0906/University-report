#include<iostream>
#include<string>
#include<windows.h>
#include<ctime>
#include<stdio.h>
using namespace std;
class Tougi {
private:
	int myhp;
	int myatk;
	int enehp;
	int eneatk;
	int sumbattle = 0;
	int skill = 3;
	int item = 2;
	int damage;
	string ename;
public:
	Tougi();
	void Easy();
	void Normal();
	void Hard();
	void Enemy1();
	void Enemy2();
	void Enemy3();
	void Enemy4();
	void Enemy5();
	void Battle();
	void Slcoen();
};
Tougi::Tougi(){
	myhp = 30;
	myatk = 5;
	eneatk = 0;
	enehp = 0;
	int x;
	cout << "モンスターを討伐してください" << endl;
	cout << "難易度を選択してください" << endl;
	cout << "1 Easy 2 Normal 3 Hard" << endl;
	cin >> x;
	if (x == 1) {
		Easy();
	}
	if (x == 2) {
		Normal();
	}
	if (x == 3) {
		Hard();
	}
	else {
		cout << "ERROR" << endl;
	}
}
void Tougi::Easy() {
	if (myhp > 0) {
		Enemy1();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy2();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy3();
		Battle();
	}

}
void Tougi::Normal() {
	if (myhp > 0) {
		Enemy2();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy3();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy4();
		Battle();
	}
}
void Tougi::Hard() {
	if (myhp > 0) {
		Enemy3();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy4();
		Battle();
	}
	if (myhp > 0) {
		Sleep(1000);
		Enemy5();
		Battle();
	}
}
void Tougi::Enemy1() {
	ename = "スライム";
	enehp = 15;
	eneatk = 3;
}
void Tougi::Enemy2() {
	ename = "ゴブリン";
	enehp = 15;
	eneatk = 4;
}
void Tougi::Enemy3() {
	ename = "オーク";
	enehp = 20;
	eneatk = 5;
}
void Tougi::Enemy4() {
	ename = "ドラゴン";
	enehp = 25;
	eneatk = 5;
}
void Tougi::Enemy5() {
	ename = "魔王";
	enehp = 30;
	eneatk = 6;
}
void Tougi::Battle() {
	int x;
	int turn = 1;
	srand((unsigned)time(NULL));
	cout << endl;
	cout << ename << "が現れた!" << endl;
	Slcoen();
	while (enehp > 0) {
		cout << turn << "ターン目" << endl;
		Slcoen();
		turn++;
		cout << ename << "の体力 " << enehp << endl;
		cout << "勇者の体力 " << myhp << endl;
		Slcoen();
		cout << "どうする?" << endl;
		cout << "1 攻撃" << endl;
		cout << "2 強攻撃　あと" << skill << "回" << endl;
		cout << "3 薬草　あと" << item << "回" << endl;
		cin >> x;
		if (x == 1) {
			damage = myatk + rand() % 3 - 1;
			enehp -= damage;
			cout << ename << "に" << damage << "のダメージを与えた" << endl;
		}
		else if (x == 2 && skill > 0) {
			damage = myatk * 2 + rand() % 5 - 2;
			enehp -= damage;
			cout << ename << "に" << damage << "のダメージを与えた" << endl;
			skill--;
		}
		else if (x == 3 && item > 0) {
			myhp = 30;
			cout << "薬草を使った" << endl;
			cout << "体力が全回復した" << endl;
			item--;
		}
		else {
			cout << "行動に失敗した" << endl;
		}
		Slcoen();
		if (enehp <= 0) {
			cout << ename << "は倒れた" << endl;
			sumbattle++;
			if (sumbattle == 3) {
				Slcoen();
				cout << "Game Clear" << endl;
			}
			break;
		}
		damage = eneatk + rand() % 3 - 1;
		myhp -= damage;
		cout << ename << "の攻撃" << endl;
		cout << "勇者は" << damage << "のダメージを受けた" << endl;
		if (myhp <= 0) {
			Slcoen();
			cout << "勇者は倒れた" << endl;
			Sleep(1000);
			cout << endl;
			cout << "Game Over" << endl;
			break;
		}
		Slcoen();
	}

}
void Tougi::Slcoen() {
	Sleep(1000);
	cout << endl;
}
int main() {
	Tougi n;
	return 0;
}