#pragma once
#include "includeHeader.h"
// Start
namespace RandomNumberGenerator {
	int RandomNumber;
	int RangeNUM;
	int WaitTime;
	//
	void Random() {
		srand(time(0));
		for (int i = 0; i < WaitTime; i++) {
			RandomNumber = rand()%RangeNUM+1;
			std::cout << "Random Number Is :" << RandomNumber << std::endl;;
			//PText::PrintText("The Randome Number Is:",RandomNumber,true,true);
		}
	}
	//
	void RandomnumberConsole(){
		// Start
		std::string YN;
		//
		std::cout <<"\nNew range:";
		std::cin >> RangeNUM;
		//
		std::cout << "New 'For wait time':";
		std::cin >> WaitTime;
		//
		while (1){
			//
			std::cout << "Do You Wanna Genorate New Numbers <Y/N>";
			std::cin >> YN;
			//
			if (YN == "Y"){
				Random();
			}
			else if (YN == "N"){
				std::cout << "Ok closing : )" << std::endl;
				return;
			}
			else if (YN != "Y" or "N"){
				std::cout << "<Y/N> Only!" << std::endl;
			}
			//
		}
		//
	}
	//
}
// END;
