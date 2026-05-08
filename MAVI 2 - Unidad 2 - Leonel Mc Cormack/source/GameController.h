#pragma once
#include "raylib.h"
#include <box2d.h>
#include <vector>
#include "World.h"
#include "Box.h"
class GameController
{
private:
	
	/*
		Le damos un atributo World para crear ese mundo fisico
		y un contenedor dinamico que almacenara nuestros objetos (Box)
	*/
	World physicsWorld;
	std::vector<Box> boxes;

	// Con estas variables podemos establecer el angulo con el que se crea el objeto
	float currentAngle = 0.0f;
	const float rotationSpeed = 2.0f;



	Color background = { 110, 100, 215, 255 };

public:

	GameController();
	~GameController();

	void RunMainLoop();

	void Events();
	void UpdateGame();
	void DrawGame();


	void CreateBox(float _finalAngle);
};

