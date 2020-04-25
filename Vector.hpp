#pragma once

#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Color.hpp"

class Vector
{
private:
    float x;
    float y;
    float z;

public:
    Vector();
    Vector(float x, float y, float z);
    Vector(float f);
    Vector operator+(Vector const &rhs);
    Vector operator*(std::vector<Vector> const &rhs);
    Vector& operator+=(Vector const &rhs);
    Vector& operator*=(float rhs);
    Vector& operator/=(float const &rhs);
    Vector operator-(Vector const &rhs);
    float dot_product(Vector const &rhs);
    float max_component();
    Vector cross_product(Vector const &rhs);
    float norm();
    Vector normalize();
    float get_x();
    float get_y();
    void set_y(float y);
    float get_z();
    Vector adjust();
    ~Vector();
    friend Vector operator*(std::vector<Vector> const &lhs, const Vector& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend Vector operator*(float scalar, Vector const& rhs);
    friend bool operator==(Vector const &left, float right);
    //friend Vector operator+(Vector lhs, Vector const& rhs);
    friend Vector operator*(Vector const& lhs, float scalar);
    friend Vector operator/(Vector const& lhs, float scalar);
};
