#include <stdlib.h>
#include <stdio.h>

#include "libs/spl_vector.h"

int main()
{

    
    vec3 v1 = create_vec3(1, 2, 0);
    vec3 v2 = create_vec3(1, 2, 0);

    vec3 v3 = get_add_vec3(&v1, &v2);

    print_vec3(&v1);
    print_vec3(&v3);
    
    

    return 0;
}