#ifndef QUEUE_H
#define QUEUE_H

class Product;

enum QueueType { FIFO, LIFO };

class ProductQueue
{
	private:
		QueueType qType;
		
	protected:
		std::list<Product*> products;
		
	public:
		virtual void push( Product* p) = 0;
		virtual Product* pop() = 0;
		QueueType getQueueType() const { return qType; };
};

class ProductQueueFIFO : public ProductQueue
{
	private:

	public:
		void push( Product* p);
		Product* pop();
};

class ProductQueueLIFO : public ProductQueue
{
	private:
	
	public:
		void push( Product* p);
		Product* pop();
};
#endif
