/*
 * test.hpp
 *
 *  Created on: 24 окт. 2015 г.
 *      Author: mmwind
 */

#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include "testing.h"
#include "Timsort.h"

/**
 * Организуем внутриклассовое тестирование для Timsort
 */
class Test: public Timsort {
public:
	void AddTestData(){
			std::vector<int> v;
		    v.push_back(1);
		    v.push_back(2);
		    v.push_back(3);
		    v.push_back(2);
		    v.push_back(5);
		    v.push_back(1);
		    setArray(&v);
	}

	void test_getRunEnd(){

		std::vector<int>::iterator it = Array->begin();
		std::pair< std::vector<int>::iterator, bool> e = getRunEnd(it);

		std::cout << "Index: " <<(int)(e.first - it) << std::endl;
		std::cout << "Value: " << *(e.first) << std::endl;

	    CHECK( (int)((e.first) - it) == 2, "Wrong element index" );
	}

	Test(){
		std::cout << " <Timsort testing>" << std::endl;
		try{

			AddTestData();
			test_getRunEnd();

		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << " <Timsort testing end>" << std::endl;
	}
};


#endif /* TEST_HPP_ */
