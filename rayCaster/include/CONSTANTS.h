#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NBSHADOWRAY 4
#define SUPER_SAMPLING_NUMBER 8

#define HEIGHT 500
#define WIDTH 500

#define MAXBOUNCES 3
#define RUSSIAN_P 0.4

#define BRDF_CONSTANT 150.0
#define DIRECT_CONSTANT 0.9f
#define INDIRECT_CONSTANT 0.1f

// frustum variables:
#define NEAR -100
#define LEFT -200
#define RIGHT 200
#define TOP 200
#define BOTTOM -200

#define MIN_T 0.00001
#define EPSILON 0.1f

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif


#endif
