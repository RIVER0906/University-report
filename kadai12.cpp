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
	cout << "�����X�^�[�𓢔����Ă�������" << endl;
	cout << "��Փx��I�����Ă�������" << endl;
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
	ename = "�X���C��";
	enehp = 15;
	eneatk = 3;
}
void Tougi::Enemy2() {
	ename = "�S�u����";
	enehp = 15;
	eneatk = 4;
}
void Tougi::Enemy3() {
	ename = "�I�[�N";
	enehp = 20;
	eneatk = 5;
}
void Tougi::Enemy4() {
	ename = "�h���S��";
	enehp = 25;
	eneatk = 5;
}
void Tougi::Enemy5() {
	ename = "����";
	enehp = 30;
	eneatk = 6;
}
void Tougi::Battle() {
	int x;
	int turn = 1;
	srand((unsigned)time(NULL));
	cout << endl;
	cout << ename << "�����ꂽ!" << endl;
	Slcoen();
	while (enehp > 0) {
		cout << turn << "�^�[����" << endl;
		Slcoen();
		turn++;
		cout << ename << "�̗̑� " << enehp << endl;
		cout << "�E�҂̗̑� " << myhp << endl;
		Slcoen();
		cout << "�ǂ�����?" << endl;
		cout << "1 �U��" << endl;
		cout << "2 ���U���@����" << skill << "��" << endl;
		cout << "3 �򑐁@����" << item << "��" << endl;
		cin >> x;
		if (x == 1) {
			damage = myatk + rand() % 3 - 1;
			enehp -= damage;
			cout << ename << "��" << damage << "�̃_���[�W��^����" << endl;
		}
		else if (x == 2 && skill > 0) {
			damage = myatk * 2 + rand() % 5 - 2;
			enehp -= damage;
			cout << ename << "��" << damage << "�̃_���[�W��^����" << endl;
			skill--;
		}
		else if (x == 3 && item > 0) {
			myhp = 30;
			cout << "�򑐂��g����" << endl;
			cout << "�̗͂��S�񕜂���" << endl;
			item--;
		}
		else {
			cout << "�s���Ɏ��s����" << endl;
		}
		Slcoen();
		if (enehp <= 0) {
			cout << ename << "�͓|�ꂽ" << endl;
			sumbattle++;
			if (sumbattle == 3) {
				Slcoen();
				cout << "Game Clear" << endl;
			}
			break;
		}
		damage = eneatk + rand() % 3 - 1;
		myhp -= damage;
		cout << ename << "�̍U��" << endl;
		cout << "�E�҂�" << damage << "�̃_���[�W���󂯂�" << endl;
		if (myhp <= 0) {
			Slcoen();
			cout << "�E�҂͓|�ꂽ" << endl;
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