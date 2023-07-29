/* -- easypos (https://github.com/Patoke/easypos)
 * - math.hpp
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

#include "math.hpp"

// create instance
s_math math_i;

s_angle s_math::calculate_angle(const s_vec3& vec) {
    s_angle angles;

    angles.x = rad2deg(asinf(vec.z / vec.length()));
    angles.y = rad2deg(atan2(vec.y, vec.x));
    angles.z = 0.0f;

    return angles;
}

s_angle s_math::calculate_angle(const s_vec3 &source, const s_vec3 &destination, const s_angle &viewangles) {
    s_vec3 delta = source - destination;
    s_angle angles = calculate_angle(delta) - viewangles;

    if (delta.x >= 0.0)
        angles.y += 180.0f;

    return angles;
}

s_vec3 s_math::vector_transform(const s_vec3 &vector, const s_matrix3x4 &matrix) {
    s_vec3 res;
    res.x = vector.dot(matrix[0]) + matrix[0][3];
    res.y = vector.dot(matrix[1]) + matrix[1][3];
    res.z = vector.dot(matrix[2]) + matrix[2][3];
    return res;
}