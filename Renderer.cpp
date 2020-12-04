#include "Renderer.h"
#include "Game.h"

Renderer::Renderer(Game* g):
    game(g)
{

}

Renderer::~Renderer()
{
    delete game;
}
