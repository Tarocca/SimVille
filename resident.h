#ifndef resident_h
#define resident_h
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

#endif

