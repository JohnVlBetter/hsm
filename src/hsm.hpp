#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef HSM_H
#define HSM_H

#include <assert.h>
#include <iterator>

//#define USE_DOUBLE
#ifdef USE_DOUBLE
	#define Float double
#else
	#define Float float
#endif

namespace hsm {

static constexpr Float Sqrt2 = 1.41421356237309504880;
static constexpr Float Pi = 3.14159265358979323846;
static constexpr Float InvPi = 0.31830988618379067154;

template<typename T>
inline bool isNaN(const T t) { return std::isnan(t); }
template<>
inline bool isNaN(const int t) { return false; }

template<typename T> class Vector2;
//two-dimensional point
template<typename T>
class Point2 {
public:
	//public methods
	Point2() :x(0), y(0) {}
	Point2(T xx, T yy) :x(xx), y(yy) {}

	template<typename S>
	explicit Point2(const Point2<S>& p) {
		x = (T)p.x;
		y = (T)p.y;
	}

	template<typename S>
	explicit Point2(const Vector2<S>& v) {
		x = (T)v.x;
		y = (T)v.y;
	}

	bool hasNaN() const {
		return isNaN(x) || isNaN(y);
	}

	Point2<T>& operator = (const Point2<T>& p) {
		x = p.x;
		y = p.y;
		return *this;
	}

	bool operator == (const Point2<T> p) const {
		return x == p.x && y == p.y;
	}

	bool operator != (const Point2<T> p) const {
		return x != p.x || y != p.y;
	}

	Point2<T> operator -() const {
		return Point2<T>(-x, -y);
	}

	T operator [](int i) const {
		assert(i == 0 || i == 1);
		if (i == 0) return x;
		return y;
	}

	T& operator [](int i) {
		assert(i == 0 || i == 1);
		if (i == 0) return x;
		return y;
	}

	Point2<T> operator + (const Vector2<T>& v) const {
		return Point2<T>(x + v.x, y + v.y);
	}

	Point2<T>& operator += (const Vector2<T>& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Point2<T> operator - (const Vector2<T>& v) const {
		return Point2<T>(x - v.x, y - v.y);
	}

	Point2<T>& operator -= (const Vector2<T>& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2<T> operator - (const Point2<T>& p) const {
		return Vector2<T>(x - p.x, y - p.y);
	}

	template<typename S>
	Point2<T> operator *(S n) const {
		return Point2<T>(n * x, n * y);
	}

	template<typename S>
	Point2<T>& operator *= (S n) {
		x *= n;
		y *= n;
		return *this;
	}

	template<typename S>
	Point2<T> operator / (S n) const {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		return Point2<T>(x * inverse, y * inverse);
	}

	template<typename S>
	Point2<T>& operator /= (S n) {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		x *= inverse;
		y *= inverse;
		return *this;
	}

	//public data
	T x, y;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const Point2<T>& p) {
	o << '[' << p.x << ',' << p.y << ']';
	return o;
}

template<typename T> class Vector3;
//three-dimensional point
template<typename T>
class Point3 {
public:
	//public methods
	Point3() :x(0), y(0), z(0) {}
	Point3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {}

	template<typename S>
	explicit Point3(const Point3<S>& p) {
		x = (T)p.x;
		y = (T)p.y;
		z = (T)p.z;
	}

	template<typename S>
	explicit Point3(const Vector3<S>& v) {
		x = (T)v.x;
		y = (T)v.y;
		z = (T)v.z;
	}

	bool hasNaN() const {
		return isNaN(x) || isNaN(y) || isNaN(z);
	}

	Point3<T>& operator = (const Point3<T>& p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}

	bool operator == (const Point3<T> p) const {
		return x == p.x && y == p.y && z == p.z;
	}

	bool operator != (const Point3<T> p) const {
		return x != p.x || y != p.y || z != p.z;
	}

	Point3<T> operator -() const {
		return Point3<T>(-x, -y, -z);
	}

	T operator [](int i) const {
		assert(i >= 0 && i <= 3);
		if (i == 0) return x;
		else if (i == 1) return y;
		return z;
	}

	T& operator [](int i) {
		assert(i >= 0 && i <= 3);
		if (i == 0) return x;
		else if (i == 1) return y;
		return z;
	}

	Point3<T> operator + (const Vector3<T>& v) const {
		return Point3<T>(x + v.x, y + v.y, z + v.z);
	}

	Point3<T>& operator += (const Vector3<T>& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Point3<T> operator - (const Vector3<T>& v) const {
		return Point3<T>(x - v.x, y - v.y, z - v.z);
	}

	Point3<T>& operator -= (const Vector3<T>& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3<T> operator - (const Point3<T>& p) const {
		return Vector3<T>(x - p.x, y - p.y, z - p.z);
	}

	template<typename S>
	Point3<T> operator *(S n) const {
		return Point3<T>(n * x, n * y, n * z);
	}

	template<typename S>
	Point3<T>& operator *= (S n) {
		x *= n;
		y *= n;
		z *= n;
		return *this;
	}

	template<typename S>
	Point3<T> operator / (S n) const {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		return Point3<T>(x * inverse, y * inverse, z * inverse);
	}

	template<typename S>
	Point3<T>& operator /= (S n) {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		x *= inverse;
		y *= inverse;
		z *= inverse;
		return *this;
	}

	//public data
	T x, y, z;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const Point3<T>& p) {
	o << '[' << p.x << ',' << p.y << ',' << p.z << ']';
	return o;
}

//two-dimensional vector
template<typename T>
class Vector2 {
public:
	//public methods
	Vector2() :x(0), y(0) {}
	Vector2(T xx, T yy) :x(xx), y(yy) {}

	//public data
	T x, y;
};

//three-dimensional vector
template<typename T>
class Vector3 {
public:
	//public methods
	Vector3() :x(0), y(0), z(0) {}
	Vector3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {}

	//public data
	T x, y, z;
};
}
#endif