#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <map>
#include <vector>
#include <list>

#include "Queue.h"

class Product
{
	private:
		int _id;
		
	public:
		Product( int id );
		
		int getID();	
};


class Receiver
{
	public:
		virtual void addProduct( Product* p ) = 0;
		virtual ProductQueue* getProducts() = 0;
};


class Sender
{
	private:
		std::map<Receiver*,float> receivers;
	
	public:
		void addReceiver( Receiver* r, float pref = -1 );
		void send( Product* p );
		std::map<Receiver*,float> getReceivers();
};


class Ramp : public Sender
{
	private:
		int _id;
		float frequency;
		
	public:
		Ramp( int id, float freq );
		void update( float time, Product* p );
		
		int getID();
		float getFrequency();
};


class Magazine : public Receiver
{
	private:
		ProductQueue * products;
		QueueType qType = FIFO;
	
	public:
		void addProduct( Product* p);
		
		ProductQueue* getProducts();
};


class Worker : public Receiver, public Sender
{
	private:
		int _id;
		float workTime;
		float endWork;
		QueueType qType;
		ProductQueue* products;
		Product* currentProduct;

	public:
		Worker( int id, float time, QueueType queue );
		void work( float time );
		void addProduct( Product* p);
		
		int getID();
		QueueType getQueueType();
		ProductQueue* getProducts();
};
#endif
