#ifndef _Percentage_Node_
#define _Percentage_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Percentage_Node :public Binary_Expr_Node{

public:

	Percentage_Node(void);
	virtual ~Percentage_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif