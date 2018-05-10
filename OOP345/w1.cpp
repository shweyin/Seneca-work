#include <iostream>
#include "Process.h"

extern int STORED;

int main(int argc, char *argv[])
{
	int errorcode = 0;
	std::cout << "Command Line :";
	for (int i = 0; i < argc; i++)
	{
		std::cout << " " << argv[i];
	}
	if (argc <= 1)
	{
		std::cout << "Insufficient number of arguments (min 1)";
		errorcode = 1;
	}
	else
	{
		std::cout << std::endl << "Maximum number of characters stored : " << STORED << std::endl;
		for (int i = 1; i < argc; i++)
		{
			process(argv[i]);
		}
	}
	return errorcode;
}