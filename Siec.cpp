#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::cin;

//-------------------------------------------------------------------------------//
//									Product
//-------------------------------------------------------------------------------//

Product::Product(int id)
{
	_id = id;
}

Product::Product()
{
	return _id;
}

//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(float freq)
{
	frequency = freq;
}

Ramp::addReceiver(Worker* w, float pref = -1)
{
	rampReceiver.push_back(w);
	
	if (pref != -1)
	{
		
	}
	else
	{
		
	}
}

Ramp::update(float time)
{
	
}

Ramp::getFrequency()
{
	return frequency;
}

Ramp::getReceivers()
{
	return rampReceiver;
}

//-------------------------------------------------------------------------------//
//									Magazine
//-------------------------------------------------------------------------------//

Magazine::addProduct(Product* p)
{
	products.push_back(p);
}

Magazine::getProducts()
{
	return products;
}

//-------------------------------------------------------------------------------//
//									Worker
//-------------------------------------------------------------------------------//

Worker::Worker(float time, QueueType queue)
{
	workTime = time;
	qType = queue;
}

Worker::addReceiver(Worker* w, float pref = -1)
{
	workerReceiver.push_back(w);
	
	if (pref != -1)
	{
		
	}
	else
	{
		
	}
}

Worker::addProduct(Product* p)
{
	products.push_back(p);
}

Worker::work(float time)
{
	
}

Worker::getQueueType()
{
	return qType;
}

Worker::getReceivers()
{
	return workerReceiver;
}

Worker::getProducts()
{
	return products;
}

