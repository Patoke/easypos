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

#pragma once

// includes
#include "position.hpp"

// angle functions
constexpr float rad2deg(const float x) {
    return x * (180.f / std::numbers::pi_v<float>);
}

constexpr float deg2rad(const float x) {
    return x * (std::numbers::pi_v<float> / 180.f);
}

struct s_math {
    __forceinline void sin_cos(float radians, float *sine, float *cosine) const {
        *sine = sinf(radians);
        *cosine = cosf(radians);
    }

    __forceinline float normalize_angle(float angle, float start = -180.f, float end = 180.f) const {
        const float width = end - start;
        const float offset_angle = angle - start;

        return (offset_angle - (floor(offset_angle / width) * width)) + start;
    }

    s_angle calculate_angle(const s_vec3 &vec);
    s_angle calculate_angle(const s_vec3 &source, const s_vec3 &destination, const s_angle &viewangles = s_angle(0.f, 0.f, 0.f));
    s_vec3 vector_transform(const s_vec3 &vector, const s_matrix3x4 &matrix);
};

extern s_math math_i;