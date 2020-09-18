#include <iostream> 
#include <resident.h>

Resident::Resident() : wealth_(100 + rand()% 901){
        std::cout << "Resident::Resident() wealth " << wealth_ << " at " << this << std::endl;

}

Resident::~Resident() {

}

std::ostream& operator << (std::ostream& out ,const Resident& rhs){
	out << "Residents,  wealth =" << rhs.wealth_ << " at " << &rhs << std::endl;
	return out;

}

