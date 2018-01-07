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

int Product::getID()
{
	return _id;
}

//-------------------------------------------------------------------------------//
//						OD TEGO MIEJSCA DO WYEDYTOWANIA!!!
//-------------------------------------------------------------------------------//


//-------------------------------------------------------------------------------//
//									Sender
//-------------------------------------------------------------------------------//

void Sender::addReceiver( Receiver* r, float pref = -1)
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

void Sender::send( Product *p)
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
}

void Sender::getReceivers()
{
	if (receivers.size() == 0)
		cout << "Brak polaczen\n";
	
	for (auto i: receivers)
		cout << i->first << ", p = " << i->second << endl; 
}

//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(int id, float freq)
{
	_id = id;
	frequency = freq;
}

void Ramp::update(float time, Product* p)
{
	if (time%frequency == 0)
	{
		send(p);
	}
}

int Ramp::getID()
{
	return _id;
}

float Ramp::getFrequency()
{
	return frequency;
}

//-------------------------------------------------------------------------------//
//									Magazine
//-------------------------------------------------------------------------------//

void Magazine::addProduct(Product* p)
{
	products.push_back(p);
}

vector<Products*> Magazine::getProducts()
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

void Worker::work(float time)
{
	if (time == endWork)
	{
		send(currentProduct);
		currentProduct = products.pop();
		endWork += workTime;
	}

}

void Worker::addProduct( Product* p)
{
	products.push(p);
}

int Worker:: getID()
{
	return _id;
}

float Worker:: getWorkTime()
{
	return workTime;
}

QueueType Worker:: getQueueType()
{
	return qType;
}

ProductQueue* Worker:: getProducts()
{
	return products;
}
