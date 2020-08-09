#if !defined printf
#include <stdio.h>
#endif

#if !defined sqrt
#include <math.h>
#endif

#if !defined(SPL_VECTOR_H)
#define SPL_VECTOR_H

typedef struct
{ 
    double x;
    double y;
    double z;
} vec3;

vec3        create_vec3_empty       ();                                     // create vector with 0 defaults
vec3        create_vec3             (double x, double y, double z);         // create vector
vec3        copy_vec3               (vec3 *v);                              // copy a vector
vec3        create_vec3_from_scalor (double scalor);                        // create a vector that has all of its components set to the scalor

vec3        mod_vec3                (vec3 *v, int n);                       // returns the 'modulo' vector of a vector with an int
vec3        cross_vec3              (vec3 *v, vec3 *w);                     // returns the cross-product vector

vec3        get_add_vec3            (vec3 *v, vec3*w);                      // get a vector by addition
vec3        get_sub_vec3            (vec3 *v, vec3*w);                      // get a vector by subtraction
vec3        get_mul_vec3            (vec3 *v, vec3*w);                      // get a vector by multiplication
vec3        get_div_vec3            (vec3 *v, vec3*w);                      // get a vector by division

void        add_vec3                (vec3 *v, vec3*w);                      // add two vectors
void        sub_vec3                (vec3 *v, vec3*w);                      // subtract two vectors
void        mul_vec3                (vec3 *v, vec3*w);                      // multiply two vectors
void        div_vec3                (vec3 *v, vec3*w);                      // divide two vectors

void        limit_vec3              (vec3 *v, double min, double max);      // limit each component of a vector 
void        limit_mag_vec3          (vec3 *v, double min, double max);      // limit the magnitude of a vector
void        set_mag_vec3            (vec3 *v, double magnitude);            // set the magnitude of a vector
void        normalize_vec3          (vec3 *v);                              // set magnitude to 1 (unit length)

double      mag_vec3                (vec3 *v);                              // get the magnitude
double      mag_sq_vec3             (vec3 *v);                              // get the magnitude squared

double      dot_vec3                (vec3 *v, vec3 *w);                     // get the dot product
double      get_heading_vec3        (vec3 *v);                              // get the heading in radians of a vector

void        print_vec3              (vec3 *vec);                            // print out the vector

#endif

vec3 create_vec3(double x, double y, double z)
{
    vec3 new_v;
    new_v.x = x;
    new_v.y = y;
    new_v.z = z;
    return new_v;
}

vec3 create_vec3_empty()
{
    return create_vec3(0.0, 0.0, 0.0);
}

vec3 copy_vec3(vec3 *v)
{
    return create_vec3(v->x, v->y, v->z);
}

vec3 create_vec3_from_scalor(double scalor)
{
    return create_vec3(scalor, scalor, scalor);
}

void add_vec3(vec3 *v, vec3 *w)
{
    v->x = v->x + w->x;
    v->y = v->y + w->y;
    v->z = v->z + w->z;
}

void sub_vec3(vec3 *v, vec3 *w)
{
    v->x = v->x - w->x;
    v->y = v->y - w->y;
    v->z = v->z - w->z;
}

void mul_vec3(vec3 *v, vec3 *w)
{
    v->x = v->x * w->x;
    v->y = v->y * w->y;
    v->z = v->z * w->z;
}

void div_vec3(vec3 *v, vec3 *w)
{
    v->x = v->x / w->x;
    v->y = v->y / w->y;
    v->z = v->z / w->z;
}

vec3 get_add_vec3(vec3 *v, vec3 *w)
{
    vec3 u = copy_vec3(v);
    add_vec3(&u, w);
    return u;
}

vec3 get_sub_vec3(vec3 *v, vec3 *w)
{
    vec3 u = copy_vec3(v);
    sub_vec3(&u, w);
    return u;
}

vec3 get_mul_vec3(vec3 *v, vec3 *w)
{
    vec3 u = copy_vec3(v);
    mul_vec3(&u, w);
    return u;
}

vec3 get_div_vec3(vec3 *v, vec3 *w)
{
    vec3 u = copy_vec3(v);
    div_vec3(&u, w);
    return u;
}

double mag_sq_vec3(vec3 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

double mag_vec3(vec3 *v)
{
    return sqrt(mag_sq_vec3(v));
}

void set_mag_vec3(vec3 *v, double magnitude)
{   
    normalize_vec3(v);
    vec3 temp = create_vec3_from_scalor(magnitude);
    mul_vec3(v, &temp);
}

void normalize_vec3(vec3 *v)
{   
    vec3 temp = create_vec3_from_scalor(mag_vec3(v));
    div_vec3(v, &temp);
}

void limit_vec3(vec3 *v, double min, double max)
{
    if (v->x < min)
        v->x = min;
    else if (v->x > max)
        v->x = max;
    
    if (v->y < min)
        v->y = min;
    else if (v->y > max)
        v->y = max;
    
    if (v->z < min)
        v->z = min;
    else if (v->z > max)
        v->z = max;
}

void limit_mag_vec3(vec3 *v, double min, double max)
{
    double mag_ = mag_vec3(v);

    if (mag_ < min)
        set_mag_vec3(v, min);
    if (mag_ > max)
        set_mag_vec3(v, max);
}

double get_heading_vec3(vec3 *v)
{
    return atan2(v->y, v->x);
}

vec3 mod_vec3(vec3 *v, int n)
{
    vec3 new_v;
    new_v.x = (int)v->x % n;
    new_v.y = (int)v->y % n;
    new_v.z = (int)v->z % n;
    return new_v;
}

vec3 cross_vec3(vec3 *v, vec3 *w)
{
    double x = v->y * w->z - v->z * w->y;
    double y = v->z * w->x - v->x * w->z;
    double z = v->x * w->y - v->y * w->x;
    return create_vec3(x,y,z);
}

double dot_vec3(vec3 *v, vec3 *w)
{
    return v->x * w->x + v->y * w->y + v->z * w->z;
}

void print_vec3(vec3 *vec)
{
    printf("(%f, %f, %f)", vec->x, vec->y, vec->z);
}