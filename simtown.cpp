#include <iostream> 
#include <building.h>
#include <dynarray.h>

void print_street(std::ostream& out ,const DynArray<Building*>& street){
	for (int ib=0; ib < street.size(); ++ib)
	{
		if (street[ib] == nullptr) continue;
			out << "-- " << street[ib] << ", identifier = " << street[ib]->identifier() << "\n";
	}
	out << std::endl;
}



void shuffle_resident (DynArray<Building*>& street){
        int med_size = street.size() /2;
	for (int ileft = med_size-1 ; ileft> med_size ; --ileft) {
        	street[ileft]->swap_residents(*street[street.size()-ileft-1]);

}
}



int main ( int argc, char** argv){ 
	std::cout << "Combien de bâtiments voulez-vous créer?" << std::endl;
	int street_length = 0;
	std::cin >> street_length;
	DynArray<Building*> street(street_length);
	Building(4);

	for (int ib=0; ib < street_length;++ib) {
		Building* current_building= new Building;
		street[ib] = current_building;
		delete current_building;
	}

	print_street(std::cout,street);
	shuffle_resident(street);
	print_street(std::cout,street);
	return 0 ; //Normal termination
}
