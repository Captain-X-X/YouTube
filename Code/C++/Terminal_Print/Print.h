#pragma once
#include "includeHeader.h"
//
namespace PText {
	void PrintText(std::string Text, int NUM, bool Pendl, bool PNUM) {
		if (Pendl == true) {
			if (PNUM == true) {
				std::cout << Text << NUM << std::endl;
			}
			std::cout << Text << std::endl;
		}
		else if (Pendl == false) {
			if (PNUM == true) {
				std::cout << Text << NUM;
			}
			std::cout << Text;
		}
	}
}