#include "Box.h"

 /*
	Establecemos como van a ser las propiedades del cuerpo
	Pasamos como parametro el mundo en el cual se va a crear
	y un flotante que determine el angulo en que se va a crear
	establecido por el input de las flechas de direccion
 */
Box::Box(b2World& _world, float _finalAngle)
{
	width = 30.0f;
	height = 50.0f;
	color = Fade(SKYBLUE, 0.95f);

	/*
		Definimos que tipo de cuerpo es, es decir
		que responda a la fuerza de gravedad
		que responda a fuerzas 
		y pueda moverse
	*/
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set((width/2) + 10.0f, (float)GetScreenHeight() - 40.0f - height);
	bodyDef.angle = _finalAngle;

	boxBody = _world.CreateBody(&bodyDef);

	// Definimos la forma que tendra nuestro cuerpo
	b2PolygonShape boxShape;
	boxShape.SetAsBox(width / 2.0f, height / 2.0f);

	/*
		Finalmente creamos un fixture que una la forma con el cuerpo
		El mismo no solo asocia una forma (shape) a un cuerpo fisico
		sino que tambien permite definir las propiedades del objeto
		es decir como el mismo tiene su propia densidad, friccion y restitucion
	*/
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.2f;


	boxBody->CreateFixture(&fixtureDef);
}

Box::~Box()
{
}

void Box::Draw()
{

	b2Vec2 pos = boxBody->GetPosition();
	float angle = boxBody->GetAngle() * RAD2DEG;

	Rectangle rect = { pos.x, pos.y, width, height };

	Vector2 origin = { width / 2.0f, height / 2.0f };
	
	// Gracias a la funcion Pro podemos dibujar nuestro cuerpo con una rotacion especifica
	DrawRectanglePro(rect, origin, angle, color);
}

b2Body* Box::GetBody() const
{
	return boxBody;
}