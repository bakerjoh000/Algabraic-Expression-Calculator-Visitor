#ifndef _Expr_Builder_
#define _Expr_Builder_

#include <iostream>
#include "Expr_Node.h"
#include "Binary_Expr_Node.h"
#include "Stack.h"
#include "Array.h"
#include "Number_Node.h"
#include "Stack.cpp"
#include "Array.cpp"


class Expr_Builder{
public:

	Expr_Builder(void);
	virtual ~Expr_Builder(void);

	virtual void build_expression(void) = 0;
	virtual void build_number(int n) = 0;
	virtual void build_addition_operand(void) = 0;
	virtual void build_subtraction_operand(void) = 0;
	virtual void build_multiplication_operand(void) = 0;
	virtual void build_division_operand(void) = 0;
	virtual void build_percentage_operand(void) = 0;
	virtual void build_open_parenthesis(void) = 0;
	virtual void build_close_parenthesis(void) = 0;

	virtual Expr_Node * get_expression(void) = 0;

	virtual void checkWeight(Stack<Expr_Node *>& operators, Stack<Expr_Node *>& numbers, Expr_Node * rootNode, Expr_Node * expr_node) = 0;


	Expr_Node* getTopNumber();

	Expr_Node* getTopOperator();

	void popOperator();

	void popNumber();

	void pushNumber(Expr_Node * n);

	bool isOperatorsEmpty();

	bool isNumbersEmpty();




protected:
	Expr_Node * tree_;

	Stack<Expr_Node *> numbers;
	Stack<Expr_Node *> operators;
};


#endif 