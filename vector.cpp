
#include <stdlib.h>


#include "vector.h"

void NewVector4f(Vector4f_t * Vector, float x, float y, float z, float w) {
		Vector->x = x;
		Vector->y = y;
		Vector->z = z;
		Vector->w = w;
}

float LengthVector4f(Vector4f_t * Vect) {
	return (Vect->x * Vect->x + Vect->y * Vect->y +
			Vect->z * Vect->z + Vect->w * Vect->w);
}

float MaxVector4f(Vector4f_t * Vect){
	return max(max(Vect->x, Vect->y), max(Vect->z, Vect->w));
}	

float DotVector4f(Vector4f_t * Vect1, Vector4f_t * Vect2){//1=blank 2=r.
	return (Vect1->x * Vect2->x + Vect1->y * Vect2->y +
			Vect1->z * Vect2->z + Vect1->w * Vect2->w);
}

void CrossVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2){
	out->x = Vect1->y * Vect2->z - Vect1->z * Vect2->y;
	out->y = Vect1->z * Vect2->x - Vect1->x * Vect2->z;
	out->z = Vect1->x * Vect2->y - Vect1->y * Vect2->x;
	out->w = 0;
}

void NormalizedVector4f(Vector4f_t * out, Vector4f_t * Vect1){
	float length = LengthVector4f(Vect1);
	
	out->x = Vect1->x / length;
	out->y = Vect1->y / length;
	out->z = Vect1->z / length;
	out->w = Vect1->w / length;
}

void AddVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2){
	out->x = Vect1->x + Vect2->x;
	out->y = Vect1->y + Vect2->y;
	out->z = Vect1->z + Vect2->z;
	out->w = Vect1->w + Vect2->w;	
}

void AddFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r){
	out->x = Vect1->x + r;
	out->y = Vect1->y + r;
	out->z = Vect1->z + r;
	out->w = Vect1->w + r;
}

void SubVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2){
	out->x = Vect1->x - Vect2->x;
	out->y = Vect1->y - Vect2->y;
	out->z = Vect1->z - Vect2->z;
	out->w = Vect1->w - Vect2->w;	
}

void SubFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r){
	out->x = Vect1->x - r;
	out->y = Vect1->y - r;
	out->z = Vect1->z - r;
	out->w = Vect1->w - r;
}

void MulVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2){
	out->x = Vect1->x * Vect2->x;
	out->y = Vect1->y * Vect2->y;
	out->z = Vect1->z * Vect2->z;
	out->w = Vect1->w * Vect2->w;	
}

void MulFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r){
	out->x = Vect1->x * r;
	out->y = Vect1->y * r;
	out->z = Vect1->z * r;
	out->w = Vect1->w * r;
}

void DivVector4f(Vector4f_t * out, Vector4f_t * Vect1, Vector4f_t * Vect2){
	out->x = Vect1->x / Vect2->x;
	out->y = Vect1->y / Vect2->y;
	out->z = Vect1->z / Vect2->z;
	out->w = Vect1->w / Vect2->w;	
}

void DivFloatVector4f(Vector4f_t * out, Vector4f_t * Vect1, float r){
	out->x = Vect1->x / r;
	out->y = Vect1->y / r;
	out->z = Vect1->z / r;
	out->w = Vect1->w / r;
}

//void LerpVector4f(Vector4f_t * out, Vector4f_t * Vect1, float lerpFactor){	
//		return dest.Sub(this).Mul(lerpFactor).Add(this);
//}

bool Vector4fEqual(Vector4f_t * Vect1, Vector4f_t * Vect2){	
	if( Vect1->x == Vect2->x && Vect1->y == Vect2->y &&
		Vect1->z == Vect2->z && Vect1->w == Vect2->w ){
		return 1;
	}else{
		return 0;
	}
}

