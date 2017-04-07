#ifndef _Multiplication_Node_
#define _Multiplication_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Multiplication_Node :public Binary_Expr_Node{

public:

	Multiplication_Node(void);
	virtual ~Multiplication_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif 