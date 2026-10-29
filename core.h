#ifndef _RENDER_H
#define _RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdint.h>

using std::cout;
using std::endl;

#define oops "[RDEngine] Oops!!!\n"
#define good "[RDEngine] Good!!!\n"

void log(char * logLevel, char * info) {
    cout << "[" << logLevel << "] " << info << "\n";
}
int RD_Init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		log("RDEngine/Init", "CANT INIT SDL VIDEO");
		return 1;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		log("RDEngine/Init", "CANT INIT IMG PNG");
		return 1;
	}
	log("RDEngine/Init", "SUCESS");
	return 0;
} 

class RD_Engine {
	public:
		SDL_Window * window;
		SDL_Renderer * renderer;
		uint8_t red, green, blue, alpha;
		
		int CreateEngine(const char * name, int width, int height) {
			window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
			if (!window) { // neu co loi xay ra thi SDL_CreateWindow() tra ve NULL nen ta dung !window de kiem tra loi
				log("RDEngine/CreateEngine", "CANT CREATE WINDOW");
				SDL_Quit();
				return 1;
			}
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (!renderer) { // cach kiem tra loi cua renderer cung tuong tu nhu cua window
				log("RDEngine/CreateEnine", "CANT CREATE RENDERER");
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 1;
			}
			return 0;
		}
		
		void Clear() {
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
		}
		
		void clearScreen() {
			SDL_SetRenderDrawColor(
				renderer,
                red, green,
				blue, alpha
			);
			SDL_RenderClear(renderer);
		}
		void updateScreen() {
			SDL_RenderPresent(renderer);
		}
		void drawTexture(SDL_Texture * texture, int x, int y, int w, int h) {
			SDL_Rect dst = {x, y, w, h};
			SDL_RenderCopy(renderer, texture, NULL, &dst);
		}
		SDL_Texture * loadTexture(const char * filename) {
			return IMG_LoadTexture(renderer, filename);
		}
		void setDefaultClearColor(uint8_t fr, uint8_t fg, uint8_t fb, uint8_t fa) {
            red = fr;
            green = fg;
            blue = fb;
            alpha = fa;
		}
		
};

void RD_Quit() {
	SDL_Quit();
}

#endif

