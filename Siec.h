#ifndef SIEC_H
#define SIEC_H

#include <iostream>
#include <vector>
#include <list>

enum QueueType { FIFO, LIFO };

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
		addProduct( Product* p ) = 0;
};

class Worker : public Receiver;
class Magazine : public Receiver;

class Ramp
{
	private:
		float frequency;
		std::vector<Worker*> rampReceiver;
		std::vector<float> rampReceiverPref;
		
	public:
		Ramp( float freq );
		addReceiver( Worker* w, float pref = -1);
		update( float time );
		
		float getFrequency();
		std::vector<Worker*> getReceivers();
};

class Magazine : public Receiver
{
	private:
		std::vector<Product*> products;
	
	public:
		addProduct( Product* p);
		
		std::vector<Product*> getProducts();
};

class Worker : public Receiver
{
	private:
		float workTime;
		float endWork;
		QueueType qType;
		std::list<Product*> products;
		std::vector<Receiver*> workerReceiver;
		std::vector<float> workerReceiverPref;
	
	public:
		Worker( float time, QueueType queue );
		addReceiver( Receiver* r, float pref = -1 );
		addProduct( Product* p );
		work( float time );
		
		QueueType getQueueType();
		std::list<Product*> getProducts();
		std::vector<Receiver*> getReceivers();
}
#endif
