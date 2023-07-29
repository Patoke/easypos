
# easypos

Simple and lightweight positioning/math library written in C++


## Usage/Examples

```cpp
#include "easypos/math.hpp" // also includes position.hpp

int main(void) 
{
    { // -- Example: Checking if a 2D vector is inside a rectangle
        //  Create a 2D vector and rectangle
        auto new_vector = s_vec2(5.5f, 200);
        auto new_rectangle = s_rect(0.2f, 0, 250.5f, 250);

        //  Check if the vector is inside the rectangle
        bool is_inside = new_rectangle.in_rect(new_vector);
        // is_inside: true
    }
    
    { // -- Example: Get the angle to a 3D position
        auto new_origin = s_vec3(0, 100, 0);
        auto angle_to_origin = math_i.calculate_angle(new_origin);
        // angle_to_origin: s_angle(0, 270, 0)
        // this can also be normalized to any format you need!
        float normalized_yaw = math_i.normalize_angle(angle_to_origin.y, -180.f, 180.f);
        // normalized_yaw: 90.f
        // or you can normalize the whole angle to -180 - 180 format
        auto normalized_angle = angle_to_origin.normalize();
        // normalized_angle: s_angle(0, 90, 0)
        //  or flip it!
        auto flipped_angle = normalized_angle.flip().normalize();
        // flipped_angle: s_angle(-180, -90, 0)
    }

    { // -- Example: Get the angle between 2 3D positions
        auto first_origin = s_vec3(0, 100, 0);
        auto second_origin = s_vec3(200, 100, 0);
        auto angle_to_second = math_i.calculate_angle(first_origin, second_origin);
        // angle_to_second: s_angle(0, 180, 0)
    }

    return 0;
}
```


## License

This project is protected under the [GPL3](https://www.gnu.org/licenses/gpl-3.0.html) license

