#pragma once
#include "includeHeader.h"
// Start
namespace RandomNUM {
	int RandomNumber;
	int RangeNUM;
	int WaitTime;
	//
	void Randeom() {
		srand(time(0));
		for (int i = 0; i < WaitTime; i++) {
			RandomNumber = rand()%RangeNUM+1;
			std::cout << "Random Number Is :" << RandomNumber << std::endl;;
			//PText::PrintText("The Randome Number Is:",RandomNumber,true,true);
		}
	}
	//
	void RangeNumber(){
		int NewRange;
		int NewTime;
		int WNUM = 100;
		while (WNUM == 100){
			std::string Command;
			std::cout << "Command:";
			std::cin >> Command;
			// Check The Command!
			if (Command == "NewRange"){
				std::cout << "Custom Range For The Number Gen:";
				std::cin >> NewRange;
				// When Done!
				RandomNUM::RangeNUM = NewRange;
				std::cout << "- - - - Range Updated To:" << NewRange << std::endl;;
			}
			if (Command == "SetTime"){
				std::cout << "Set New Time:";
				std::cin >> NewTime;
				std::cout << "- - - - Time Updated To:" << NewTime << std::endl;
			}
			if (Command == "Start"){
				RangeNUM = NewRange;
				WaitTime = NewTime;
				Randeom();
			}
			if (Command == "Stop"){
				return;
			}
		}
	}
}