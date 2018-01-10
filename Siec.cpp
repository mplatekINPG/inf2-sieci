#include "Siec.h"

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <string>


//dyrektywy using, zamiast nielubiane using namespace. Raczej wystarcz¹
using std::vector;
using std::list;
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::stof;

//--------------------------------------------------------------//
//--------------------------------------------------------------//

void Net::create()
{	
	// wczytanie pliku i test wczytania
    std::fstream dane;
    string linia;
    float pref;
        
    dane.open( /*"TU PODAJEMY ŒCIE¯KÊ DO PLIKU.txt"*/, std::ios::in);
    if (dane.good() == false)
	{
		cout << "brak dostepu do pliku !!";
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
				Ramp r( stoi(linia[16]), stof(linia[36]) ); //stoi - String TO Int
				ramps.push_back(&r); 							  //stof - String TO Float
				break;											
			}
			
			if (linia.find( "STOREHOUSE" ) != std::string::npos)
			{
				Magazine m( stoi(linia[14]) );
				magazines.push_back(&m);
				break;
			}
								
			if (linia.find( "WORKER" ) != std::string::npos)
			{
				if (linia.find( "FIFO" ) != std::string::npos) //2 rodzaje kolejek
					Worker w( stoi(linia[11]), stof(linia[29]), LIFO);
				else
					Worker w( stoi(linia[11]), stof(linia[29]), FIFO);
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
										i->addReceiver(j,pref);
									}
									
							if (linia.find( "dest=store" ) != std::string::npos)
								for ( auto j: magazines)
									if(getID(j) == stoi(linia.find( "e-" ) + 2))
									{
										auto wsk = linia.find( "p=") + 2;
										pref = stoi(wsk) + stoi(wsk+2)*0.1;
										i->addReceiver(j,pref);
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

void Net::update()
{ 
	create();
	int currentTime = 0;
	endingSimulationTime = 100/*SK¥D TO WZI¥Æ??*/ ;
	
	while ( currentTime < endingSimulationTime)
	{
		//-------------tu trza stworzyæ producta----------------//
		
		for (auto i: ramps)
			i->update(currentTime);
		
		for (auto i: workers)
			i->work(currentTime);
		
		//----//
		currentTime++;
	}
}

//--------------------------------------------------------------//
//--------------------------------------------------------------//

void Net::report()
{
	std::fstream raportStruktury;
	raportStruktury.open( "struktura_sieci.txt", std::ios::out );
	
	if ( raportStruktury.good() )
	{
		raportStruktury << "1. Ramps" << endl << endl;
		for (auto i: ramps)
		{
			raportStruktury << "\t ramp #" << i->getID() << "\n\tfreq = " << i->getFrequency() << endl;
			raportStruktury << "\tReceivers:\n";
			raportStruktury << "\t\t";
			i->getReceivers(); 
			cout<<endl;
		}
		
		raportStruktury << endl << "2. Workers" << endl << endl;
		for (auto i: workers)
		{
			raportStruktury << "\t worker #" << i->getID() << "\n\twork time = " << i->getWorkTime() << endl;
			raportStruktury<< "\tReceivers:\n";
			raportStruktury << "\t\t";
			i->getReceivers(); 
			cout<<endl;
		}
		
		raportStruktury << endl << "3. Storehouses" << endl << endl;
		for (auto i: magazines)
		{
		/*	raportStruktury << "\t Storehouse #" << i.getID() << endl << endl*/;
		}
	}
	
	std::fstream raportSymulacji;
	raportSymulacji.open( "stan_symulacji.txt", std::ios::out );
	
	
	
}
