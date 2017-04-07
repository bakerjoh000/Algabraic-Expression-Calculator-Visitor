#ifndef _Calculator_Visiter_
#define _Calculator_Visiter_

#include <iostream>
#include "Expr_Tree_Builder.h"
#include <sstream>



class Calculator_Visiter{

public:

	Calculator_Visiter(void);
	virtual ~Calculator_Visiter(void);


	bool parse_expr(const std::string & infix, Expr_Tree_Builder &b);

	bool evaluate_expr(const std::string &infix);

	bool ArePair(char opening, char closing);
	
	bool AreParanthesesBalanced(std::string exp);

	bool IsAlpha(std::string number);

};

#endif 