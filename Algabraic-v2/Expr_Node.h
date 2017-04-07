#ifndef _Expr_Node_
#define _Expr_Node_

#include <iostream>
#include "Expr_Node_Visitor.h"

class Expr_Node{

public:

	Expr_Node(void);
	virtual ~Expr_Node(void);

	virtual int accept(Expr_Node_Visitor & v) = 0;

	virtual int weight() = 0;


};

#endif