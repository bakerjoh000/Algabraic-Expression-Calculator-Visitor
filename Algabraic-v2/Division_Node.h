#ifndef _Division_Node_
#define _Division_Node_

#include <iostream>
#include "Binary_Expr_Node.h"


class Division_Node :public Binary_Expr_Node{

public:

	Division_Node(void);
	virtual ~Division_Node(void);


	virtual int accept(Expr_Node_Visitor & v);

	virtual int weight();
};

#endif 