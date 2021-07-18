#include <stdio.h>


#include <stdlib.h>
#include <math.h>

#include "edge.h"
#include "vector.h"
#include "gradient.h"
#include "vertex.h"

void SetEdge(Gradients_t * grad, Edge * Current, Vertex_t * min, Vertex_t * max, int Index){
	
Vector4f_t temp1;
Vector4f_t temp2;
Vector4f_t temp3;

		Current->m_yStart = (int)ceil(min->m_pos.y);
		Current->m_yEnd   = (int)ceil(max->m_pos.y);
		
		float yDist = max->m_pos.y - min->m_pos.y;
		float xDist = max->m_pos.x - min->m_pos.x;
		
		float yPrestep = Current->m_yStart - min->m_pos.y;	
		
		Current->m_xStep = (float)xDist/(float)yDist;	
		Current->m_x = min->m_pos.x + yPrestep * Current->m_xStep;
		
		float xPrestep = Current->m_x - min->m_pos.x;
		
MulFloatVector4f(&temp1, &grad->m_colorYStep, yPrestep);
MulFloatVector4f(&temp2, &grad->m_colorXStep, xPrestep);
AddVector4f(&temp3, &grad->m_color[Index], &temp1);
AddVector4f(&Current->m_color, &temp3, &temp2);

MulFloatVector4f(&temp1, &grad->m_colorXStep, Current->m_xStep);
AddVector4f(&Current->m_colorStep, &temp1, &grad->m_colorYStep);


}

void Step(Edge * Current){
		
	Current->m_x += Current->m_xStep;
	
	AddVector4f(&Current->m_color, &Current->m_color, &Current->m_colorStep);
		
}