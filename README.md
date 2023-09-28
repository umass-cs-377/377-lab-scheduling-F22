# COMPSCI 377
# Scheduling Lab

## Purpose

This lab is designed to cover different types of scheduling used in operating systems, such as Round Robin. Please make sure that all of your answers to questions in these labs come from work done on the Edlab environment - otherwise, they may be inconsistent results and will not receive points.

The TA present in your lab will do a brief explanation of the various parts of this lab, but your group is expected to answer all questions on your own. Please raise your hand if you have any questions during the lab section. Questions and Parts have a number of points marked next to them to signify their weight in this lab’s final grade.

Please read through this lab and follow the instructions. After you do that, visit Gradescope and complete the questions associated with this lab by the assigned due date.

**You may work in groups up to 4 to complete this lab. Make sure you submit as a group in Gradescope.**

## Setup

Once you have logged in to Edlab, clone this repository. You can do this by clicking on the "Code" drop down, clone using HTTPS, and copy the repositories URL:

<img width="371" alt="image" src="https://user-images.githubusercontent.com/348202/192867111-70299f73-979c-4b15-84f5-9f036932a02f.png">

You then clone the repository with the URL REPO_URL like so:

```bash
git clone REPO_URL
```

Then you can use `cd` to open the directory you just cloned:

```bash
cd REPO
```

This repo includes a Makefile that allows you to compile and run all the sample code listed in this tutorial. You can compile them by running `make`. Feel free to modify the source files yourself, after making changes you can run `make` again to build new binaries from your modified files. You can also use `make clean` to remove all the built files, this command is usually used when something went wrong during the compilation so that you can start fresh.

## Part 1: FIFO (10 Points):

One scheduling algorithm is FIFO, or First In First Out. As it sounds, the scheduling algorithm simply runs whichever processes arrive first, and finishes with whichever processes arrive last. In essence, it acts like a line at the grocery store, taking whichever customer arrives first. While this does grant every process hypothetical fastest time, in reality a very slow process could bog down the system like a grocer with too much produce. If that happens, faster processes like a customer with only 10 items or less could be forced to wait even though they could be done in a short period of time.

## Part 2: SJF (10 Points):

The grocer with 10 items or less complained to the manager about their FIFO policy, and the store has now changed to the SJF policy, or Shortest Job First. With this new policy, the scheduling algorithm runs whichever process is the shortest, and finishes with whichever process is the longest. In the supermarket, this means that if someone has a lot of produce and is taking a while to check out, the cashier will tell them to wait and checks out someone with only a few items first. This leads to its own problem, however, in that the new policy only checks for shoppers that are all in line at the same time – if someone with a lot of groceries arrives before everyone else, they still have to wait for the one shopper to finish.

## Part 3: RR (10 Points):

Finally, the manager has had enough. Customers keep complaining, and they have no idea how to stop it. For their final act, they implement the RR policy, which dictates that customers be partial checked out one after another, looping through the line over and over again until everyone is checked out. This policy means that shoppers will all receive attention one at a time, but may take a while to finish if there are many customers in line.

However, Round Robin requires that processes be attended to for a while before moving onto the next one – otherwise, the cost of switching between processes becomes large enough that it fails to save any time at all. Additionally, while processes all get attention from the CPU relatively soon, it is terrible in turnaround time, since it must slowly iterate through all of the processes until it finishes.

## Part 4: Priority Queues (10 Points)

Priority queues can be a very useful tool in making various programs, and especially so in creating scheduling algorithms. They work just like queues, but instead of adding in new elements at the end elements are added with some value attached to them, and enter the queue such that it is sorted by the values of its elements. This means we can do things like create priority queues that prioritize certain elements, and push back other kinds of elements. As an example, please look at the code below:

chicken.cpp
```
#include <iostream>
#include <queue>

using namespace std;

struct Chicken {
	int age;
	
	Chicken(int _age){
		age = _age;
	}
};

struct AgeCheck{
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
	priority_queue<Chicken, vector<Chicken>, AgeCheck> chickens; 
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
```

The code above creates two priority queues, called numbers and chickens. Each sorts from high to low its metric – for numbers, the element itself, and for Chickens their age. As can be seen, it is significantly more difficult to sort a priority queue based on a struct than a primitive data type. There are also methods that can be done to create priority queues using classes – it is encouraged to look these up as they might be useful, but not required.

Additionally, it is good to remember three major methods when working with priority queues: push, top, and pop. push allows you to add an element to the priority queue, top returns the element at the front of the queue, and pop removes the front element of the queue. You can also use the empty and size methods to return whether the queue is empty or its size, respectively.
