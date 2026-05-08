#pragma once
#include "raylib.h"
#include <box2d.h>
#include <vector>

class Box
{
private:
	
	// Definimos las propiedades iniciales del cuerpo
	b2Body* boxBody;
	float width;
	float height;
	Color color;

public:

	Box(b2World& _world, float _finalAngle);
	~Box();

	void Draw();

	b2Body* GetBody() const;

};

