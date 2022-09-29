#include <iostream>
#include <queue>

using namespace std;

struct Chicken {
	float age;
	
	Chicken(float _age){
		age = _age;
	}
};

struct SizeCheck{
	bool operator()(Chicken const& c1, Chicken const& c2){
		return c1.age < c2.age;
	}
};

int main() {
	//This is a simple priority queue of numbers
	priority_queue<int> numbers; 
	numbers.push(5);
	numbers.push(10);
	numbers.push(99);
	numbers.push(60);
	numbers.push(94);
	while (!numbers.empty()){
		//Prints out the order of 99, 94, 60, 10, 5
		cout << numbers.top() << "\n"; 
		numbers.pop();
	}
	cout << "\n";
	
	//Uses the Chicken struct, a vector of type Chicken, and the SizeCheck operator to compare Chickens
	priority_queue<Chicken, vector<Chicken>, SizeCheck> chickens; 
	chickens.push(Chicken(30));
	chickens.push(Chicken(3));
	chickens.push(Chicken(8));
	chickens.push(Chicken(12));
	chickens.push(Chicken(35));
	while (!chickens.empty()){
		Chicken c = chickens.top();
		chickens.pop();
		cout << c.age << "\n"; //Prints out the order of 35, 30, 12, 8, 3
	}
	cout << "\n";


	return 0;
}
