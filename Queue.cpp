#include "Queue.h"


#include "factory.h"
#include<iostream>
using namespace std;

void ProductQueueFIFO::push(Product* p)
{
	cout << 3 << endl;	
	products.push_back(p);
	cout << 3 << endl;
}


Product* ProductQueueFIFO::pop()
{
	Product* p = products.front();
	products.pop_front();	
	return p;
}

void ProductQueueLIFO::push(Product* p)
{
	cout << 3 << endl;	
	products.push_back(p);
	cout << 3 << endl;
}


Product* ProductQueueLIFO::pop()
{
	Product* p = products.back();
	products.pop_back();	
	return p;
}
