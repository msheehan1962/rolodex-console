

#ifndef ROLODEXCONSOLE_H
#define ROLODEXCONSOLE_H

#include "Console.h"
#include "Rolodex.h"


class RolodexConsole : public Console
{
public:
	RolodexConsole() : Console() {}
	RolodexConsole(const std::string&);
	// constructor: use file input and file output
	RolodexConsole(const std::string&, const std::string&);

	// member functions
	std::string getLine();
	void printMenu();
	void printPrompt();
	void echo(std::string str);
	void toUpper(std::string& str);

};


#endif
