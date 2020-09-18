#include <iostream> 
#include <resident.h>

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
