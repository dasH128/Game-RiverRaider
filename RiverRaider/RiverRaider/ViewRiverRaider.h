#pragma once
#include "Jugador.h"

namespace RiverRaider {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ViewRiverRaider
	/// </summary>
	public ref class ViewRiverRaider : public System::Windows::Forms::Form
	{
	public:
		CJugador *oNave = new CJugador(150,0);
		Graphics ^g;
		BufferedGraphicsContext ^espacio;
		BufferedGraphics ^buffer;
		//Bitmap ^imgNave = gcnew Bitmap("img/helicoptero.png");
		//Bitmap ^imgNave = gcnew Bitmap("img/img_personaje01.png");
		Bitmap ^imgNave = gcnew Bitmap("img/img_personaje03.png");

		ViewRiverRaider(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewRiverRaider()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  Timer_Personaje;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Timer_Personaje = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// Timer_Personaje
			// 
			this->Timer_Personaje->Enabled = true;
			this->Timer_Personaje->Tick += gcnew System::EventHandler(this, &ViewRiverRaider::Timer_Personaje_Tick);
			// 
			// ViewRiverRaider
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 584);
			this->Name = L"ViewRiverRaider";
			this->Text = L"ViewRiverRaider";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ViewRiverRaider::PresionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &ViewRiverRaider::SoltarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
		void CrearBuffer(){
			g = this->CreateGraphics();
			espacio = BufferedGraphicsManager::Current;
			buffer = espacio->Allocate(g, this->ClientRectangle);
		}

	private: System::Void PresionarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		switch (e->KeyCode)
		{
		//case Keys::Up:
		//	oNave->direccion = Direccion::Arriba; break;

		//case Keys::Down:
		//	oNave->direccion = Direccion::Abajo; break;

		case Keys::Left:
			oNave->direccion = Direccion::Izquierda; break;

		case Keys::Right:
			oNave->direccion = Direccion::Derecha; break;

		case Keys::Space:
			MessageBox::Show("Disparar");
			
		}
	}
	private: System::Void SoltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		oNave->direccion = Direccion::Ninguno;
	}
	private: System::Void Timer_Personaje_Tick(System::Object^  sender, System::EventArgs^  e) {
		CrearBuffer();

		oNave->Mover(buffer, imgNave);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	};
}
