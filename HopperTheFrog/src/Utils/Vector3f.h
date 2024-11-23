#pragma once

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI


class Vector3f {

public:
	float x, y, z;
	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);

	Vector3f operator+(Vector3f& v);
	Vector3f operator-(Vector3f& v);
	Vector3f operator-();
	Vector3f operator*(float n);
	Vector3f operator/(float n);
	Vector3f operator+=(Vector3f& v);
	Vector3f operator-=(Vector3f& v);
	Vector3f operator*=(float n);
	Vector3f operator/=(float n);
	Vector3f unit();
	Vector3f cross(Vector3f v);
	float dot(Vector3f v);
	//Vector3f rotate(float angle, Vector3f axis);
	//Vector3f rotateX(float angle);
	//Vector3f rotateY(float angle);
	//Vector3f rotateZ(float angle);

};