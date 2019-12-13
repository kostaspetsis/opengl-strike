#include "common.h"


std::string operator<<(std::string s1, std::string s2){
	return s1+=s2;
}

std::string operator<<(std::string s1, float f){
	return s1 + std::to_string(f);
}
std::string operator*(std::string s1, int times){
	std::string s("");
	for(int i = 0; i < times; i++){
		s = s+ s1;
	}
	return s;
}
std::string Join(std::vector<std::string> v){
	std::string joined;
	for(auto s : v){
		joined += s;
	}
	return joined;
}

std::string StringMultiply(std::string s1, int times){
	std::string s;
	for(int i = 0; i < times; i++){
		s += s1;
	}
	return s;
}