#include "Ball.h"

namespace Ballz
{
    Ball::Ball(float radius, float mass, const glm::vec2 &pos,
               const glm::vec2 &vel, unsigned int textureId,
               const Toaster::ColorRGBA8 &color)
    {
        this->radius = radius;
        this->mass = mass;
        this->position = pos;
        this->velocity = vel;
        this->textureId = textureId;
        this->color = color;
    }
}
