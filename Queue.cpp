#include "Queue.h"


#include "factory.h"

void ProductQueueFIFO::push(Product* p)
{
	products.push_back(p);
}


Product* ProductQueueFIFO::pop()
{
	Product* p = products.front();
	products.pop_front();	
	return p;
}

void ProductQueueLIFO::push(Product* p)
{
	products.push_back(p);
}


Product* ProductQueueLIFO::pop()
{
	Product* p = products.back();
	products.pop_back();	
	return p;
}
