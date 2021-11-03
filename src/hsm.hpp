#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef HSM_H
#define HSM_H

#include <assert.h>
#include <iterator>

namespace hsm {

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
		double inverse = (double)1 / n;
		return Point2<T>(x * inverse, y * inverse);
	}

	template<typename S>
	Point2<T>& operator /= (S n) {
		assert(n != 0);
		double inverse = (double)1 / n;
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
}
#endif