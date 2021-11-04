#define USE_DOUBLE
#include "hsm.hpp"
#include "iostream"
int main() {
	hsm::Point3<int> p1;
	hsm::Point3<float> p2(0.003, -0.005, -6);
	hsm::Point3<float> p3 = hsm::Point3<float>(1.58, 9.96, 0.05f);
	hsm::Point3<float> p4 = hsm::Point3<float>(1.58, 9.96, 0.05f);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p3*5 << std::endl;
	std::cout << p3*1.23 << std::endl;
	std::cout << p3*0 << std::endl;
	std::cout << p3/5 << std::endl;
	std::cout << p3/5.24 << std::endl;
	std::cout << p3[0] << std::endl;
	std::cout << p3[1] << std::endl;
	std::cout << p3[2] << std::endl;
	std::cout << -p3 << std::endl;
	std::cout << (p3-p2).x << std::endl;
	std::cout << (p3-p2).y << std::endl;
	if(p3 == p4)std::cout << "1" << std::endl;
	if(p3 != p2)std::cout << "2" << std::endl;
	system("pause");
	return 0;
}