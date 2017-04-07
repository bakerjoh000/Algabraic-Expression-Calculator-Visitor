#ifndef _Subtraction_Node_
#define _Subtraction_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Subtraction_Node :public Binary_Expr_Node{

public:

	Subtraction_Node(void);
	virtual ~Subtraction_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif 