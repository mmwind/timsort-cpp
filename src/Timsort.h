/*
 * Timsort.h
 *
 *  Created on: 24 окт. 2015 г.
 *      Author: mmwind
 */

#ifndef TIMSORT_H_
#define TIMSORT_H_

#include <cstdlib>
#include <vector>

class Timsort {
public:
	Timsort(){ };

	virtual ~Timsort(){ };

	void sort(){
		if(Array == NULL) {
			throw (std::bad_array_length());
		}
		minrun = getMinrun();
		for (unsigned int i = 0; i < Array->size(); i++){

		}

	}

	std::vector<int>* getArray()  {
		return Array;
	}

	void setArray(std::vector<int>* array) {
		Array = array;
	}

protected:
	std::vector<int> * Array;
	int minrun;

	int getMinrun()
	{
		int n = Array->size();
	    int r = 0;
	    while (n >= 64) {
	        r |= n & 1;
	        n >>= 1;
	    }
	    return n + r;
	}

	std::vector<int>::iterator getRunEnd(std::vector<int>::iterator first){
		std::vector<int>::iterator it = first + 1;
		while(*(it - 1) > *it && it != Array->end() ){
			it++;
		}

		while(*(it - 1) <= *it && it != Array->end() ){
			it++;
		}
		return(it - 1);
	}

};

#endif /* TIMSORT_H_ */
