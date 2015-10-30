#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NBSHADOWRAY 4
#define SUPER_SAMPLING_NUMBER 8

#define HEIGHT 300
#define WIDTH 300

#define MAXBOUNCES 3
#define RUSSIAN_P 0.4

#define BRDF_CONSTANT 150.0
#define DIRECT_CONSTANT 0.9f
#define INDIRECT_CONSTANT 0.1f

// frustum variables:
#define NEAR -100
#define LEFT -100
#define RIGHT 100
#define TOP 100
#define BOTTOM -100

#define MIN_T 0.00001
#define EPSILON 0.1f

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif


#endif
