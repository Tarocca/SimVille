#include <hut.h>


Hut::Hut() : Building(1)
{

}

Hut::~Hut(){

}

void Hut::swap_residents(Hut& other) {
        Resident* tmp = other.Building::get_resident();
        other.Building::set_resident(Building::get_resident);
	Building::set_resident( tmp);
}

