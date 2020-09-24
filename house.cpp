#include <house.h>


House::House() : Building(4)
{

}

House::~House(){

}

void House::swap_residents(House& other) {
        Resident* tmp = other.Building::get_resident();
        other.Building::set_resident(Building::get_resident());
	Building::set_resident( tmp);
}
