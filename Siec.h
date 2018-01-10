#ifndef SIEC_H
#define SIEC_H

#include "factory.h"
#include "Queue.h"


class Net
{
	private:
		std::vector<Ramp*> ramps;
		std::vector<Worker*> workers;
		std::vector<Magazine*> magazines;	// Czy nie powinny to byæ wskaŸniki??
	
	public:
		int endingSimulationTime;
		void create();
		void update();
		void report();
};
#endif
