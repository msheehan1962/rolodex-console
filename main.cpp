// include files
#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Rolodex.h"
#include "RolodexConsole.h"

using namespace std;

// command function prototypes
void list(Rolodex&);  
void view(Rolodex&); 
void flip(Rolodex&);
void add(Rolodex&);
void remove1(Rolodex&);
void search(Rolodex&);
void quit(Rolodex&);
// utility function prototype
vector<string> parseInput(const std::string&, char);


// global console object instantiation. Uncomment the
// #define INTERACTIVE_MODE to run interactivly.

#define INTERACTIVE_MODE
// read input from std::cin
#ifdef INTERACTIVE_MODE   
RolodexConsole console;   

#else     
// read input from file, write output to std::cout or file
std::string outFile{ "RolodexTestOutput.txt" };
std::string inFile{ "RolodexTestInput.txt" };
RolodexConsole console(inFile);                 // input file and std::cout
//RolodexConsole console(inFile, outFile);      // input and output files
#endif

// class to handle invalid user input exception
class InvalidInput : public exception {
public:
    virtual const char* what() const throw() {
        return "invalid input command";
    }
};

//
//  main() program function
//
int main() {

    try {

        Rolodex myRolodex;


        {  // scope block for initializing the console object. 
           
           // open the init file and attach it to the console object.
            std::string initFile{ "RolodexInit.txt" };
            RolodexConsole console(initFile);

            // initialize the 10 Rolodex cards using the console istream object
            vector<string> dataTokens;
            std::string fileContents;

            // read each input line, parse into tokens, create the 
            // card and add it to the rolodex.

            while ((fileContents = console.getLine()) != "EOF") {
                 
                dataTokens = parseInput(fileContents, ';');
                myRolodex.createCard(dataTokens);           // calls Rolodex.add()
            }

        } // end scope block for initializing the console object

        // below we use the globally defined console object for IO 
        string input;

        while (1) {
            try {
                console.printMenu();
                console.printPrompt();
                console.inStream >> input;
                console.echo(input);
                console.toUpper(input);

                if (console.inStream.eof())
                    break;

                if (input == "LIST")
                    list(myRolodex);
                else if (input == "VIEW")
                    view(myRolodex);
                else if (input == "FLIP")
                    flip(myRolodex);
                else if (input == "ADD")
                    add(myRolodex);
                else if (input == "REMOVE")
                    remove1(myRolodex);
                else if (input == "SEARCH")
                    search(myRolodex);
                else if (input == "QUIT")
                    break;
                else 
                    throw InvalidInput();
            } // try
            catch (InvalidInput& ii) {
                cerr << "Exception: " << ii.what() << endl;
            }
        } // while
    } // try  
    
    catch (bad_alloc& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    return 0;
}

//***********************************************************************
// parseInput utility function breaks a string into sub-strings (tokens)
// delimited by input parameter "delimiter". A vector of these tokens is
// returned to the calling function.
//***********************************************************************
const int FIELD_CT{ 5 };
vector<string>  parseInput(const std::string& str, char delimiter)
{
  std::vector<std::string> tokens;
  size_t size{ 0 };
  int pos{ 0 };
  for (int feild{ 0 }; feild < FIELD_CT; feild++) {
    size = str.find(delimiter, pos);
    tokens.insert(tokens.end(), str.substr(pos, size-pos));
    pos = (size + 1);
  }
  return tokens;
}

/*
 *  command functions
 */

void list(Rolodex& rdx)
{
    console.putLine("* List utility  *\n");

    rdx.show(console.outStream);
}

void view(Rolodex& rdx)
{
    console.putLine("* View utility  *\n");

    Card localCard = rdx.getCurrentCard();
    localCard.show(console.outStream);
}

void flip(Rolodex& rdx)
{
    console.putLine("* Flip utility  *\n");

    Card localCard = rdx.flip();
    localCard.show(console.outStream);
}

//
//  add() cannot use the stream extraction >> operator to read input
//  due to the embedded space(s) in the input address field.
//
void add(Rolodex& rdx)
{
    console.putLine("*  Add utility  *\n");

    vector<string> prompts{ "Enter first name: ", "Enter last name: ",
                            "Enter occupation: ", "Enter address: ",
                            "Enter phone number: "};

    // storage for input strings
    vector<string> cardStrings;
    std::string input;
 
    // clear the '\n' character from the stream left behind by the
    // stream extraction >> operator.
    if (char junk = console.inStream.peek() == '\n')
        console.inStream >> std::ws;

    // prompt and populate the cardStrings vector with input
    for (int i{ 0 }; i < 5; i++) {
        console.putLine(prompts[i]);
        input = console.getLine();
        console.echo(input);
        cardStrings.push_back(input);  
    }

    // create a card from user input and add to the set
    rdx.createCard(cardStrings);        // calls rdx.add()
}

void remove1(Rolodex& rdx)
{
    console.putLine("* Remove utility *\n");

    Card temp = rdx.getCurrentCard();
    
    string input;
    console.putLine("Remove: ");
    temp.show(console.outStream);
    console.putLine("Are you sure? (yes or no): ");
   
    console.inStream >> input;
    console.echo(input);

    if ("yes" == input)
        temp = rdx.remove();
}

void search(Rolodex& rdx)
{
    string input[2];
    console.outStream << "* Search utility *\n";

    // prompt for which card to find
    console.outStream << "Enter last name: ";
    console.inStream >> input[0];
    console.echo(input[0]); 
    console.outStream << "Enter first name: ";
    console.inStream >> input[1];
    console.echo(input[1]); 

    // search for the card
    if (!rdx.search(input[0], input[1]))
        console.outStream << input[0] << ", " << input[1] << " card not found!\n";

    // if card is found, display it.
    else {
        Card temp = rdx.getCurrentCard();
        temp.show(console.outStream);
    }
}

void quit(Rolodex& rdx)
{
    return;
}
