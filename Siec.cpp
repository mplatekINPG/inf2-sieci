#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <string>

#include "Factory.h"
#include "Queue.h"

//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarcz¹
using std::vector;
using std::list;
using std::map;
using std::cout;
using std::cin;
using std::string;

//--------------------------------------------------------------//
//--------------------------------------------------------------//

Net::create()
{	
	// wczytanie pliku i test wczytania
    std::fstream dane;
    string linia;
    float pref;
        
    dane.open( ".txt", std::ios::in)
    if (dane.good() == false)
	{
		cout << "brak dostepu do piku !!"
		return ;
	}
	
	// przeszukiwanie pliku
	while( !dane.eof() )
	{
		getline(dane, linia); //wczytuje linie
		if (linia[0] != ';') //jeœli nie komentarz
		{
			if (linia.find( "LOADING_RAMP" ) != std::string::npos)
			{
				Ramp::Ramp r( stoi(linia[16]), stof(linia[36]) ); //stoi - String TO Int
				ramps.push_back(&r); 							  //stof - String TO Float
				break;											
			}
			
			if (linia.find( "STOREHOUSE" ) != std::string::npos)
			{
				Magazine::Magazine m( stoi(linia[14]) );
				magazines.push_back(&m);
				break;
			}
								
			if (linia.find( "WORKER" ) != std::string::npos)
			{
				if (linia.find( "FIFO" ) != std::string::npos) //2 rodzaje kolejek
					Worker::Worker w( stoi(linia[11]), stof(linia[29]), LIFO);
				else
					Worker::Worker w( stoi(linia[11]), stof(linia[29]), FIFO);
				workers.push_back(&w);
				break;
			}
			
			if (linia.find( "LINK" ) != std::string::npos) //tworzenie wiazan
			{
				if (linia.find( "src=ramp" ) != std::string::npos)
				{
					for (auto i: ramps) //przeszukuje wszystkie rampy w poszukiwaniu tej o odpowiednim ID
					{
						if (getID(i) == stoi(linia.find( "-" ) + 1))
						{
							for (auto j: workers)
								if(getID(j) == stoi(linia.find( "r-" ) + 2))
								{
									auto wsk = linia.find( "p=" ) + 2;
									pref = stoi(wsk) + stoi(wsk+2)*0.1;
									i.addReceiver(j,pref);
								}
						}
					}
					break;	
				}
				
				if (linia.find( "src=worker" ) != std::string::npos)
				{
					for (auto i: workers) 
					{
						if (getID(i) == stoi(linia.find( "-" ) + 1))
						{
							if (linia.find( "dest=worker" ) != std::string::npos)
								for ( auto j: workers)
									if(getID(j) == stoi(linia.find( "dest=worker" ) + 12))
									{
										auto wsk = linia.find( "p=") + 2;
										pref = stoi(wsk) + stoi(wsk+2)*0.1;
										i.addReceiver(j,pref);
									}
									
							if (linia.find( "dest=store" ) != std::string::npos)
								for ( auto j: magazines)
									if(getID(j) == stoi(linia.find( "e-" ) + 2))
									{
										auto wsk = linia.find( "p=") + 2;
										pref = stoi(wsk) + stoi(wsk+2)*0.1;
										i.addReceiver(j,pref);
									}
						}
					}
					break;
				}
			}
		}
	}
	
	dane.close();
}

//--------------------------------------------------------------//
//--------------------------------------------------------------//

Net::update()
{
	
}

//--------------------------------------------------------------//
//--------------------------------------------------------------//

Net::report()
{
	
}
