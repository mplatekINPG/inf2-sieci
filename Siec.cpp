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
				Ramp::Ramp( stoi(linia[16]), stof(linia[36]) ); //stoi - String TO Int
				break;											//stof - String TO Float
			}
			
			if (linia.find( "STOREHOUSE" ) != std::string::npos)
			{
				Magazine::Magazine( stoi(linia[14]) );
				break;
			}
								
			if (linia.find( "WORKER" ) != std::string::npos)
			{
				if (linia.find( "FIFO" ) != std::string::npos) //2 rodzaje kolejek
					Worker::Worker( stoi(linia[11]), stof(linia[29]), LIFO);
				else
					Worker::Worker( stoi(linia[11]), stof(linia[29]), FIFO);
				break;
			}
			
			if (linia.find( "LINK" ) != std::string::npos) //tworzenie wiazan
				
		}
	}

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
