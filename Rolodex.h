// --------------  INFO.2680-061 C++ Programming    ------------- //
// --------------          Mark Sheehan 		    ------------- //
// --------------        Rolodex Project            ------------- //

#ifndef _ROLODEX_H
#define _ROLODEX_H

#include "Card.h"
//#include <iostream>
#include <set>
#include <vector>
#include <string>
//#include <algorithm>
//#include <iterator>

class Rolodex {
public:
	Rolodex();				// default constructor
	~Rolodex();				// destructor

	void add(const Card&);
	void createCard(std::vector<std::string>);
	Card remove();
	Card getCurrentCard();
	Card flip();
	bool search(const std::string&, const std::string&);
	void show(std::ostream&);
	
	
private:
	std::multiset<Card>* setOfCards;
	std::multiset<Card>::iterator _itr;

};

#endif
