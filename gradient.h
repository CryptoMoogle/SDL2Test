#ifndef gradient_h
#define gradient_h

#include <stdlib.h>

#include "vector.h"
#include "vertex.h"

typedef struct Gradients {
	Vector4f_t m_colorXStep;
	Vector4f_t m_colorYStep;
	Vector4f_t m_color[3];
} Gradients_t;

void NewGradients(Gradients_t * gradient, Vertex_t * min, Vertex_t * mid, Vertex_t * max);

#endif /* gradient_h */