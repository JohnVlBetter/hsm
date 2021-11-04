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

	bool operator == (const Point2<T>& p) const {
		return x == p.x && y == p.y;
	}

	bool operator != (const Point2<T>& p) const {
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

	Point2<T> operator + (const Point2<T>& p) const {
		return Point2<T>(x + p.x, y + p.y);
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

	Float distanceSquared(const Point2<T>& p) const { 
		return std::pow(x - p.x, 2) + std::pow(y - p.y, 2);
	}
	Float distance(const Point2<T>& p) const { return std::sqrt(distanceSquared(p)); }

	Point2<T> floor() const { return Point2<T>(std::floor(x), std::floor(y)); }
	Point2<T> ceil() const { return Point2<T>(std::ceil(x), std::ceil(y)); }
	Point2<T> abs() const { return Point2<T>(std::abs(x), std::abs(y)); }

	Point2<T> lerp(const Point2<T>& p, Float t) const { return (1 - t)*(*this) + t * p; }

	//public data
	T x, y;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const Point2<T>& p) {
	o << '[' << p.x << ',' << p.y << ']';
	return o;
}

template<typename T, typename U>
inline Point2<T> operator * (U n, const Point2<T>& v) {
	return v * n;
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

	bool operator == (const Point3<T>& p) const {
		return x == p.x && y == p.y && z == p.z;
	}

	bool operator != (const Point3<T>& p) const {
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
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		return z;
	}

	Point3<T> operator + (const Vector3<T>& v) const {
		return Point3<T>(x + v.x, y + v.y, z + v.z);
	}

	Point3<T> operator + (const Point3<T>& p) const {
		return Point3<T>(x + p.x, y + p.y, z + p.z);
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

	Float distanceSquared(const Point3<T>& p) const {
		return std::pow(x - p.x, 2) + std::pow(y - p.y, 2) + std::pow(z - p.z, 2);
	}
	Float distance(const Point3<T>& p) const { return std::sqrt(distanceSquared(p)); }

	Point3<T> floor() const { return Point3<T>(std::floor(x), std::floor(y), std::floor(z)); }
	Point3<T> ceil() const { return Point3<T>(std::ceil(x), std::ceil(y), std::ceil(z)); }
	Point3<T> abs() const { return Point3<T>(std::abs(x), std::abs(y), std::abs(z)); }

	Point3<T> lerp(const Point3<T>& p, Float t) const { return (1 - t)*(*this) + t * p; }

	//public data
	T x, y, z;
};

template<typename T>
std::ostream & operator << (std::ostream &o, const Point3<T>& p) {
	o << '[' << p.x << ',' << p.y << ',' << p.z << ']';
	return o;
}

template<typename T, typename U>
inline Point3<T> operator * (U n, const Point3<T>& v) {
	return v * n;
}

//two-dimensional vector
template<typename T>
class Vector2 {
public:
	//public methods
	Vector2() :x(0), y(0) {}
	Vector2(T xx, T yy) :x(xx), y(yy) {}

	template<typename S>
	explicit Vector2(const Point2<T>& p) {
		x = (T)p.x;
		y = (T)p.y;
	}

	template<typename S>
	explicit Vector2(const Vector2<T>& v) {
		x = (T)v.x;
		y = (T)v.y;
	}

	bool hasNaN() const { return isNaN(x) || isNaN(y); }

	Vector2<T>& operator = (const Vector2<T>& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	bool operator == (const Vector2<T>& v) const {
		return x == v.x && y == v.y;
	}

	bool operator != (const Vector2<T>& v) const {
		return x != v.x || y != v.y;
	}

	Vector2<T> operator -() const {
		return Vector2<T>(-x, -y);
	}

	T operator [](int i) const {
		assert(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	T& operator [](int i) {
		assert(i >= 0 && i <= 1);
		if (i == 0) return x;
		return y;
	}

	Vector2<T> operator + (const Vector2<T>& v) const {
		return Point3<T>(x + v.x, y + v.y);
	}

	Vector2<T>& operator += (const Vector2<T>& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2<T> operator - (const Vector2<T>& v) const {
		return Point3<T>(x - v.x, y - v.y);
	}

	Vector2<T>& operator -= (const Vector2<T>& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	template<typename S>
	Vector2<T> operator *(S n) const {
		return Vector2<T>(n * x, n * y);
	}

	template<typename S>
	Vector2<T>& operator *= (S n) {
		x *= n;
		y *= n;
		return *this;
	}

	template<typename S>
	Vector2<T> operator / (S n) const {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		return Vector2<T>(x * inverse, y * inverse);
	}

	template<typename S>
	Vector2<T>& operator /= (S n) {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		x *= inverse;
		y *= inverse;
		return *this;
	}

	Float lengthSquared()const { return x * x + y * y; }
	Float length()const { return std::sqrt(lengthSquared()); }

	Vector2<T> abs() const { return Vector2<T>(std::abs(x), std::abs(y)); }
	Vector2<T> normalize() const { return *this / length(); }

	//public data
	T x, y;
};

template<typename T>
inline std::ostream& operator << (std::ostream& o, const Vector2<T>& v) {
	o << '[' << v.x << ',' << v.y << ']';
	return o;
}

template<typename T, typename U>
inline Vector2<T> operator * (U n, const Vector2<T>& v) {
	return v * n;
}

template<typename T>
inline Float dot(const Vector2<T>& v1, const Vector2<T>& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

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