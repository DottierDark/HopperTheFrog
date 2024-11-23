#include <Utils/Vector3f.h>


Vector3f::Vector3f(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}

Vector3f Vector3f::operator+(Vector3f& v) {
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

Vector3f Vector3f::operator-(Vector3f& v) {
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

Vector3f Vector3f::operator*(float n) {
	return Vector3f(x * n, y * n, z * n);
}

Vector3f Vector3f::operator/(float n) {
	return Vector3f(x / n, y / n, z / n);
}

Vector3f Vector3f::unit() {
	return *this / sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::cross(Vector3f v) {
	return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vector3f::dot(Vector3f v) {
	return x * v.x + y * v.y + z * v.z;
}

Vector3f Vector3f::operator+=(Vector3f& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3f Vector3f::operator-=(Vector3f& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3f Vector3f::operator*=(float n) {
	x *= n;
	y *= n;
	z *= n;
	return *this;
}

Vector3f Vector3f::operator/=(float n) {
	x /= n;
	y /= n;
	z /= n;
	return *this;
}

Vector3f Vector3f::operator-() {
	return Vector3f(-x, -y, -z);
}

//Vector3f Vector3f::rotate(float angle, Vector3f axis) {
//	float sinAngle = sin((M_PI / 180) * angle);
//	float cosAngle = cos((M_PI / 180) * angle);
//
//	return this->cross(axis * sinAngle) +        //Rotation on local X
//		(*this * cosAngle) +                     //Rotation on local Z
//		axis * this->dot(axis * (1 - cosAngle)); //Rotation on local Y
//}
//
//Vector3f Vector3f::rotateX(float angle) {
//	return rotate(angle, Vector3f(1, 0, 0));
//}
//
//Vector3f Vector3f::rotateY(float angle) {
//	return rotate(angle, Vector3f(0, 1, 0));
//}
//
//Vector3f Vector3f::rotateZ(float angle) {
//	return rotate(angle, Vector3f(0, 0, 1));
//}


