#ifndef vertex_h
#define vertex_h

#include <stdlib.h>

#include "vector.h"
#include "matrix.h"

typedef struct Vertex {
	Vector4f_t m_pos;
	Vector4f_t m_color;
}Vertex_t;

void NewVertex(Vertex_t * Vector, Vector4f_t pos, Vector4f_t color);

void TransformVertex(Vector4f_t * Vector, Matrix4f_t * transform, Vector4f_t * m_pos);

void PerspectiveDivide(Vector4f_t * Vector);

float TriangleArea(Vertex_t * a, Vertex_t * b, Vertex_t * c);
	
#endif /* vertex_h */
