#include <building.h>

class Hut : private Building {
	public:
		Hut();
		~Hut();
		void swap_residents(Hut& other);
};
