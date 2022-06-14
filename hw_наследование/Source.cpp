#include<iostream>
#include <string>
using namespace std;
//Базовый класс растения
class Plants {
public:
	static int fruit_;
	static int berries_;
	Plants(){
		count_++;
	}
	Plants(string name, int value):Plants(){
		name_ = name;	
		fruit_ += value;
	}
	virtual~Plants() {
		count_--;
	}
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
private:
	string name_;
	static int count_;
};
//класс деревья
class Tree :public Plants {
public:
	Tree(){}
	Tree(string name, int value) : Plants(name, value){}
	virtual~Tree(){}
};
//класс кусты
class Bush :public Plants {
public:
	Bush(){}
	Bush(string name,int value) {
		Plants::set_name(name);
		berries_+= value;
		//count_++;
	}
	virtual~Bush(){}
};
//класс плоды
class Fetus {
public:
	Fetus(){}
	virtual~Fetus(){}
	static int all_fetus() {
		return Plants::fruit_ + Plants::berries_;
	}
	
};
//класс фрукты
class Fruits :public Fetus {
public:
	
	Fruits(){}

	virtual~Fruits(){}
	static int fetus_picking(int fetus) {
		Plants::fruit_ -= fetus;
		return Plants::fruit_;
	}
};
//класс ягоды
class Berries :public Fetus {
public:
	Berries(){}
	virtual~Berries(){}
	static int fetus_picking(int fetus) {
		Plants::berries_ -= fetus;
		return Plants::berries_;
	}

};
int Plants::fruit_ = 0;
int Plants::count_ = 0;
int Plants::berries_ = 0;


int main() {
	system("chcp 1251>nul");
	Tree tree1("дерево 1",20);
	Tree tree2("дерево 2",20);
	Bush bush1("куст 1",90);
	Bush bush2("куст 2",40);
	
	
	cout<<"Количество растений: "<<Plants::get_count()<< endl;
	cout <<"Количестов всего фруктов: "<< Plants::fruit_ << endl;
	cout <<"Количество всего ягод: " << Plants::berries_ << endl;
	int n = 10;
	cout << "Осталось фруктов, когда собрали " << n << " штук =  "<< Fruits::fetus_picking(n) << endl;
	cout << "Осталось ягод, когда собрали " << n << " штук =  " << Berries::fetus_picking(n) << endl;
	cout << "Общее количество плодов = " << Fetus::all_fetus()<<" шт " << endl;
	

	system("pause>nul");
	return 0;
}