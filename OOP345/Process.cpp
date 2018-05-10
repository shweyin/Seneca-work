#include "Cstring.h"
#include "Process.h"

void process(char* process_string)
{
	w1::Cstring myCstring(process_string);
	//myCstring.display(std::cout);
	std::cout << myCstring;
}
