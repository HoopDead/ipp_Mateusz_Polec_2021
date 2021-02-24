#pragma once

#include <iostream>
#include <utility>

/*
* template LOG (one argument)
* Print the given value in console
* @Param: const reference to any variable type - value
* @Return: -
* Can be called by using Log(variable to print)
* Is noexcept because function does not throw any error + it's only test function
*/
template<typename T>
void Log(const T& value) noexcept {
	std::cout << value << "\n";
}

/*
* template LOG ALL (n-arguments)
* Print the given values in console
* @Param const reference to any number of variables types 
* Can ba called by using LogAll(variable to print, variable to print 2, variable to print 3, ...,  variable to print n)
* Is noexcept because function does not throw any error + it's only test function
*/
template<typename ...Args>
void LogAll(Args&&... args) noexcept
{
	((std::cout << std::forward<Args>(args) << "\n"), ...);
}