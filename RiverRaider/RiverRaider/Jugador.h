#pragma once
using namespace System::Drawing;
enum Direccion{ Ninguno, Arriba, Abajo, Derecha, Izquierda };

class CJugador
{
protected:
	int x, y,alto, ancho, indiceX, indiceY, dx, dy;
	Direccion ultima;
	
public:
	CJugador();
	~CJugador();
	CJugador(int x, int y);

	Direccion direccion;
	void Mover(BufferedGraphics ^buffer, Bitmap ^imgPersonaje);
	void Pintar(BufferedGraphics ^buffer, Bitmap ^imgPersonaje);
};

