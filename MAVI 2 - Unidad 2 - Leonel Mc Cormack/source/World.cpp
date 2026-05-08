#include "World.h"

World::World() : gravity(0.0f, 9.8f), world(gravity)
{
 
}

World::~World()
{
}

// En este metodo determinamos como calcular el estado del sistema
void World::Update()
{
    world.Step(timeStep, velocityIterations, positionIterations);
}

// En este metodo creamos un cuerpo rigido (rigid body) que actua como piso para interactuar con los objetos que caen
void World::AddFloor()
{
    Vector2 floorPos = { (float)GetScreenWidth() / 2.0f,
                 (float)GetScreenHeight() - 40.0f };

    b2BodyDef groundDef;
    groundDef.type = b2_staticBody;
    groundDef.position.Set(floorPos.x, floorPos.y);
    b2Body* groundBody = world.CreateBody(&groundDef);

    b2PolygonShape groundShape;
    groundShape.SetAsBox((float)GetScreenWidth() / 2.0f, 20.0f);
    groundBody->CreateFixture(&groundShape, 0.0f);
}

// Aqui simplemente dibujamos el piso para que el mismo este representado en el mundo
void World::Draw()
{
    DrawRectangle(0, GetScreenHeight() - 60, GetScreenWidth(), 40, Fade(DARKGREEN, 0.7f));
}

b2World* World::GetB2World()
{
    return &world;
}
