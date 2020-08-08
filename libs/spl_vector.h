#if !defined printf
#include <stdio.h>
#endif

#if !defined sqrt
#include <math.h>
#endif

#if !defined(SPL_VECTOR_H)
#define SPL_VECTOR_H

typedef struct splvec3
{ 
    double x;
    double y;
    double z;
} vec3;

vec3 create_vec3_empty();
vec3 create_vec3(double x, double y, double z);
vec3 copy_vec3(vec3 *v);

vec3 mod_vec3(vec3 *v, int n);
vec3 cross_vec3(vec3 *v, vec3 *w);    

vec3 get_add_vec3(vec3 *v, vec3*w);
vec3 get_sub_vec3(vec3 *v, vec3*w);
vec3 get_mul_vec3(vec3 *v, vec3*w);
vec3 get_div_vec3(vec3 *v, vec3*w);

void add_vec3(vec3 *v, vec3*w);
void sub_vec3(vec3 *v, vec3*w);
void mul_vec3(vec3 *v, vec3*w);
void div_vec3(vec3 *v, vec3*w);

void limit_vec3(vec3 *v, double min, double max);
void limit_mag_vec3(vec3 *v, double min, double max);

double mag(vec3 *v);
double magSq(vec3 *v);
double dot_vec3(vec3 *v, vec3 *w);

double getHeading(vec3 *v);

void normalize(vec3 *v);
void setMag(vec3 *v, double magnitude);

void print_vec3(vec3 *vec);

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

double magSq(vec3 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z;
}

double mag(vec3 *v)
{
    return sqrt(magSq(v));
}

void setMag(vec3 *v, double magnitude)
{   
    normalize(v);
    v->x = v->x * magnitude;
    v->y = v->y * magnitude;
    v->z = v->z * magnitude;
}

void normalize(vec3 *v)
{   
    double magnitude = mag(v);
    v->x = v->x / magnitude;
    v->y = v->y / magnitude;
    v->z = v->z / magnitude;
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
    double mag_ = mag(v);

    if (mag_ < min)
        setMag(v, min);
    if (mag_ > max)
        setMag(v, max);
}

double getHeading(vec3 *v)
{
    // in radians
    if (v->x == 0.0)
        if (v->y == 0.0)
            return 270;
        else
            return 90;

    double angle = v->y / v->x;
    return atan(angle);
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