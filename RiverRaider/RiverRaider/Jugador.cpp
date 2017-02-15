#include "Jugador.h"


CJugador::CJugador()
{
}


CJugador::~CJugador()
{
}

CJugador::CJugador(int x, int y){
	this->x = x;
	this->y = y;
	alto = 96;// 117; //100
	ancho = 96;// 117;//119
	indiceX = 0;
	indiceY = 0;
	dx = 0;
	dy = 0;
	ultima = Direccion::Abajo;
	direccion = Direccion::Ninguno;

}

void CJugador::Mover(BufferedGraphics ^buffer, Bitmap ^imgPersonaje){
	switch (direccion)
	{
	case Direccion::Arriba:
		indiceY = 3;
		if (indiceX>=0 & indiceX<2)
			indiceX++;
		else
			indiceX = 0;
		
		dx = 0; dy = -5; ultima = Arriba;
		break;

	case Direccion::Abajo:
		indiceY = 0;
		indiceX = (indiceX >= 0 & indiceX < 2) ? indiceX + 1 : 0;
		dx = 0; dy = +5; ultima = Abajo;
		break;

	case Direccion::Izquierda:
		indiceY = 1;
		indiceX = (indiceX >= 0 & indiceX < 2) ? indiceX + 1 : 0;
		dx = -5; dy = -0; ultima = Izquierda;
		break;

	case Direccion::Derecha:
		indiceY = 2;
		indiceX = (indiceX >= 0 & indiceX < 2) ? indiceX + 1 : 0;
		dx = +5; dy = 0; ultima = Derecha;
		break;

	case Direccion::Ninguno:
		dx = dy = 0;
		switch (Ninguno)
		{
		case Direccion::Arriba:
				indiceX = 0; indiceY = 3; break;

		case Direccion::Abajo:
				indiceX = 0; indiceY = 0; break;

		case Direccion::Izquierda:
				indiceX = 0; indiceY = 1; break;

		case Direccion::Derecha:
				indiceX = 0; indiceY = 2; break;
		}
		break;
	}

	Pintar(buffer, imgPersonaje);
}

void CJugador::Pintar(BufferedGraphics ^buffer, Bitmap ^imgPersonaje){
	Rectangle porcionUsar = Rectangle(ancho*indiceX, alto*indiceY,ancho,alto);
	Rectangle aumentoPersonaje = Rectangle(x,y,ancho*0.4,alto*0.4);
	buffer->Graphics->DrawImage(imgPersonaje,aumentoPersonaje,porcionUsar,GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}