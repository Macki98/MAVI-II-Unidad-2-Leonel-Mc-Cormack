#include "GameController.h"

GameController::GameController()
{
	// Creamos la pantalla y establemecemos el FrameRate
	const int screenWidth = 1000;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "MAVI II - Unidad 1 - Leonel Mc Cormack");
	SetTargetFPS(60);

	// A su vez, establecemos el piso de nuestro muendo
	physicsWorld.AddFloor();
}

GameController::~GameController() 
{

}

// Loop principal que se ejecutara hasta cerrar la ventana
void GameController::RunMainLoop()
{
	
	while (!WindowShouldClose())
	{
		Events();
		UpdateGame();
		DrawGame();
	}

	CloseWindow();
}

void GameController::Events()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		if (!boxes.empty()) 
		{
			Box& lastBox = boxes.back();

			// Como Box2D utiliza medidas del mundo fisico, el objeto resulta muy "pesado" por lo tanto 
			// necesitamos aplicar valores altos para que se aprecie la simulacion de movimiento
			// hasta incorporar formulas que permitan la conversion de unidades
			b2Vec2 impulse = { 50000.0f,-90000.0f };
			lastBox.GetBody()->ApplyLinearImpulseToCenter(impulse, true);
			
		}
	}
}

void GameController::UpdateGame()
{
	// Metodo que como mencione anteriormente nos permite establcer el angulo de rotacion para el objeto
	if (IsKeyDown(KEY_RIGHT))
	{
		currentAngle += rotationSpeed;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		currentAngle -= rotationSpeed;
	}

	// Con la barra espaciadora creamos un objeto
	if (IsKeyPressed(KEY_C))
	{
		float finalAngle = currentAngle * RAD2DEG;

		CreateBox(finalAngle);
	}


	physicsWorld.Update();
}

void GameController::DrawGame()
{

	BeginDrawing();
	ClearBackground(background);

	physicsWorld.Draw();

	for (Box& b : boxes)
	{
		b.Draw();
	}

	DrawText("Espacio: Crear Caja | Flechas: Rotar | L: Lanzar caja", 10, 10, 20, DARKGRAY);
	DrawText(TextFormat("Angulo actual: %.2f", currentAngle), 10, 40, 20, BLUE);

	EndDrawing();
}

void GameController::CreateBox(float _finalAngle)
{
	boxes.push_back(Box(*physicsWorld.GetB2World(), _finalAngle));
}
