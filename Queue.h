#ifndef QUEUE_H
#define QUEUE_H

enum QueueType { FIFO, LIFO };

class ProductQueue
{
	private:
		QueueType qType;
		
	public:
		push( Product* p);
		pop( Product* p);
		QueueType getQueueType();
};

class ProductQueueFIFO : public ProductQueue
{
	private:
		std::list<Product*> products;		//bo K³eczek mówi³, ¿e ze stack i queue s¹ problemy, a z list¹ nie ma
		//std::queue<Product*> products;
	public:
		void push( Product* p);
		void pop( Product* p);
		//QueueType getQueueType();
};

class ProductQueueLIFO : public ProductQueue
{
	private:
		std::list<Product*> products;
		//std::stack<Product* p> products;	
	
	public:
		void push( Product* p);
		void pop( Product* p);
		//QueueType getQueueType();
};
#endif
