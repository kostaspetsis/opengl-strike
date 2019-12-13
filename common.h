#ifndef __COMMON_H__
#define __COMMON_H__
#include <iostream>
#include <string>
#include <vector>

#define endline "\n"
#define BEGIN_BRA std::string("⎧")
#define MIDDLE_BRA std::string("⎨")
#define END_BRA std::string("⎩")
#define HIERARCHY_ARROW std::string("↳ ")
std::string operator<<(std::string s1, std::string s2);
std::string operator<<(std::string s1, float f);
std::string operator*(std::string s1, int times);
// std::string operator*(const char s1[], int times);
std::string Join(std::vector<std::string> v);
std::string StringMultiply(std::string s1, int times);
#endif // !__COMMON_H__#