/**
 *  Lightweight unit-testing tool
 *
 */

#ifndef TESTING_H_
#define TESTING_H_

// using standard exceptions
#include <iostream>
#include <exception>
#include <typeinfo.h>

/**
 * \def THROW(M)
 * Макрос, который выбрасывает исключения с именем текущего класса, метода и сообщением об ошибке
 */
#define THROW(M) throw TestException(typeid(this).name(), __FUNCTION__ , M)

/**
 * \def CHECK(EXPR,M)
 * Тестирования выражения EXPR на истинность. Если оно ложно, выбрасывается исключение.
 * \param EXPR тестируемое выражение
 * \param M сообщение об ошибке
 */
#define CHECK(EXPR,M) if(!(EXPR)) { std::cout << "<TEST FAIL> "; throw TestException(typeid(this).name(), __FUNCTION__ , M); }

/**
 * Класс исключения для удобства тестирования
 */
	class TestException: public std::exception
	{
	public:
		TestException();
		TestException(std::string objectname, std::string method, std::string mes){
		  info = "[" + objectname + "." + method + "] " +  mes;
		}
		~TestException() throw(){
		}
	   virtual const char* what() const throw()
	   {
		 return info.c_str();
	   }
	private:
	  std::string info;
	};


#endif /* TESTING_H_ */
