#ifndef _Binary_Expr_Node_
#define _Binary_Expr_Node_

#include <iostream>
#include "Expr_Node_Visitor.h"
#include "Expr_Node.h"

class Binary_Expr_Node :public Expr_Node{

public:

	Binary_Expr_Node();
	virtual ~Binary_Expr_Node();


	virtual int accept(Expr_Node_Visitor & v) = 0;

	Expr_Node & getrightChild(void);
	Expr_Node & getleftChild(void);
	void setleftChild(Expr_Node * node);
	void setrightChild(Expr_Node * node);


	virtual int weight() = 0;



protected:

	Expr_Node * right_;
	Expr_Node * left_;

};

#endif 