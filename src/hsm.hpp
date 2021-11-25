#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef HSM_H
#define HSM_H

#include <assert.h>
#include <iterator>
#include <iostream>

//#define USE_DOUBLE
#ifdef USE_DOUBLE
	typedef double Float;
#else
	typedef float Float;
#endif

namespace hsm {

static constexpr Float Sqrt2 = 1.41421356237309504880;
static constexpr Float Pi    = 3.14159265358979323846;
static constexpr Float InvPi = 0.31830988618379067154;

template<typename T>
inline bool isNaN(const T t) { return std::isnan(t); }
template<>
inline bool isNaN(const int t) { return false; }

inline Float Radians(Float degree) { return (Pi / 180) * degree; }

inline Float Degrees(Float radian) { return (180 / Pi) * radian; }

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

	bool HasNaN() const {
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

	Float DistanceSquared(const Point2<T>& p) const { 
		return std::pow(x - p.x, 2) + std::pow(y - p.y, 2);
	}
	Float Distance(const Point2<T>& p) const { return std::sqrt(DistanceSquared(p)); }

	Point2<T> Floor() const { return Point2<T>(std::floor(x), std::floor(y)); }
	Point2<T> Ceil() const { return Point2<T>(std::ceil(x), std::ceil(y)); }
	Point2<T> Abs() const { return Point2<T>(std::abs(x), std::abs(y)); }

	Point2<T> Lerp(const Point2<T>& p, Float t) const { return (1 - t)*(*this) + t * p; }

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

	bool HasNaN() const {
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

	Float DistanceSquared(const Point3<T>& p) const {
		return std::pow(x - p.x, 2) + std::pow(y - p.y, 2) + std::pow(z - p.z, 2);
	}
	Float Distance(const Point3<T>& p) const { return std::sqrt(DistanceSquared(p)); }

	Point3<T> Floor() const { return Point3<T>(std::floor(x), std::floor(y), std::floor(z)); }
	Point3<T> Ceil() const { return Point3<T>(std::ceil(x), std::ceil(y), std::ceil(z)); }
	Point3<T> Abs() const { return Point3<T>(std::abs(x), std::abs(y), std::abs(z)); }

	Point3<T> Lerp(const Point3<T>& p, Float t) const { return (1 - t)*(*this) + t * p; }

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

	bool HasNaN() const { return isNaN(x) || isNaN(y); }

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

	Float LengthSquared()const { return x * x + y * y; }
	Float Length()const { return std::sqrt(LengthSquared()); }

	Vector2<T> Abs() const { return Vector2<T>(std::abs(x), std::abs(y)); }
	Vector2<T> Normalize() const { return *this / Length(); }

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
inline Float Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

//three-dimensional vector
template<typename T>
class Vector3 {
public:
	//public methods
	Vector3() :x(0), y(0), z(0) {}
	Vector3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) {} 

	template<typename S>
	explicit Vector3(const Point3<T>& p) {
		x = (T)p.x;
		y = (T)p.y;
		z = (T)p.z;
	}

	template<typename S>
	explicit Vector3(const Vector3<T>& v) {
		x = (T)v.x;
		y = (T)v.y;
		z = (T)v.z;
	}

	bool HasNaN() const { return isNaN(x) || isNaN(y) || isNaN(z); }

	Vector3<T>& operator = (const Vector3<T>& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	bool operator == (const Vector3<T>& v) const {
		return x == v.x && y == v.y && z == v.z;
	}

	bool operator != (const Vector3<T>& v) const {
		return x != v.x || y != v.y || z != v.z;
	}

	Vector3<T> operator -() const {
		return Vector3<T>(-x, -y, -z);
	}

	T operator [](int i) const {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}

	T& operator [](int i) {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		if (i == 1) return y;
		return z;
	}

	Vector3<T> operator + (const Vector3<T>& v) const {
		return Point3<T>(x + v.x, y + v.y, z + v.z);
	}

	Vector3<T>& operator += (const Vector3<T>& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3<T> operator - (const Vector3<T>& v) const {
		return Point3<T>(x - v.x, y - v.y, z - v.z);
	}

	Vector3<T>& operator -= (const Vector3<T>& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	template<typename S>
	Vector3<T> operator *(S n) const {
		return Vector3<T>(n * x, n * y, n * z);
	}

	template<typename S>
	Vector3<T>& operator *= (S n) {
		x *= n;
		y *= n;
		z *= n;
		return *this;
	}

	template<typename S>
	Vector3<T> operator / (S n) const {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		return Vector3<T>(x * inverse, y * inverse, z * inverse);
	}

	template<typename S>
	Vector3<T>& operator /= (S n) {
		assert(n != 0);
		Float inverse = (Float)1 / n;
		x *= inverse;
		y *= inverse;
		z *= inverse;
		return *this;
	}

	Float LengthSquared()const { return x * x + y * y + z * z; }
	Float Length()const { return std::sqrt(LengthSquared()); }

	Vector3<T> Abs() const { return Vector3<T>(std::abs(x), std::abs(y), std::abs(z)); }
	Vector3<T> Normalize() const { return *this / Length(); }

	//public data
	T x, y, z;
};

template<typename T>
inline std::ostream& operator << (std::ostream& o, const Vector3<T>& v) {
	o << '[' << v.x << ',' << v.y << ',' << v.z << ']';
	return o;
}

template<typename T, typename U>
inline Vector3<T> operator * (U n, const Vector3<T>& v) {
	return v * n;
}

template<typename T>
inline Float Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
inline Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) {
	return Vector3<T>((v1.y * v2.z) - (v1.z * v2.y), 
		(v1.z * v2.x) - (v1.x * v2.z), (v1.x * v2.y) - (v1.y * v2.x));
}

typedef Vector3<Float> Vector3f;
typedef Vector3<int> Vector3i;
typedef Vector2<Float> Vector2f;
typedef Vector2<int> Vector2i;
typedef Point2<Float> Point2f;
typedef Point2<int> Point2i;
typedef Point3<Float> Point3f;
typedef Point3<int> Point3i;

//Matrix 4x4
class Matrix4x4 {
public:
	//public methods
	Matrix4x4() {
		data[0][0] = data[1][1] = data[2][2] = data[3][3] = 1.0f;
		data[0][1] = data[0][2] = data[0][3] = data[1][0] =
		data[1][2] = data[1][3] = data[2][0] = data[2][1] =
		data[2][3] = data[3][1] = data[3][2] = data[3][0] = 0.0f;
	}

	Matrix4x4(Float d00, Float d01, Float d02, Float d03, Float d10, Float d11, Float d12, Float d13,
		Float d20, Float d21, Float d22, Float d23, Float d30, Float d31, Float d32, Float d33) {
		data[0][0] = d00;
		data[0][1] = d01;
		data[0][2] = d02;
		data[0][3] = d03;
		data[1][0] = d10;
		data[1][1] = d11;
		data[1][2] = d12;
		data[1][3] = d13;
		data[2][0] = d20;
		data[2][1] = d21;
		data[2][2] = d22;
		data[2][3] = d23;
		data[3][0] = d30;
		data[3][1] = d31;
		data[3][2] = d32;
		data[3][3] = d33;
	}

	Matrix4x4(Float mat[4][4]) {
		memcpy(data, mat, sizeof(Float) * 16);
	}

	bool operator == (const Matrix4x4& mat) const {
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				if (data[i][j] != mat.data[i][j]) return false;
		return true;
	}

	bool operator != (const Matrix4x4& mat) const {
		for (int i = 0; i <= 3; ++i)
			for (int j = 0; j <= 3; ++j)
				if (data[i][j] != mat.data[i][j]) return true;
		return false;
	}

	Matrix4x4 operator * (const Matrix4x4& mat) const {
		Matrix4x4 result;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				result.data[i][j] = data[i][0] * mat.data[0][j] + data[i][1] * mat.data[1][j] +
					data[i][2] * mat.data[2][j] + data[i][3] * mat.data[3][j];
		return result;
	}

	Matrix4x4 Transpose() const {
		return Matrix4x4(data[0][0], data[1][0], data[2][0], data[3][0],
			data[0][1], data[1][1], data[2][1], data[3][1],
			data[0][2], data[1][2], data[2][2], data[3][2],
			data[0][3], data[1][3], data[2][3], data[3][3]);
	}

	Matrix4x4 Inverse() const {
		int indexC[4], indexR[4];
		int ipiv[4] = { 0, 0, 0, 0 };
		Float inv[4][4];
		memcpy(inv, data, 4 * 4 * sizeof(Float));
		for (int i = 0; i < 4; i++) {
			int irow = 0, icol = 0;
			Float big = 0.f;
			for (int j = 0; j < 4; j++) {
				if (ipiv[j] != 1) {
					for (int k = 0; k < 4; k++) {
						if (ipiv[k] == 0) {
							if (std::abs(inv[j][k]) >= big) {
								big = Float(std::abs(inv[j][k]));
								irow = j;
								icol = k;
							}
						}
						else if (ipiv[k] > 1)
							std::cout << "Singular matrix!" << std::endl;
					}
				}
			}
			++ipiv[icol];
			if (irow != icol) {
				for (int k = 0; k < 4; ++k) std::swap(inv[irow][k], inv[icol][k]);
			}
			indexR[i] = irow;
			indexC[i] = icol;
			if (inv[icol][icol] == 0.f) std::cout << "Singular matrix!" << std::endl;

			Float pivinv = 1. / inv[icol][icol];
			inv[icol][icol] = 1.;
			for (int j = 0; j < 4; j++) inv[icol][j] *= pivinv;

			for (int j = 0; j < 4; j++) {
				if (j != icol) {
					Float save = inv[j][icol];
					inv[j][icol] = 0;
					for (int k = 0; k < 4; k++) inv[j][k] -= inv[icol][k] * save;
				}
			}
		}

		for (int j = 3; j >= 0; j--) {
			if (indexR[j] != indexC[j]) {
				for (int k = 0; k < 4; k++)
					std::swap(inv[k][indexR[j]], inv[k][indexC[j]]);
			}
		}
		return Matrix4x4(inv);
	}

	bool IsIdentity() const {
		return (data[0][0] == 1.f && data[0][1] == 0.f && data[0][2] == 0.f && data[0][3] == 0.f && 
				data[1][0] == 0.f && data[1][1] == 1.f && data[1][2] == 0.f && data[1][3] == 0.f && 
				data[2][0] == 0.f && data[2][1] == 0.f && data[2][2] == 1.f && data[2][3] == 0.f &&
				data[3][0] == 0.f && data[3][1] == 0.f && data[3][2] == 0.f && data[3][3] == 1.f);
	}

	//public data
	Float data[4][4];
};

inline std::ostream& operator << (std::ostream& o, const Matrix4x4& mat) {
	o << "[ " << mat.data[0][0] << " , " << mat.data[0][1] << " , " << mat.data[0][2] << " , " << mat.data[0][3] << " ]\n" <<
		 "[ " << mat.data[1][0] << " , " << mat.data[1][1] << " , " << mat.data[1][2] << " , " << mat.data[1][3] << " ]\n" <<
		 "[ " << mat.data[2][0] << " , " << mat.data[2][1] << " , " << mat.data[2][2] << " , " << mat.data[2][3] << " ]\n" <<
		 "[ " << mat.data[3][0] << " , " << mat.data[3][1] << " , " << mat.data[3][2] << " , " << mat.data[3][3] << " ]"   <<
		 std::endl;
	return o;
}

Matrix4x4 Translate(const Vector3f pos) {
	return Matrix4x4(1.0f, 0.0f, 0.0f, pos.x, 0.0f, 1.0f, 0.0f, pos.y,
		0.0f, 0.0f, 1.0f, pos.z, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 RotateX(Float degree) {
	Float sinTheta = std::sin(Radians(degree));
	Float cosTheta = std::cos(Radians(degree));
	return Matrix4x4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, cosTheta, -sinTheta, 0.0f,
		0.0f, sinTheta, cosTheta, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 RotateY(Float degree) {
	Float sinTheta = std::sin(Radians(degree));
	Float cosTheta = std::cos(Radians(degree));
	return Matrix4x4(cosTheta, 0.0f, sinTheta, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		-sinTheta, 0.0f, cosTheta, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 RotateZ(Float degree) {
	Float sinTheta = std::sin(Radians(degree));
	Float cosTheta = std::cos(Radians(degree));
	return Matrix4x4(cosTheta, -sinTheta, 0.0f, 0.0f, sinTheta, cosTheta, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Rotate(const Vector3f& axis, Float degree) {
	Vector3f normalizedAxis = axis.Normalize();
	Float sinTheta = std::sin(Radians(degree));
	Float cosTheta = std::cos(Radians(degree));
	return Matrix4x4(normalizedAxis.x * normalizedAxis.x + (1 - normalizedAxis.x * normalizedAxis.x) * cosTheta,
		normalizedAxis.x * normalizedAxis.y * (1 - cosTheta) - normalizedAxis.z * sinTheta,
		normalizedAxis.x * normalizedAxis.z * (1 - cosTheta) + normalizedAxis.y * sinTheta,
		0,
		normalizedAxis.x * normalizedAxis.y * (1 - cosTheta) + normalizedAxis.z * sinTheta,
		normalizedAxis.y * normalizedAxis.y + (1 - normalizedAxis.y * normalizedAxis.y) * cosTheta,
		normalizedAxis.y * normalizedAxis.z * (1 - cosTheta) - normalizedAxis.x * sinTheta,
		0,
		normalizedAxis.x * normalizedAxis.z * (1 - cosTheta) - normalizedAxis.y * sinTheta,
		normalizedAxis.y * normalizedAxis.z * (1 - cosTheta) + normalizedAxis.x * sinTheta,
		normalizedAxis.z * normalizedAxis.z + (1 - normalizedAxis.z * normalizedAxis.z) * cosTheta,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix4x4 Scale(const Vector3f scale) {
	return Matrix4x4(scale.x, 0.0f, 0.0f, 0.0f, 0.0f, scale.y, 0.0f, 0.0f,
		0.0f, 0.0f, scale.z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
}

}
#endif