#include <stdio.h> 
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include <stdlib.h> 
#include <math.h>

#include "render.h"
#include "vertex.h"
#include "matrix.h"
#include "gradient.h"
#include "edge.h"
#include "screen.h"

void FillTriangle(Vertex_t * min, Vertex_t * mid, Vertex_t * max){
	
	Vertex_t * temp;
	
	Matrix4f_t * screenSpaceTransform =(Matrix4f_t *) malloc(sizeof(Matrix4f_t));
	InitScreenSpaceTransform(screenSpaceTransform ,600/2, 600/2);
	
	TransformVertex(&min->m_pos, screenSpaceTransform, &min->m_pos);
	PerspectiveDivide(&min->m_pos);
	TransformVertex(&mid->m_pos, screenSpaceTransform, &mid->m_pos);
	PerspectiveDivide(&mid->m_pos);
	TransformVertex(&max->m_pos, screenSpaceTransform, &max->m_pos);
	PerspectiveDivide(&max->m_pos);	
	
		
		if(max->m_pos.y < mid->m_pos.y){
			temp = max;
			max = mid;
			mid = temp;
		}

		if(mid->m_pos.y < min->m_pos.y){
			temp = mid;
			mid = min;
			min = temp;
		}
		
		if(max->m_pos.y < mid->m_pos.y){
			temp = max;
			max = mid;
			mid = temp;
		}	
			
	ScanTriangle(min, mid, max, TriangleArea(min, mid, max) >=0 );

}

void ScanTriangle(Vertex_t * min, Vertex_t * mid, Vertex_t * max, int handedness){

	Gradients_t Gradient;		
						
	Edge topToBottom;
	Edge topToMiddle;
	Edge middleToBottom;
	
	NewGradients(&Gradient, min, mid, max);
	
	SetEdge(&Gradient, &topToBottom, min, max, 0);
	SetEdge(&Gradient, &topToMiddle, min, mid, 0);
	SetEdge(&Gradient, &middleToBottom, mid, max, 1);

	
	ScanEdges(&Gradient, &topToBottom, &topToMiddle, handedness);
	ScanEdges(&Gradient, &topToBottom, &middleToBottom, handedness);
	
}

void ScanEdges(Gradients_t * gradient, Edge * a, Edge * b, int handedness){

		Edge * left = a;
		Edge * right = b;
		
		if(handedness){
			Edge * temp = left;
			left = right;
			right = temp;
		}

		int yStart = b->m_yStart;
		int yEnd   = b->m_yEnd;
		for(int j = yStart; j < yEnd; j++)
		{
			DrawScanLine(gradient, left, right, j);
			Step(left);
			Step(right);
		}
}

void DrawScanLine(Gradients_t * gradient, Edge * left, Edge * right, int j) {

	int xMin = (int)ceil(left->m_x);
	int xMax = (int)ceil(right->m_x);
	
	float xPrestep = xMin - left->m_x;

	Vector4f_t color;
	Vector4f_t temp;
	 
	MulFloatVector4f(&temp, &gradient->m_colorXStep, xPrestep);
	AddVector4f(&color, &left->m_color, &temp);	
	
	for(int i = xMin; i < xMax; i++){
		
		float rand;
		rand = color.z * 255.0f + 0.5f;
		uint8_t blue = (uint8_t) rand;
		rand = color.y * 255.0f + 0.5f;
		uint8_t green = (uint8_t) rand;
		rand = color.x * 255.0f + 0.5f;
		uint8_t red = (uint8_t) rand;
		
		uint32_t  A_Color =	blue + (green << 8) + (red << 16);
					//blue	//green		//Red
					
		put_buf(i, j, A_Color);
		
		AddVector4f(&color, &color, &gradient->m_colorXStep);

	}
	
}
