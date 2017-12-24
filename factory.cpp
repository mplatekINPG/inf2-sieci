#include "Factory.h"
#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>

//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarczï¿½
using std::vector;
using std::map;
using std::cout;
using std::cin;



//-------------------------------------------------------------------------------//
//									Product
//-------------------------------------------------------------------------------//

Product::Product(int id)
{
	_id = id;
}

Product::getID()
{
	return _id;
}

//-------------------------------------------------------------------------------//
//						OD TEGO MIEJSCA DO WYEDYTOWANIA!!!
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//
//									Sender
//-------------------------------------------------------------------------------//

Sender::addReceiver( Receiver* r, float pref = -1)
{	
	if (receivers.size() == 0) 
		receiver.insert(std::pair<Receiver*,float>(r,1.0));
		
/*	Dodanie nowego odbiorcy do puli odbiorców danego wêz³a 
	bez precyzowania prawdopodobieñstwa powoduje ustawienie 
	preferencji na rozk³ad jednostajny.*/
	else if (pref == -1)
	{
		for (auto i=receivers.begin(); i!=receivers.end(); i++)
			i->second = 1/( receivers.size() + 1 );
			
		receivers.insert(std::pair<Receiver*,float>(r,receivers[0]->second);
	}
	//jak pref podany, to przelicza na nowo dla wszystkich (wzór od K³eczka)
	else
	{
		for (auto i=receivers.begin(); i!=receivers.end(); i++)
			i->second = (1 - pref) * i->second;
			
		receivers.insert(std::pair<Receiver*,float>(r,pref);
	}
}

Sender::send( Product *p)
{	
	srand(time(NULL));
	int choice = rand()%100;
	float sum = 0;

	if ( receivers.size() != 0 )
		for (auto i: receivers) 
		{
			sum += i->second * 100;
			if (choice <= sum)
			{
				(i->first)->addProduct(p);
				break;
			}
		}

Sender::addReceiver()
{
	Worker:: getQue
}

//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(int id, float freq)
{
	_id = id;
	frequency = freq;
}

Ramp::update(float time, Product* p)
{
	if (time%frequency == 0)
	{
		send(p);
	}
}

Ramp::getID()
{
	return _id;
}

Ramp::getFrequency()
{
	return frequency;
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

Worker::Worker(int id, float time, QueueType queue)
{
	_id = id;
	workTime = time;
	qType = queue;
}

Worker::work(float time)
{
	if (time == endWork)
	{
		send(currentProduct);
		currentProduct = products.pop();
		endWork += workTime;
	}

}

Worker:: addProduct( Product* p)
{
	products.push(p);
}

Worker:: getID()
{
	return _id;
}

Worker:: getQueueType()
{
	return qType;
}

Worker:: getProducts()
{
	return products;
}
