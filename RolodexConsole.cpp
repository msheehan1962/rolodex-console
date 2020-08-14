
#include "RolodexConsole.h"
#include <string>
#include <algorithm>

// constructor used for file input and std::cout output
RolodexConsole::RolodexConsole(const std::string& infile) : Console(infile) {

}

// constructor used for file input and file output
RolodexConsole::RolodexConsole(const std::string& infile, 
				const std::string& outfile) : Console(infile, outfile) {

}

// call getline() using file or std::cin
std::string RolodexConsole::getLine() {

	std::string temp;
	if (_isInFile) {
		getline(_inFile, temp);
		if (inStream.eof())
			temp = "EOF";
	}
	else  // interactive input mode
		getline(std::cin, temp);
	
	return (temp);
}

// print the command options for the user. (only print if interactive mode)
void RolodexConsole::printMenu() {

	std::string menu{ "" };
	if (!_isInFile)
		menu = {"Valid commands: list, view, flip, add, remove, search, quit\n"};
	outStream << menu;
}

// command prompt for user input. also use in file mode to make the output
// more readable.
void RolodexConsole::printPrompt() {

	std::string prompt{ "Enter input command: " };
	outStream << prompt;
}

// send the file input to the std::cout
void RolodexConsole::echo(std::string str) {

	if (_isInFile)  // if reading input from a file, echo the input
		outStream << str << '\n';
}


// toUpper member function
void RolodexConsole::toUpper(std::string& str) {
	
	std::transform(str.begin(), str.end(), str.begin(), toupper);
}