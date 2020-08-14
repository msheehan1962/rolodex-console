// --------------  INFO.2680-061 C++ Programming    ------------- //
// --------------          Mark Sheehan 		    ------------- //
// --------------        Rolodex Project            ------------- //

#include "Rolodex.h"
#include "Card.h"
#include <vector>
#include <string>
#include <algorithm>

//
// default constructor
//
Rolodex::Rolodex() {

	setOfCards = new std::multiset<Card>;
	_itr = setOfCards->begin();           // _itr is current card in rolodex
	// uncomment below to test the bad_alloc exception handler
	//char* pMemory = new char[0x7fffffff];
	//delete [] pMemory;
}

//
// destructor
//
Rolodex::~Rolodex() {
	
	delete setOfCards;
}

//
// add member function: (wrap to beginning if at the end)
//
void Rolodex::add(const Card& card) {

	if (_itr == setOfCards->end())
		_itr = setOfCards->begin();
	_itr = setOfCards->insert(card);
}

//
// remove member function:
//
Card Rolodex::remove() {

	Card temp = *_itr;       // _itr is the current card in the rolodex
	setOfCards->erase(_itr++);
	return temp;
}

//
// getCurrentCard member function: 
//
Card Rolodex::getCurrentCard() {
	
	if (_itr == setOfCards->end())
		_itr = setOfCards->begin();
	return *_itr;
}

//
// flip member function: (wrap to begin if at the end of the set)
//
Card Rolodex::flip() {
	
	if (++_itr == setOfCards->end())
		_itr = setOfCards->begin();
	return *_itr;
}

//
// search member function: 
//
bool Rolodex::search(const std::string& ln, const std::string& fn) {

	Card temp(fn, ln);
	
	if ((_itr = setOfCards->find(temp)) != setOfCards->end())
		return true; 
	
	return false;
}

//
//  show() displays all the cards on the Rolodex
//
void Rolodex::show(std::ostream& os) {
	
	for (auto card : *setOfCards)
		card.show(os);
}


// create card utility function:
// the input parameter "cardStrings" contains the strings input by 
// the user. these are used to create the rolodex card object.

void Rolodex::createCard(std::vector<std::string> cardStrings) {

	Card temp;
	std::string stmp{ "" };
	stmp = cardStrings.front();
	temp.setFirstName(cardStrings.at(0));
	temp.setLastName(cardStrings.at(1));
	temp.setOccupation(cardStrings.at(2));
	temp.setAddress(cardStrings.at(3));
	temp.setPhoneNumber(cardStrings.at(4));
	add(temp);
}