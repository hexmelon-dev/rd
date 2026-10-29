#include "core.h"

#define ENTITY_CREATE_ENTITY_ERROR_PRD_NULL 1;
#define ENTITY_CREATE_ENTITY_ERROR_WH_LESS_0 2;
class Entity {
    public:
        RD_Engine * prd;
        int x, y;
        int vx, vy;
        int ax, ay;
        SDL_Rect box;
        SDL_Texture * texture;
        int createEntity(
            RD_Engine * fprd,
            int fw, int fh,
            SDL_Texture * ftx
        ) {
        
            // error checker
            if (!fprd) {
                log("Entity/CreateEntity", "FPRD = NULLL");
                return ENTITY_CREATE_ENTITY_ERROR_PRD_NULL;
            }
            // error checker
            if (fw < 0 || fh < 0) {
                log("Entity/CreateEntity", "fw < 0 || fh < 0");
                return ENTITY_CREATE_ENTITY_ERROR_WH_LESS_0;
            }
            
            prd = fprd;
            box.w = fw;
            box.h = fh;

            x = y = vx = vy = ax = ay = 0;
            return 0;
            
        }
        
};
