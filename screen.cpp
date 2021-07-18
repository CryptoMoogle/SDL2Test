//C:\MinGW\project\screen>
//g++ screen.cpp vector.cpp matrix.cpp vertex.cpp render.cpp gradient.cpp edge.cpp -lmingw32 -lSDL2main -lSDL2 -o test


#define SDL_MAIN_HANDLED

#include <bits/stdc++.h> 

#include <stdlib.h>
#include <stdio.h>

#include "vector.h"
#include "matrix.h"
#include "vertex.h"
#include "render.h"

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 600
#define WINDOW_HIGHT 600

#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

uint32_t * pixels;

int main(void) {
	
	clock_t current, previous;

	uint32_t buff[600 * 600];
	
	
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;
	SDL_Texture * texture;
    int i, q;

    SDL_Init(SDL_INIT_VIDEO);
    //SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HIGHT,
		//0, &window, &renderer);
	window = SDL_CreateWindow("SDL2 Pixel Drawing", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 600, 600, 0);
	
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, 
		SDL_TEXTUREACCESS_STATIC, 600, 600);
	
	pixels = (uint32_t *)buff;
	memset(pixels, 255, 600 * 600 * sizeof(uint32_t));


 

	Vector4f_t * TempMinY =(Vector4f_t *)malloc(sizeof(Vector4f_t));
	NewVector4f(TempMinY, -1, -1, 0, 1);
	Vector4f_t * TempMidY =(Vector4f_t *)malloc(sizeof(Vector4f_t));
	NewVector4f(TempMidY, 0, 1, 0, 1);
	Vector4f_t * TempMaxY =(Vector4f_t *)malloc(sizeof(Vector4f_t));
	NewVector4f(TempMaxY, 1, -1, 0, 1);
	
	float rotCounter = 0.0f;

	Matrix4f_t * projection = (Matrix4f_t *)malloc(sizeof(Matrix4f_t));
	InitPerspective(projection, degToRad(90.0f), WINDOW_WIDTH/WINDOW_HIGHT, 0.1f, 1000.0f);
	Matrix4f_t * translation = (Matrix4f_t *)malloc(sizeof(Matrix4f_t));
	InitTranslation(translation, 0, 0, 3.0f);	

	previous = clock();	
 	
	Matrix4f_t * rotation =(Matrix4f_t *)malloc(sizeof(Matrix4f_t));
	Matrix4f_t * transform =(Matrix4f_t *)malloc(sizeof(Matrix4f_t));
	Matrix4f_t * temp =(Matrix4f_t *)malloc(sizeof(Matrix4f_t));
	
	Vertex_t * minYVert =(Vertex_t *)malloc(sizeof(Vertex_t));
	NewVector4f(&minYVert->m_color, 1.0f, 0.0f, 0.0f, 0.0f);
	Vertex_t * midYVert =(Vertex_t *)malloc(sizeof(Vertex_t));
	NewVector4f(&midYVert->m_color, 0.0f, 1.0f, 0.0f, 0.0f);
	Vertex_t * maxYVert =(Vertex_t *)malloc(sizeof(Vertex_t));
	NewVector4f(&maxYVert->m_color, 0.0f, 0.0f, 1.0f, 0.0f);
printf("Start\n");
	while(1){//for (i = 0; i < 50; ++i){
		current = clock();
		float delta = float(current - previous) / (float)(CLOCKS_PER_SEC);
		previous = current;
		
		rotCounter += delta;
		
		InitRotationFloat(rotation, 0.0f, rotCounter, 0.0f);
		
		Matrix4fMul(temp, translation, rotation);
		Matrix4fMul(transform, projection, temp);
		
		TransformVertex(&minYVert->m_pos, transform, TempMinY);
		TransformVertex(&midYVert->m_pos, transform, TempMidY);
		TransformVertex(&maxYVert->m_pos, transform, TempMaxY);
		
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		memset(pixels, 0, 600 * 600 * sizeof(uint32_t));
		
		FillTriangle(minYVert, midYVert, maxYVert);
		
///for (q = 0; q < 600; ++q){
///	pixels[q * 600 + i] = 0x00FF0000;
///}
		SDL_UpdateTexture(texture, NULL, pixels, 600 * sizeof(uint32_t));
//SDL_Delay(1);
	}
	
	


	
    while (1) {////
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)/////
            break;//////
    }//////
	SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void put_buf(int i, int j, uint32_t color){
	
	pixels[j * 600 + i] = color;
	
}