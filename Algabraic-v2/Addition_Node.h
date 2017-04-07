#ifndef _Addition_Node_
#define _Addition_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Addition_Node : public Binary_Expr_Node{

public:

	Addition_Node(void);
	virtual ~Addition_Node(void);

	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif 
