#include <stdlib.h>
#include <stdio.h>

#include "libs/spl_vector.h"


vec3 create_color_rgb4(int r, int g, int b, int a)
{
    vec3 color = create_vec3(r,g,b);
    color.alpha = a;
    return color;
}

void print_color(vec3 *v)
{
    printf("(%f, %f, %f, %f)", v->x, v->y, v->z, v->alpha);
}

int main()
{

    vec3 v1 = create_vec3(3, 3, 0);
    vec3 v2 = create_vec3(3, 4, 0);

    sub_vec3(&v1, &v2);

    print_vec3(&v1);
    printf("\n");

    add_vec3(&v1, &v2);

    print_vec3(&v1);
    printf("\n");

    vec3 v3 = get_mul_vec3(&v1, &v2);

    print_vec3(&v3);
    printf("\n");

    vec3 v4 = mod_vec3(&v1, 2);

    print_vec3(&v4);
    printf("\n");

    printf("%f, %f\n", mag_vec3(&v4), mag_sq_vec3(&v4));
    normalize_vec3(&v4);
    print_vec3(&v4);
    printf("\n%f, %f\n", mag_vec3(&v4), mag_sq_vec3(&v4));

    vec3 mycolor = create_color_rgb4(255, 255, 255, 100);
    limit_vec3(&mycolor, 0, 255);
    print_color(&mycolor);

    return 0;
}