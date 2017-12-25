#ifndef SIEC_H
#define SIEC_H

class Net
{
	private:
		std::vector<Ramp*> ramps;
		std::vector<Worker*> workers;
		std::vector<Magazine*> magazines;	// Czy nie powinny to byæ wskaŸniki??
	
	public:
		void create();
		void update();
		void report();
}
#endif
