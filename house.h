#include <building.h>

class House : private Building {
	public:
		House();
		~House();
		void swap_residents(House& other);
};
