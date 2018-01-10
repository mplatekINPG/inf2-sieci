#include <iostream>
#include <vector>
#include <map>

#include "Siec.h"
#include "factory.h"
#include "Queue.h"


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	std::vector<Ramp> ramps;
	std::vector<Worker> workers;
	std::vector<Magazine> magazines;
	
	ramps.push_back(Ramp(1, 5));
	
	workers.push_back(Worker(1, 3, FIFO));
	
	magazines.push_back(Magazine(1));
	
	ramps[0].addReceiver( &workers[0] , 1);
	
	workers[0].addReceiver( &magazines[0], 1);
	
	int currentTime = 0;
	int endingSimulationTime = 100;
	
	while ( currentTime < endingSimulationTime)
	{
		//-------------tu trza stworzyæ producta----------------//
				
		ramps[0].update(currentTime);
		cout << 1 << endl;

		workers[0].work(currentTime);
		
		cout << 1 << endl;

		/*for (auto i: ramps)
			i.update(currentTime);
		
		for (auto i: workers)
			i.work(currentTime);*/
		
		//----//
		currentTime++;
	}
	return 0;
}
