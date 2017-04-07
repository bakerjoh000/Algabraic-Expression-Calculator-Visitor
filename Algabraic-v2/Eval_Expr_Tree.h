#ifndef _Eval_Expr_Tree_
#define _Eval_Expr_Tree_

#include <iostream>
#include "Expr_Node_Visitor.h"
#include "Addition_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Multiplication_Node.h"
#include "Division_Node.h"
#include "Percentage_Node.h"
#include "Parenthesis_Node.h"


class Eval_Expr_Tree :public Expr_Node_Visitor{
public:
	Eval_Expr_Tree(void);
	virtual ~Eval_Expr_Tree(void);

	virtual void Visit_Addition_Node(Addition_Node & node);
	virtual void Visit_Number_Node(Number_Node & node);
	virtual void Visit_Subtraction_Node(Subtraction_Node & node);
	virtual void Visit_Multiplication_Node(Multiplication_Node & node);
	virtual void Visit_Division_Node(Division_Node & node);

	virtual void Visit_Percentage_Node(Percentage_Node & node);

	virtual int result(void);

};

#endif