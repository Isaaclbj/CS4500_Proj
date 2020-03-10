#pragma once
#include "node.h"

class Application : public Node
{
public:
	
	void run_();

	size_t this_node();

	void run_override();

	void producer();

	void counter();

	void summarizer();

};