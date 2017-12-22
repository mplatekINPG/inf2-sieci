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

<<<<<<< HEAD
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
		for (auto i: receivers)  //mysla³em, czy da sie tu skorzystaæ z range-for, ale nie mam pomys³u jak
		{
			sum += i->second * 100;
			if (choice <= sum)
			{
				(i->first)->addProduct(p);
				break;
			}
		}
=======
Sender::addReceiver()
{

	Worker:: getQue
}

Sender::send()
{

>>>>>>> ffe825e0f4ec46570799ac6d3c9e12c577c27bca
}

//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(float freq)
{
	frequency = freq;
}

<<<<<<< HEAD
Ramp::update(float time, Product* p)
{
	if (time%frequency == 0)
	{
		send(p);
=======
/* Ramp::addReceiver(Worker* w, float pref = -1)
{
	rampReceiver.push_back(w);

	//1 odbiorca, na pewno do niego
	if (rampReceiver.size() == 1)
		rampReceiverPref.push_back(1.0);

	/*Dodanie nowego odbiorcy do puli odbiorcï¿½w danego wï¿½zï¿½a
	bez precyzowania prawdopodobieï¿½stwa powoduje ustawienie
	preferencji na rozkï¿½ad jednostajny.*/
	/*else if (pref == -1)
	{
		for (int i=0; i<rampReceiver.size()-1; i++)
			rampReceiver[i] = 1/( rampReceiver.size() + 1 );

		rampReceiver.push_back(rampReceiver[0]);
	}
	//jak pref podany, to przelicza na nowo dla wszystkich (wzï¿½r od Kï¿½eczka)
	else
	{
		for (int i=0; i<rampReceiver.size()-1; i++)
			rampReceiver[i] = (1 - pref) * rampReceiver[i];

		rampReceiver.push_back(pref);
	}
}*/

Ramp::update(float time)
{
	if (time%frequency == 0)
	{
		Product p1(/*trzeba znaleï¿½c sposï¿½b na iterowanie produktï¿½w*/);

		srand(time(NULL));
		int choice = rand()%100;

		if ( rampReceiver.size() != 0 )
			for (int i=0; i<rampReceiver.size() - 2; i++)  //myslaï¿½em, czy da sie tu skorzystaï¿½ z range-for, ale nie mam pomysï¿½u jak
			{
				if (choice < rampReceiverPref[i+1]*100)
				{
					(rampReceiver[i]).addProduct(p1);
					break;
				}
			}
>>>>>>> ffe825e0f4ec46570799ac6d3c9e12c577c27bca
	}
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

Worker::Worker(float time, QueueType queue)
{
	workTime = time;
	qType = queue;
}

Worker::addReceiver(Worker* w, float pref = -1)
{
	workerReceiver.push_back(w);

	//tak jak w rampie
	if (workerReceiver.size() == 1)
		workerReceiverPref.push_back(1.0);
	else if (pref == -1)
	{
		for (int i=0; i < workerReceiver.size()-1; i++)
			workerReceiver[i] = 1/( workerReceiver.size() + 1 );

		workerReceiver.push_back(workerReceiver[0]);
	}
	else
	{
		for (int i=0; i < workerReceiver.size()-1; i++)
			workerReceiver[i] = (1 - pref) * workerReceiver[i];

		workerReceiver.push_back(pref);
	}
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
Worker:: getQueueType()
{
	return qType;
}
Worker:: getProducts()
{
	return products;
}
