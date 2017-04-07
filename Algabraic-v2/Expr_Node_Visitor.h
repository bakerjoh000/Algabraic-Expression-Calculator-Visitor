#ifndef _Expr_Node_Visitor_
#define _Expr_Node_Visitor_

#include <iostream>
class Addition_Node;
class Subtraction_Node;
class Number_Node;
class Multiplication_Node;
class Division_Node;
class Percentage_Node;



class Expr_Node_Visitor{

public:

	Expr_Node_Visitor();
	virtual ~Expr_Node_Visitor();

	virtual void Visit_Addition_Node(Addition_Node & node) = 0;
	virtual void Visit_Number_Node(Number_Node & node) = 0;
	virtual void Visit_Subtraction_Node(Subtraction_Node & node) = 0;
	virtual void Visit_Multiplication_Node(Multiplication_Node & node) = 0;
	virtual void Visit_Division_Node(Division_Node & node) = 0;
	virtual void Visit_Percentage_Node(Percentage_Node & node) = 0;

	virtual int result(void) = 0;

protected:
	int result_;

};

#endif