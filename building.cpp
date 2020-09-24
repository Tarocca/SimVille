#include <iostream> 
#include <building.h>

int Building::unique_id = 0;
Building::Building() : id_(unique_id), resident_(new Resident[1]) {
	std::cout << "Building::Building()" << " At " << this << std::endl;
	unique_id++;
}
Building::~Building() {
	delete[] resident_;
        resident_=nullptr;
	std::cout << "~Building(" << id_ << ") At " << this << std::endl;

}


Building::Building(int hab) : id_(unique_id), resident_(new Resident[hab]) {
	
	std::cout << "Building::Building()" << " At " << this << " with " << hab << " habitants."<< std::endl;
	unique_id++;

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

Resident* Building::get_resident(){
	return resident_;

}

void Building::set_resident(Resident* res){

	resident_ = res;


}
