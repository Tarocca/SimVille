#include <iostream> 
#include <resident.h>

class Building {
public: 
	Building (int id);
	Building();
	~Building();
	Building& operator=(const Building& rhs);
	const Resident* get_resident() const;
	void set_resident(Resident* res);
	inline int identifier() const {return id_;}
	virtual void swap_residents(Building& other){} ;
	friend std::ostream& operator<<(std::ostream& out, const Building& rhs);


private:
	static int unique_id;
	int id_;
	Resident* resident_;

};
