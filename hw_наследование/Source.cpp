#include<iostream>
#include <string>
using namespace std;
//������� ����� ��������
class Plants {
public:
	static int count_;
	static int fruit_;
	static int berries_;
	Plants(){}
	Plants(string name,int value){
		name_ = name;
		fruit_+=value;
		count_++;
	}
	virtual~Plants(){}
	void set_name(string name) {
		this->name_ = name;
	}
	string get_name() {
		return name_;
	}
		static int get_count() {
		return count_;
	}
	static int get_fruits() {
		return fruit_;
	}
	static int all_fetus() {
		return fruit_ + berries_;
	}
private:
	string name_;
};
//����� �������
class Tree :public Plants {
public:
	Tree(){}
	Tree(string name,int value) :Plants(name,value) {}
	virtual~Tree(){}
	static int fetus_picking(int fetus) {
		fruit_ -= fetus;
		return fruit_;
	}
};
//����� �����
class Bush :public Plants {
public:
	Bush(){}
	Bush(string name,int value) {
		Plants::set_name(name);
		berries_+= value;
		count_++;
	}
	virtual~Bush(){}
	static int fetus_picking(int fetus) {
		berries_ -= fetus;
		return berries_;
	}
};
//����� �����
class Fetus {
public:
	Fetus(){}
	virtual~Fetus(){}
	
};
//����� ������
class Fruits :public Fetus {
	Fruits(){}
	virtual~Fruits(){}
};
//����� �����
class Berries :public Fetus {
	Berries(){}
	virtual~Berries(){}
};
int Plants::fruit_ = 0;
int Plants::count_ = 0;
int Plants::berries_ = 0;


int main() {
	system("chcp 1251>nul");
	Tree tree1("������ 1",20);
	Tree tree2("������ 2",20);
	Bush bush1("���� 1",90);
	Bush bush2("���� 2",40);
	
	
	cout<<"���������� ��������: "<<Plants::count_ << endl;
	cout <<"���������� ����� �������: "<< Plants::fruit_ << endl;
	cout <<"���������� ����� ����: " << Plants::berries_ << endl;
	int n = 10;
	cout << "�������� �������, ����� ������� " << n << " ���� =  "<< Tree::fetus_picking(n) << endl;
	cout << "�������� ����, ����� ������� " << n << " ���� =  " << Bush::fetus_picking(n) << endl;
	cout << "����� ���������� ������ = " << Plants::all_fetus()<<" �� " << endl;
	

	system("pause>nul");
	return 0;
}