#ifndef render_h
#define render_h

#include <stdlib.h>

#include "vertex.h"
#include "gradient.h"
#include "edge.h"

void FillTriangle(Vertex_t * v1, Vertex_t * v2, Vertex_t * v3);

void ScanTriangle(Vertex_t * minYVert, Vertex_t * midYVert, 
			Vertex_t * maxYVert, int handedness);
			
			
			
			

void IntScanBuffer(int height);
	
void FillShape(int yMin, int yMax);

void ScanConvertTriangle(Vector4f_t * minYVert, Vector4f_t * midYVert, Vector4f_t * maxYVert, int handedness);

void ScanConvertLine(Vector4f_t * minYVert, Vector4f_t * maxYVert, int whichSide);


		
void DrawScanLine(Gradients_t * gradient, Edge * left, Edge * right, int j);

void ScanEdges(Gradients_t * gradient, Edge * a, Edge * b, int handedness);

#endif /* render_h */