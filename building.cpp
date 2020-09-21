#include <iostream> 
#include <building.h>

int Building::unique_id = 0;

void Building::swap_residents(Building& other) {
	Resident* tmp = other.resident_;
	other.resident_ = resident_;
	resident_ = tmp;	
}

Building::Building() : id_(unique_id), resident_(Resident[1]) {
	std::cout << "Building::Building()" << " At " << this << std::endl;
	unique_id++;
}

Building::Building(int hab) : id_(unique_id), resident_(Resident[hab]) {
        std::cout << "Building::Building()" << " At " << this << std::endl;
	for (int i = 0 ; i < resident_.size(); i++){
		Resident* neo_res = new Resident;
		resident_[i] = neo_res;
		delete neo_res;
	}

        unique_id++;
}


Building::~Building() {
	delete[] resident_;
        resident_=nullptr;
	std::cout << "~Building(" << id_ << ") At " << this << std::endl;

}

std::ostream& operator << (std::ostream& out, const Building& rhs){
	out << "Building, id: " << rhs.id_ << " at " << &rhs << std::endl;
	return out;
}


Building& Building::operator=(const Building& rhs){
	std::cout << "Building::assignement from"
		<< &rhs << ")" << rhs.id_ 
		<< ") to this at" << this << std::endl;
	if (this != &rhs){
	//Cleanup
	delete resident_;
	//Copy
	id_ = rhs.id_;
	resident_ = new Resident ( *rhs.resident_);
	}
	return *this;


}



