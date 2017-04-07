#ifndef _Number_Node_
#define _Number_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Number_Node :public Binary_Expr_Node{

public:

	Number_Node(int n);
	virtual ~Number_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();

	int getNumber();

private:
	int n_;
};

#endif 