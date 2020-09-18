#include <iostream> 


class Resident{
        public:
                Resident();
                ~Resident();
                int wealth() const {return wealth_;}
		friend std::ostream& operator<<(std::ostream& out, const Resident& rhs);
        private:
                int wealth_;


};

Resident::Resident() : wealth_(100 + rand()% 901){
        std::cout << "Resident::Resident() wealth " << wealth_ << " at " << this << std::endl;

}

Resident::~Resident() {

}

std::ostream& operator << (std::ostream& out ,const Resident& rhs){
	out << "Residents,  wealth =" << rhs.wealth_ << " at " << &rhs << std::endl;
	return out;

}

class Building {
public: 
	Building (int id);
	Building();
	~Building();
	Building& operator=(const Building& rhs);
	inline int identifier() const {return id_;}
	void swap_residents(Building& other);
	friend std::ostream& operator<<(std::ostream& out, const Building& rhs);

private:
	static int unique_id;
	int id_;
	Resident* resident_;

};

int Building::unique_id = 0;

void Building::swap_residents(Building& other) {
	Resident* tmp = other.resident_;
	other.resident_ = resident_;
	resident_ = tmp;	
}

Building::Building() : id_(unique_id), resident_(new Resident) {
	std::cout << "Building::Building()" << " At " << this << std::endl;
	unique_id++;
}

void print_street(std::ostream& out ,const Building* const* street ,int street_size){
	for (int ib=0; ib < street_size; ++ib)
	{
		if (street[ib] == nullptr) continue;
		out << "-- " << street[ib] << ", identifier = " << street[ib]->identifier() << "\n";
	}
	out << std::endl;
}

Building::~Building() {
	delete resident_;
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
	id = rhs.id_;
	resident_ = new Resident ( *rhs.resident_);
	}
	return *this;


}


void shuffle_resident (Building** street, int street_length){
        int med_size = street_length /2;
	for (int ileft = med_size-1 ; ileft> med_size ; --ileft) {
        	street[ileft]->swap_residents(*street[street_length-ileft-1]);

}
}



int main ( int argc, char** argv){ 
	std::cout << "Combien de bâtiments voulez-vous créer?" << std::endl;
	int street_length = 0;
	std::cin >> street_length;
	Building** street = new Building*[street_length];
	//Building street[street_length];
        //Building* street  = new Building [street_length];

	for (int ib=0; ib < street_length;++ib) {
		//Building current_building();
		street[ib] = new Building();
		std::cout << " Added building " << street[ib]-> identifier() << std::endl;
	}
	shuffle_resident(street, street_length);
	print_street(std::cout,street, street_length);
	for (int ib=0;ib < street_length; ++ib){
	delete street[ib];
	}
	delete[] street;	
	return 0 ; //Normal termination
}
