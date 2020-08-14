// --------------  INFO.2680-061 C++ Programming    ------------- //
// --------------          Mark Sheehan 		    ------------- //
// --------------        Rolodex Project            ------------- //

#ifndef _CARD_H
#define _CARD_H

#include <string>
#include <iostream>

class Card {
public:
	Card() {}					    // default constructor
	Card(const std::string& fn, const std::string& ln) :
		firstName(fn), lastName(ln) {}
	Card(const Card&);				// copy constructor
	~Card() {}						// destructor

	// member functions
	std::ostream& show(std::ostream&) const;
	bool operator== (const Card&);
	// non-member functions
	friend bool operator== (const Card&, const Card&);
	friend bool operator<(const Card&, const Card&);

	// getter member functions
	inline std::string getFirstName() const { return firstName; }
	inline std::string getLastName() const { return lastName; }
	inline std::string getOccupation() const { return occupation; }
	inline std::string getAddress() const { return address; }
	inline std::string getPhoneNumber() const { return phoneNumber; }

	// setter member functions
	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setOccupation(const std::string&);
	void setAddress(const std::string&);
	void setPhoneNumber(const std::string&);

	// private member data
private:
	std::string firstName{ "" };
	std::string lastName{ "" };
	std::string occupation{ "" };
	std::string address{ "" };
	std::string phoneNumber{ "" };
};

#endif
