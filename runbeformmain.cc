#include <iostream>

int x = [](int a){
	std::cout << "initialize x before main func\n" << std::endl;
	return a;
	}(10);

int main(){
	std::cout << "x is " << x << std::endl;
	return 0;
}
