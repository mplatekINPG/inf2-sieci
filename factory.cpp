#include "Factory.h"
#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>

//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarcz¹
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

Sender::addReceiver()
{
	
}

Sender::send()
{
	
}

//-------------------------------------------------------------------------------//
//									Receiver
//-------------------------------------------------------------------------------//




//-------------------------------------------------------------------------------//
//									Ramp
//-------------------------------------------------------------------------------//

Ramp::Ramp(float freq)
{
	frequency = freq;
}

/* Ramp::addReceiver(Worker* w, float pref = -1)
{
	rampReceiver.push_back(w);
	
	//1 odbiorca, na pewno do niego
	if (rampReceiver.size() == 1) 
		rampReceiverPref.push_back(1.0);
		
	/*Dodanie nowego odbiorcy do puli odbiorców danego wêz³a 
	bez precyzowania prawdopodobieñstwa powoduje ustawienie 
	preferencji na rozk³ad jednostajny.*/
	/*else if (pref == -1)
	{
		for (int i=0; i<rampReceiver.size()-1; i++)
			rampReceiver[i] = 1/( rampReceiver.size() + 1 );
			
		rampReceiver.push_back(rampReceiver[0]);
	}
	//jak pref podany, to przelicza na nowo dla wszystkich (wzór od K³eczka)
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
		Product p1(/*trzeba znaleŸc sposób na iterowanie produktów*/);
		
		srand(time(NULL));
		int choice = rand()%100;
		
		if ( rampReceiver.size() != 0 )
			for (int i=0; i<rampReceiver.size() - 2; i++)  //mysla³em, czy da sie tu skorzystaæ z range-for, ale nie mam pomys³u jak
			{
				if (choice < rampReceiverPref[i+1]*100)
				{
					(rampReceiver[i]).addProduct(p1);
					break;
				}
			}
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

/*Worker::addReceiver(Worker* w, float pref = -1)
{
	workerReceiver.push_back(w);
	
	//tak jak w rampie
	if (workerReceiver.size() == 1) 
		workerReceiverPref.push_back(1.0);
	else if (pref == -1)
	{
		for (int i=0; i<workerReceiver.size()-1; i++)
			workerReceiver[i] = 1/( workerReceiver.size() + 1 );
			
		workerReceiver.push_back(workerReceiver[0]);
	}
	else
	{
		for (int i=0; i<workerReceiver.size()-1; i++)
			workerReceiver[i] = (1 - pref) * workerReceiver[i];
			
		workerReceiver.push_back(pref);
	}
}*/


Worker::work(float time)
{
	if (time == endTime)
		
}


