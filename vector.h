#ifndef vector_h
#define vector_h

#include <stdlib.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

typedef struct Vector4f {
	float x;
	float y;
	float z;
	float w;
}Vector4f_t;

void NewVector4f(Vector4f_t * Vector, float x, float y, float z, float w);

float LengthVector4f(Vector4f_t * Vect);

float MaxVector4f(Vector4f_t * Vect);

float DotVector4f(Vector4f_t * Vect1, Vector4f_t * Vect2);

void CrossVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2);

void NormalizedVector4f(Vector4f_t * out, Vector4f_t * Vect1);

void AddVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2);

void AddFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r);

void SubVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2);

void SubFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r);

void MulVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2);

void MulFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r);

void DivVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2);

void DivFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r);

//void LerpVector4f(Vector4f_t * out, Vector4f_t * Vect1, float lerpFactor);

bool Vector4fEqual(Vector4f_t * Vect1, Vector4f_t * Vect2);


#endif /* vector_h */