#define USE_DOUBLE
#include "hsm.hpp"
#include "iostream"
int main() {
	hsm::Point3<int> p1;
	hsm::Point3<float> p2(0.003, -0.005, 9.3f);
	hsm::Point3<float> p3 = hsm::Point3<float>(1.58, 9.96, -99.2f);
	hsm::Point3<float> p4 = hsm::Point3<float>(1.58, 9.96, -99.2f);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p3.distance(p2) << std::endl;
	std::cout << p3.floor() << std::endl;
	std::cout << p3.ceil() << std::endl;
	std::cout << p2.abs() << std::endl;
	std::cout << p2.lerp(p3,0.5f) << std::endl;
	std::cout << p3*5 << std::endl;
	std::cout << p3*1.23 << std::endl;
	std::cout << p3*0 << std::endl;
	std::cout << p3/5 << std::endl;
	std::cout << p3/5.24 << std::endl;
	std::cout << p3[0] << std::endl;
	std::cout << p3[1] << std::endl;
	std::cout << -p3 << std::endl;
	std::cout << (p3-p2).x << std::endl;
	std::cout << (p3-p2).y << std::endl;
	if(p3 == p4)std::cout << "1" << std::endl;
	if(p3 != p2)std::cout << "2" << std::endl;

	hsm::Vector3<float>v1(0.0036f, -96.5f, 2);
	hsm::Vector3<float>v2(1.5f, 9.6f, 3);
	hsm::Vector3<float>x(45.5f,0,0);
	hsm::Vector3<float>y(0,56.0f,0);
	std::cout << v1.length() << std::endl;
	std::cout << v1.abs() << std::endl;
	std::cout << v1.normalize() << std::endl;
	std::cout << dot(v1,v2) << std::endl;
	std::cout << cross(x,y) << std::endl;
	system("pause");
	return 0;
}