#pragma once
#include "includeHeader.h"
//

// Update Log
// 1.0 Color Text. How to use? 'PText::PrintText(1,"Color Codes 1,2,3")

//
namespace PText {
	// BOOL
	bool ColorText;
	bool Pendl;
	bool PNUM;
	// INT
	int TextColor;
	int PTextNum;
	// STRING
	// std::string Textcolor;
	// CHAR
	
	void PrintText(int Color,std::string Text) {
		if (Pendl == true){
			if (Color == 1){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m" << std::endl;
				}
				std::cout << "\033[1;31m!" <<  Text << "\033[0m" << std::endl;
			}
			if (Color == 2){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m" << std::endl;
				}
				std::cout << "\033[1;30m!" <<  Text << "\033[0m" << std::endl;
			}
			if (Color == 3){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m" << std::endl;
				}
				std::cout << "\033[1;34m!" <<  Text << "\033[0m" << std::endl;
			}
		}
		else if (Pendl == false){
			if (Color == 0){
				if (PNUM == true){
					std::cout << Text << PTextNum;
				}
				std::cout << Text;
			}
			if (Color == 1){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m";
				}
				std::cout << "\033[1;31m!" <<  Text << "\033[0m";
			}
			if (Color == 2){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m";
				}
				std::cout << "\033[1;30m!" <<  Text << "\033[0m";
			}
			if (Color == 3){
				if (PNUM == true){
					std::cout << "\033[1;31m!" <<  Text << PTextNum << "\033[0m";
				}
				std::cout << "\033[1;34m!" <<  Text << "\033[0m";
			}
		}
	}
}