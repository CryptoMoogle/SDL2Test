
#include <stdlib.h>

#include "vertex.h"
#include "vector.h"


void NewVertex(Vertex_t * Vector, Vector4f_t pos, Vector4f_t color) {
	Vector->m_pos = pos;
	Vector->m_color = color;
}

	
void TransformVertex(Vector4f_t * Vector, Matrix4f_t * transform, Vector4f_t * m_pos){
	
	Transform(Vector, transform, m_pos);

}

void PerspectiveDivide(Vector4f_t * Vector){
	
	NewVector4f(Vector, Vector->x/Vector->w, Vector->y/Vector->w,
				Vector->z/Vector->w, Vector->w);
	
}

float TriangleArea(Vertex_t * min, Vertex_t * mid, Vertex_t * max){
	
	Vector4f_t * a = &min->m_pos;
	Vector4f_t * b = &mid->m_pos;
	Vector4f_t * c = &max->m_pos;	

		float x1 = c->x - a->x;
		float y1 = c->y - a->y;
		
		float x2 = b->x - a->x;
		float y2 = b->y - a->y;
		
		return (x1 * y2 - x2 * y1);
}
