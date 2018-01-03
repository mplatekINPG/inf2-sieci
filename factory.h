#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <vector>
#include <list>

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
		virtual std::vector<Product*> getProducts() = 0;
};


class Sender
{
	private:
		std::map<Receiver*,float> receivers;
	
	public:
		void addReceiver( Receiver* r, float pref = -1 );
		void send( Product* p );
		std::map<receiver*,float> getReceivers();
};


class Worker : public Receiver, public Sender;
class Magazine : public Receiver;


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
		std::vector<Product*> products;
	
	public:
		void addProduct( Product* p);
		
		std::vector<Product*> getProducts();
};


class Worker : public Receiver, public Sender
{
	private:
		int _id;
		float workTime;
		float endWork;
		ProductQueue* products;
		Product* currentProduct;

	public:
		Worker( int id, float time, QueueType queue );
		void work( float time );
		void addProduct( Product* p);
		
		int getID();
		QueueType getQueueType();
		ProductQueue* getProducts();
}
#endif
