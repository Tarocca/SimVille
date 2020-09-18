#ifndef dyn_array_h
#define dyn_array_h

#include <iostream>
#include <assert.h>

template <class T> class DynArray {

	public:
		DynArray(int size);
		~DynArray();

		T& operator[] (int index);
		const T& operator[](int index) const;
		const T& operator=(const DynArray<T>& other) const;
		void push_back(T elmt);
		const int size() const;
	private:
		void copy(const DynArray<T>& other);
	        int capacity_;	
		int size_;
		T* mach_;

};

template <class T> DynArray<T>::DynArray(int size): size_(size), mach_(new T[size]) {
	
	std::cout << "DynArray<T>::DynArray(" << size_ << ")" << std::endl;

}

template <class T> DynArray<T>::~DynArray(){
	std::cout << "Dyn has been : destroyed" << std::endl;
	delete[] mach_;

}

template <class T> void DynArray<T>::copy(const DynArray<T>& other) {
	size_ = other.size_;
	delete[] mach_;
	mach_ = new T[other.size_];
	for (int ia=0; ia < size_; ia++){
	mach_[ia] = other.mach_[ia];
	std::cout << "Un clone se tient maintenant à cette place" << std::endl;
	}


}
 
template <class T> void DynArray<T>::push_back(T elmt){
	T* tab = nullptr;
	if (size_ == capacity_){
		tab = new T[2*size_];
		capacity_ = 2 * size_;
		for (int i=0; i<size_; i++){
                	tab[i] = mach_[i];
		}
		delete[] mach_;
                mach_ = tab;
                delete[] tab;

                }
	tab[size_+1] = elmt;
	size_ +=1;
	std::cout << "Un élément à été ajouté a la liste" << std::endl;
	}


template <class T> const int DynArray<T>::size() const{
	
	return size_;
}

template <class T> const T& DynArray<T>::operator[](int index) const{
	assert(index >=0 && index < size_);
	return mach_[index];
 
}


template <class T> const T& DynArray<T>::operator=(const DynArray<T>& other) const{
	
	size_ = other.size_;
	
	for (int ia=0; ia < size_; ia++){
		mach_[ia] = other.mach_[ia];
        }


}


#endif 
