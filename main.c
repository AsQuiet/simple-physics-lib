#include <stdlib.h>
#include <stdio.h>

#include "libs/spl_vector.h"

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
    
    return 0;
}