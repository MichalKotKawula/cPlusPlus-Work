
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>


namespace sdds{

	template<typename T>
	class Collection{
		// the name of the collection;
		std::string collectName;

		//a dynamically allocated array of items T
		T* itmArr;

		// the size of the array 
		size_t arrSize;

		//  pointer to a function that returns void
		void (*myObserver)(const Collection<T>&, const T&);

	public:

		// sets the name of the collection to the string referred to by the parameter and sets all other attributes to their default value
		Collection(std::string name){
			collectName = name;
			itmArr = nullptr;
			myObserver = nullptr;
			arrSize = 0;
		}

		// destructor 
		~Collection(){
			if (itmArr != nullptr){
				delete[] itmArr;
				itmArr = nullptr;
			}
		}

		//this class doesn't support any copy operations; delete all of them.
		Collection<T>& operator=(const Collection<T>&) = delete;
		Collection<T>& operator=(Collection<T>&&) = delete;

		//  a query that returns the name of the collection.
		const std::string& name() const{return collectName;}

		// a query that returns the number of items in the collection.
		size_t size() const{return arrSize;}

		//  stores the address of the callback function (observer) into an attribute.  
		void setObserver(void (*observer)(const Collection<T>&, const T&)){myObserver = observer;}

		// adds a copy of item to the collection, only if the collection doesn't contain an item with the same title.
		Collection<T>& operator+=(const T& item)
		{
			bool regist = true;

			for (size_t i = 0; i < arrSize; i++){
				if (itmArr[i].title() == item.title()){
					regist = false;
				}
			}

			if (regist){
				T* temporary = new T[arrSize + 1];
				for (size_t i = 0; i < arrSize; i++){
					temporary[i] = itmArr[i];
				}
				++arrSize;
				delete[] itmArr;
				itmArr = temporary;
				itmArr[arrSize - 1] = item;

				if (myObserver != nullptr){
					myObserver(*this, item);
				}
			}
			return *this;
		}

		// returns the item at index idx.
		T& operator[](size_t idx) const{
			if (idx >= arrSize || idx < 0){
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(arrSize) + "] items.");
			}
			else{
				return itmArr[idx];
			}
		}

		// returns the address of the item with the title title (type T has a member function called title()
		T* operator[](std::string title) const{

			for (size_t i = 0; i < arrSize; ++i){
				if (itmArr[i].title() == title){
					return &itmArr[i];
				}
			}
			return nullptr;
		}
	};

	template<typename T>
	//overload the insertion operator to insert the content of a Collection object into an ostream object.
	std::ostream& operator <<(std::ostream& os, const Collection<T>& pas)	{

		for (size_t i = 0; i < pas.size(); ++i){
			os << pas[i];
		}
		return os;
	}
}
#endif
