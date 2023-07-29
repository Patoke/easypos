/* -- easypos (https://github.com/Patoke/easypos)
 * - position.cpp
 * Copyright(C) 2023 https://github.com/Patoke
 *
 * This program is free software : you can redistribute it and /or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.If not, see < http://www.gnu.org/licenses/>.
 */

#include "position.hpp"
#include "math.hpp"

#pragma region s_angle
s_angle s_angle::normalize() {
    this->x = math_i.normalize_angle(this->x);
    this->y = math_i.normalize_angle(this->y);
    this->z = this->z < 50.f && this->z > -50.f ? this->z : 0.f;

    return *this;
}

s_vec3 s_angle::forward() {
    s_vec3 return_forward{};
    float sp{}, sy{}, cp{}, cy{};

    math_i.sin_cos(deg2rad(this->x), &sp, &cp);
    math_i.sin_cos(deg2rad(this->y), &sy, &cy);

    return_forward.x = cp * cy;
    return_forward.y = cp * sy;
    return_forward.z = -sp;

    return return_forward;
}

s_vec3 s_angle::right() {
    s_vec3 return_right{};
    float sp{}, sy{}, sr{}, cp{}, cy{}, cr{};

    math_i.sin_cos(deg2rad(this->x), &sp, &cp);
    math_i.sin_cos(deg2rad(this->y), &sy, &cy);
    math_i.sin_cos(deg2rad(this->z), &sr, &cr);

	return_right.x = -1.f * sr * sp * cy + -1.f * cr * -sy;
    return_right.y = -1.f * sr * sp * sy + -1.f * cr * cy;
    return_right.z = -1.f * sr * cp;

    return return_right;
}

s_vec3 s_angle::up() {
    s_vec3 return_up{};
    float sp{}, sy{}, sr{}, cp{}, cy{}, cr{};

    math_i.sin_cos(deg2rad(this->x), &sp, &cp);
    math_i.sin_cos(deg2rad(this->y), &sy, &cy);
    math_i.sin_cos(deg2rad(this->z), &sr, &cr);

    return_up.x = cr * sp * cy + -sr * -sy;
    return_up.y = cr * sp * sy + -sr * cy;
    return_up.z = cr * cp;

    return return_up;
}
#pragma endregion

#pragma region s_vec3
s_angle s_vec3::to_angle() const {
    return math_i.calculate_angle(*this);
}

s_vec3 s_vec3::normalize() {
    this->x = std::isfinite(this->x) ? std::remainderf(this->x, 360.f) : 0.f;
    this->y = std::isfinite(this->y) ? std::remainderf(this->y, 360.f) : 0.f;
    this->z = 0.f;

    return *this;
}

float s_vec3::normalize_in_place() {
    float radius = this->length();

    // FLT_EPSILON is added to the radius to eliminate the possibility of division by zero
    float iradius = 1.f / (radius + FLT_EPSILON);

    this->x *= iradius;
    this->y *= iradius;
    this->z *= iradius;

    return radius;
}
#pragma endregion