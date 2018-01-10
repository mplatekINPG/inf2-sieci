#include "factory.h"
#include "Siec.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <utility>

//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarczï¿½
using std::vector;
using std::map;
using std::cout;
using std::cin;
using namespace std; //XD //NIE, tak si� nie robi, to nie jest dobra praktyka programistyczna xD



//-------------------------------------------------------------------------------//
//									Product
//-------------------------------------------------------------------------------//

int Product::ids = 0;

Product::Product()
{
	_id = ids;
	ids++;
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

void Sender::addReceiver( Receiver* r, float pref)
{	
	if (receivers.size() == 0) 
		receivers.insert(std::pair<Receiver*,float>(r,1.0));
		
/*	Dodanie nowego odbiorcy do puli odbiorców danego wêz³a 
	bez precyzowania prawdopodobieñstwa powoduje ustawienie 
	preferencji na rozk³ad jednostajny.*/

	///Prawdopodobnie nie zmienia wszystkich i trzeba będzie poprawić
	else if (pref == -1)
	{
		for (auto i=receivers.begin(); i!=receivers.end(); i++)
			i->second = 1/( receivers.size() + 1 );
			
		receivers.insert(std::pair<Receiver*,float>(r,receivers.begin()->second));
	}
	//jak pref podany, to przelicza na nowo dla wszystkich (wzór od K³eczka)
	else
	{
		for (auto i=receivers.begin(); i!=receivers.end(); i++)
			i->second = (1 - pref) * i->second;
			
		receivers.insert(std::pair<Receiver*,float>(r,pref));
	}
}

void Sender::send( Product *p)
{	
	srand(time(NULL));
	int choice = rand()%100;
	float sum = 0;

	if ( receivers.size() != 0 )
		for (auto i=receivers.begin(); i!=receivers.end(); i++) 
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
	
	for (auto i=receivers.begin(); i!=receivers.end(); i++)
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

void Ramp::update(float time)
{
	if (fmod(time,frequency) == 0)
	{
		send(new Product);
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

Magazine::Magazine(int id)
{
	_id = id;
}

void Magazine::addProduct(Product* p)
{
	products->push(p);
}

ProductQueue* Magazine::getProducts()
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
		currentProduct = products->pop();
		endWork += workTime;
	}

}

void Worker::addProduct( Product* p)
{
	products->push(p);
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
