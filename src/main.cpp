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
	std::cout << p3.Distance(p2) << std::endl;
	std::cout << p3.Floor() << std::endl;
	std::cout << p3.Ceil() << std::endl;
	std::cout << p2.Abs() << std::endl;
	std::cout << p2.Lerp(p3,0.5f) << std::endl;
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

	std::cout << "***********************" << std::endl;
	hsm::Vector3<float>v1(0.0036f, -96.5f, 2);
	hsm::Vector3<float>v2(1.5f, 9.6f, 3);
	hsm::Vector3<float>x(45.5f,0,0);
	hsm::Vector3<float>y(0,56.0f,0);
	std::cout << v1.Length() << std::endl;
	std::cout << v1.Abs() << std::endl;
	std::cout << v1.Normalize() << std::endl;
	std::cout << Dot(v1,v2) << std::endl;
	std::cout << Cross(x,y) << std::endl;

	std::cout << "***********************" << std::endl;
	hsm::Matrix4x4 mat;
	hsm::Matrix4x4 mat2 = hsm::Matrix4x4(1.0f, 0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f, 5.0f, 0.0f, 0.0f, 1.0f, 6.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	hsm::Matrix4x4 matInverse = mat2.Inverse();
	if (mat == mat2 * matInverse) std::cout << "yess!!!" << std::endl;
	else std::cout << mat2 * matInverse << std::endl;
	std::cout << matInverse << std::endl;

	std::cout << "***********************" << std::endl;
	hsm::Matrix4x4 rotateZ90 = hsm::Rotate(hsm::Vector3f(0.0f, 0.0f, 1.0f), 90);
	hsm::Matrix4x4 rotateZ90_2 = hsm::RotateZ(90);
	std::cout << rotateZ90 << std::endl;
	std::cout << rotateZ90_2 << std::endl;
	if (rotateZ90_2 == rotateZ90) std::cout << "yess2!!!" << std::endl;

	std::cout << "***********************" << std::endl;
	hsm::Matrix4x4 viewMat = hsm::GetPerspectiveMatrix(1920.0f / 1080.0f, 175, 0.1f, 1000.0f);
	std::cout << viewMat << std::endl;

	system("pause");
	return 0;
}