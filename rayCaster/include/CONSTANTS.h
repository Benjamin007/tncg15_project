#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NBSHADOWRAY 1
#define SUPER_SAMPLING_NUMBER 16

#define HEIGHT 10
#define WIDTH 10

#define HEIGHT 200
#define WIDTH 200

#define MAXBOUNCES 5
#define RUSSIAN_P 0.2

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
