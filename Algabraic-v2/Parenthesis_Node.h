#ifndef _Parenthesis_Node_
#define _Parenthesis_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Parenthesis_Node :public Binary_Expr_Node{

public:

	Parenthesis_Node(void);
	virtual ~Parenthesis_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif 