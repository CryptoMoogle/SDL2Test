
#include <stdlib.h>

#include "gradient.h"
#include "vertex.h"
#include "vector.h"

void NewGradients(Gradients_t * gradient, Vertex_t * min, Vertex_t * mid, Vertex_t * max){
	
gradient->m_color[0] = min->m_color;
gradient->m_color[1] = mid->m_color;
gradient->m_color[2] = max->m_color;	

Vector4f_t temp;
Vector4f_t temp1;
Vector4f_t temp2;
	
	float oneOverdX = 1.0f /(((mid->m_pos.x - max->m_pos.x) * (min->m_pos.y - max->m_pos.y)) - ((min->m_pos.x - max->m_pos.x) * (mid->m_pos.y - max->m_pos.y)));
	
	float oneOverdY = - oneOverdX;
	
	SubVector4f(&temp, &gradient->m_color[1], &gradient->m_color[2]);
	MulFloatVector4f(&temp1, &temp, min->m_pos.y - max->m_pos.y);
	SubVector4f(&temp, &gradient->m_color[0], &gradient->m_color[2]);
	MulFloatVector4f(&temp2, &temp, mid->m_pos.y - max->m_pos.y);			
	SubVector4f(&temp, &temp1, &temp2);
	MulFloatVector4f(&gradient->m_colorXStep, &temp, oneOverdX);


	SubVector4f(&temp, &gradient->m_color[1], &gradient->m_color[2]);
	MulFloatVector4f(&temp1, &temp, min->m_pos.x - max->m_pos.x);
	SubVector4f(&temp, &gradient->m_color[0], &gradient->m_color[2]);
	MulFloatVector4f(&temp2, &temp, mid->m_pos.x - max->m_pos.x);			
	SubVector4f(&temp, &temp1, &temp2);
	MulFloatVector4f(&gradient->m_colorYStep, &temp, oneOverdY);
	
}

