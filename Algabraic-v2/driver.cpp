#include <iostream>
#include "Array.h"
#include "Calculator_Visitor.h"
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <time.h>


int main()
{
	Calculator_Visiter c;
	std::string infix;
	bool keepGoing = true;

	while (keepGoing)
	{
		std::cout << "Enter an Expression: " << std::endl;
		std::getline(std::cin, infix);

		if (c.AreParanthesesBalanced(infix)){
			c.evaluate_expr(infix);
		}
		else
			std::cout << "Not Balanced parenthesis\n";

		std::cout << "  \n";

	}

	return 0;
}