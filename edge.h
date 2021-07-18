#ifndef edge_h
#define edge_h

#include <stdlib.h>

#include "vector.h"
#include "gradient.h"
#include "vertex.h"

typedef struct Edges {
	
	float m_x;
	float m_xStep;
	int m_yStart;
	int m_yEnd;
	Vector4f_t m_color;
	Vector4f_t m_colorStep;

}Edge;

void SetEdge(Gradients_t * grad, Edge * Current, Vertex_t * min, Vertex_t * max, int Index);

void Step(Edge * CurrentEdge);

#endif /* edge_h */