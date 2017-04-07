#ifndef _Expr_Tree_Builder_
#define _Expr_Tree_Builder_

#include <iostream>
#include "Expr_Builder.h"




class Expr_Tree_Builder : public Expr_Builder {

public:
	Expr_Tree_Builder(void);
	virtual ~Expr_Tree_Builder(void);


	virtual void build_number(int n);
	virtual void build_addition_operand(void);
	virtual void build_subtraction_operand(void);
	virtual void build_multiplication_operand(void);
	virtual void build_division_operand(void);
	virtual void build_percentage_operand(void);
	virtual void build_open_parenthesis(void);
	virtual void build_close_parenthesis(void);
	virtual void build_expression(void);

	virtual void checkWeight(Stack<Expr_Node *>& operators, Stack<Expr_Node *>& numbers, Expr_Node * rootNode, Expr_Node * expr_node);


	virtual Expr_Node * get_expression(void);


};

#endif