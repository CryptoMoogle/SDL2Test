
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
#include "vector.h"

void InitIdentity(Matrix4f_t * matrix){
	
matrix->m[0][0] = 1; matrix->m[0][1] = 0; matrix->m[0][2] = 0; matrix->m[0][3] = 0;
matrix->m[1][0] = 0; matrix->m[1][1] = 1; matrix->m[1][2] = 0; matrix->m[1][3] = 0;
matrix->m[2][0] = 0; matrix->m[2][1] = 0; matrix->m[2][2] = 1; matrix->m[2][3] = 0;
matrix->m[3][0] = 0; matrix->m[3][1] = 0; matrix->m[3][2] = 0; matrix->m[3][3] = 1;	

}

void InitScreenSpaceTransform(Matrix4f_t * matrix ,float halfWidth, float halfHeight){
	
matrix->m[0][0] = halfWidth; matrix->m[0][1] = 0; matrix->m[0][2] = 0; matrix->m[0][3] = halfWidth;
matrix->m[1][0] = 0; matrix->m[1][1] = -halfHeight; matrix->m[1][2] = 0; matrix->m[1][3] = halfHeight;
matrix->m[2][0] = 0; matrix->m[2][1] = 0; matrix->m[2][2] = 1; matrix->m[2][3] = 0;
matrix->m[3][0] = 0; matrix->m[3][1] = 0; matrix->m[3][2] = 0; matrix->m[3][3] = 1;

}

void InitPerspective(Matrix4f_t * matrix, float fov,
			float aspect, float zNear, float zFar){

		float tanFOV = (float)tan(fov / 2);
		float zRange = zNear - zFar;

matrix->m[0][0] = 1.0f/(tanFOV*aspect); matrix->m[0][1] = 0; matrix->m[0][2] = 0; matrix->m[0][3] = 0;
matrix->m[1][0] = 0;    matrix->m[1][1] = 1.0f / tanFOV;     matrix->m[1][2] = 0; matrix->m[1][3] = 0;
matrix->m[2][0] = 0; matrix->m[2][1] = 0; matrix->m[2][2] = (-zNear -zFar)/zRange; matrix->m[2][3] = 2 * zFar * zNear / zRange;
matrix->m[3][0] = 0; matrix->m[3][1] = 0; matrix->m[3][2] = 1; matrix->m[3][3] = 0;

}

void InitTranslation(Matrix4f_t * matrix, float x, float y, float z){
	
matrix->m[0][0] = 1; matrix->m[0][1] = 0; matrix->m[0][2] = 0; matrix->m[0][3] = x;
matrix->m[1][0] = 0; matrix->m[1][1] = 1; matrix->m[1][2] = 0; matrix->m[1][3] = y;
matrix->m[2][0] = 0; matrix->m[2][1] = 0; matrix->m[2][2] = 1; matrix->m[2][3] = z;
matrix->m[3][0] = 0; matrix->m[3][1] = 0; matrix->m[3][2] = 0; matrix->m[3][3] = 1;

}

void InitRotationFloat(Matrix4f_t * matrix, float x, float y, float z){

		Matrix4f_t rx;
		Matrix4f_t ry;
		Matrix4f_t rz;
		Matrix4f_t ryrx;

rz.m[0][0] =  (float)cos(z); rz.m[0][1] = -(float)sin(z); rz.m[0][2] =  0;			  rz.m[0][3] = 0;
rz.m[1][0] =  (float)sin(z); rz.m[1][1] =  (float)cos(z); rz.m[1][2] =  0;			  rz.m[1][3] = 0;
rz.m[2][0] =  0;			  rz.m[2][1] =  0;			    rz.m[2][2] =  1;			  rz.m[2][3] = 0;
rz.m[3][0] =  0;			  rz.m[3][1] =  0;				rz.m[3][2] =  0;			  rz.m[3][3] = 1;

rx.m[0][0] =  1;			  rx.m[0][1] =  0;				rx.m[0][2] =  0;			  rx.m[0][3] = 0;
rx.m[1][0] =  0;			  rx.m[1][1] = (float)cos(x);	rx.m[1][2] = -(float)sin(x); rx.m[1][3] = 0;
rx.m[2][0] =  0;			  rx.m[2][1] = (float)sin(x);	rx.m[2][2] =  (float)cos(x); rx.m[2][3] = 0;
rx.m[3][0] =  0;			  rx.m[3][1] =  0;				rx.m[3][2] =  0;			  rx.m[3][3] = 1;

ry.m[0][0] =  (float)cos(y); ry.m[0][1] =  0;				ry.m[0][2] = -(float)sin(y); ry.m[0][3] = 0;
ry.m[1][0] =  0;			  ry.m[1][1] =  1;				ry.m[1][2] =  0;			  ry.m[1][3] = 0;
ry.m[2][0] =  (float)sin(y); ry.m[2][1] =  0;				ry.m[2][2] =  (float)cos(y); ry.m[2][3] = 0;
ry.m[3][0] =  0;			  ry.m[3][1] =  0;				ry.m[3][2] =  0;			  ry.m[3][3] = 1;


Matrix4fMul(&ryrx, &ry, &rx);
Matrix4fMul(matrix, &rz, &ryrx);

}

void Transform(Vector4f_t * Vector, Matrix4f_t * s, Vector4f_t * r){	
       //minvert//r input
NewVector4f( Vector,
s->m[0][0] * r->x + s->m[0][1] * r->y + s->m[0][2] * r->z + s->m[0][3] * r->w,
s->m[1][0] * r->x + s->m[1][1] * r->y + s->m[1][2] * r->z + s->m[1][3] * r->w,
s->m[2][0] * r->x + s->m[2][1] * r->y + s->m[2][2] * r->z + s->m[2][3] * r->w,
s->m[3][0] * r->x + s->m[3][1] * r->y + s->m[3][2] * r->z + s->m[3][3] * r->w);
	
}

void Matrix4fMul(Matrix4f_t * matrix, Matrix4f_t * s, Matrix4f_t * r){
	
	for(int i = 0; i < 4; i++){
		
		for(int j = 0; j < 4; j++){
	
			Matrix4fSet(matrix, i, j,
			s->m[i][0] * r->m[0][j] +
			s->m[i][1] * r->m[1][j] +
			s->m[i][2] * r->m[2][j] +
			s->m[i][3] * r->m[3][j]);
		
		}
	}
}

void Matrix4fSet(Matrix4f_t * matrix, int x, int y, float value){

	matrix->m[x][y] = value;

}
