#ifndef matrix_h
#define matrix_h

#include <stdlib.h>

#include "vector.h"

typedef struct Matrix4f {
	
	float m [4][4];

}Matrix4f_t;

void InitIdentity(Matrix4f_t * matrix);

void InitScreenSpaceTransform(Matrix4f_t * matrix ,float halfWidth, float halfHeight);

void InitPerspective(Matrix4f_t * matrix, float Tanfov, float aspectRatio, float zNear, float zFar);

void InitTranslation(Matrix4f_t * matrix, float x, float y, float z);

void InitRotationFloat(Matrix4f_t * matrix, float x, float y, float z);	

void Transform(Vector4f_t * Vector, Matrix4f_t * s, Vector4f_t * r);

void Matrix4fMul(Matrix4f_t * matrix, Matrix4f_t * s, Matrix4f_t * r);

void Matrix4fSet(Matrix4f_t * matrix, int x, int y, float value);

#endif /* matrix_h */