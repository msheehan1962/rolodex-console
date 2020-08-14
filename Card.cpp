// --------------  INFO.2680-061 C++ Programming    ------------- //
// --------------          Mark Sheehan 		    ------------- //
// --------------        Rolodex Project            ------------- //

#include "Card.h"
#include <iostream>

// copy constructor
Card::Card(const Card& cpySrc) {

	firstName = cpySrc.firstName;
	lastName = cpySrc.lastName;
	occupation = cpySrc.occupation;
	address = cpySrc.address;
	phoneNumber = cpySrc.phoneNumber;
}


// equality operator "used by find or search"
bool Card::operator== (const Card& card) {

	if ((lastName != card.lastName) || (firstName != card.firstName)) 
		return false;
	else
		return true;
}

// equality operator: used by search
bool operator==(const Card& lhs, const Card& rhs) {

	if ((lhs.lastName != rhs.lastName) || (lhs.firstName != rhs.firstName))
		return false;
	else
		return true;
}

// less than operator: used by multiset to insert elements in order
bool operator<(const Card& lhs, const Card& rhs) {

	if (lhs.lastName < rhs.lastName)
		return true;
	else if (lhs.lastName == rhs.lastName) {
		if (lhs.firstName < rhs.firstName)
			return true;
	}
	return false;
}

std::ostream& Card::show(std::ostream& os) const {

	os	<< lastName << ", " << firstName << "  " 
		<< occupation << ": " << address << ", "
		<< phoneNumber << std::endl;
	return os;
}

void Card::setFirstName(const std::string& in) {

	firstName = in;
}

void Card::setLastName(const std::string& in) {

	lastName = in;
}

void Card::setOccupation(const std::string& in) {

	occupation = in;
}

void Card::setAddress(const std::string& in) {

	address = in;
}

void Card::setPhoneNumber(const std::string& in) {

	phoneNumber = in;
}

