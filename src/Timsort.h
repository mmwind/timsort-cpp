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

		std::vector<int>::iterator it = Array->begin();
		while(it != Array->end()){
			std::pair< std::vector<int>::iterator, bool> eit = getRunEnd(it);

			unsigned int len =  eit.first - it;
			if(len < minrun){
				eit.first = eit.first + (minrun - len);
			}

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

	/**
	 *
	 * @param first
	 * @return конец подмассива и то, как он упорядочен (true - по убыванию, дальнейшая сортировка нужна)
	 */
	std::pair< std::vector<int>::iterator, bool> getRunEnd(std::vector<int>::iterator first){

		std::pair< std::vector<int>::iterator, bool> res;

		std::vector<int>::iterator it = first + 1;
		if(*(it - 1) > *it && it != Array->end())
			res.second = true;
		else
			res.second = false;

		while(*(it - 1) > *it && it != Array->end() ){
			it++;
		}

		while(*(it - 1) <= *it && it != Array->end() ){
			it++;
		}

		res.first = it - 1;
		return(it - 1);
	}

};

#endif /* TIMSORT_H_ */
