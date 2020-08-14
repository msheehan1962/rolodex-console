//********************************************************************
//
//  Name: Console.cpp
//
//  Description:
//
//
//  Author:  Mark Sheehan (Feb. 27, 2020)
//
//*******************************************************************

#include "Console.h"
#include <iostream>


// default constructor console/terminal IO
Console::Console() : inStream{ std::cin }, outStream{ std::cout } { }


// constructor for file input, output to std::cout
Console::Console(const std::string& infile) :
              _inFile{ infile, std::ios_base::in },    // open input file
              inStream{ _inFile }, outStream{ std::cout }
{
  _isInFile = true;
}

// constructor for file input and file output
Console::Console(const std::string& infile, const std::string& outfile) :
	_inFile{ infile, std::ios_base::in },    // open input file
	_outFile{ outfile, std::ios_base::out }, // open output file
	inStream{_inFile}, outStream{_outFile} {

	_isInFile = true; 
	_isOutFile = true;
}

// destructor: close any open files
Console::~Console() 
{
  if (_isInFile)
    _inFile.close();
  if (_isOutFile)
    _outFile.close();
}

// getLine: read the input from either inStream(cin) or inStream(_inFile) 
std::string Console::getLine() {

  std::string temp;
	
  // if reading from a file, set end-of-file as "done" input.
  if (_isInFile) {
    getline(_inFile, temp);
    if (inStream.eof())
      temp = "done";
  }
  else
    getline(std::cin, temp);
  return temp;
}

// putLine: print the parameter output string (ostr)
void Console::putLine(const std::string& ostr) const
{
  outStream << ostr;
}

// printPrompt: print the default prompt
void Console::printPrompt() const
{
  outStream << _prompt;
}
