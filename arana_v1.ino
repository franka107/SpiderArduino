
#include "Pata.h"
#include <Servo.h>

 // (hombro, codo, mano)
Pata izqAdelante, izqAtras, derAdelante, derAtras;

void setup()
{
  Serial.begin(9600);

  derAdelante.init(4, 2, 3);
  derAdelante.posInicial(130, 90, 90);
  derAdelante.setPosesHombro(170, 90); // primero:160,70
  derAdelante.setPosesCodoManoArriba(40, 150);
  derAdelante.setPosesCodoManoAbajo(90, 120);

  izqAtras.init(13, 11, 12);
  izqAtras.posInicial(130, 90, 90);
  izqAtras.setPosesHombro(170, 90); // primero:160,70
  izqAtras.setPosesCodoManoArriba(40, 150);
  izqAtras.setPosesCodoManoAbajo(90, 120);

  //_____________________________________________________

  izqAdelante.init(10, 8, 9);
  izqAdelante.posInicial(50, 90, 90);
  izqAdelante.setPosesHombro(30, 90); // primero:20,100
  izqAdelante.setPosesCodoManoArriba(150, 40);
  izqAdelante.setPosesCodoManoAbajo(90, 90);

  derAtras.init(7, 5, 6); 
  derAtras.posInicial(50, 90, 90);
  derAtras.setPosesHombro(30, 90); // primero:20,100
  derAtras.setPosesCodoManoArriba(150, 40);
  derAtras.setPosesCodoManoAbajo(90, 90);

  delay(1000);

  Serial.println("fin de setup");
  
  //PARARSE:
  /*
  derAdelante.abajo();
  izqAtras.abajo();
  izqAdelante.abajo();
  derAtras.abajo();
*/
  /*
  derAdelante.arriba();
  izqAtras.arriba();
  izqAdelante.arriba();
  derAtras.arriba();
  */
}

void loop()
{
  
  //avanzar(200);
  //retroceder(200);
  //girarIzq(200);
  girarDer(200);
}

void avanzar(int tiempoEntrePasos){
  
  //CAMINANDO

  izqAtras.pasoContraDireccion();
  izqAdelante.pasoEnSuDireccion();

  derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

  delay(tiempoEntrePasos);

  derAtras.pasoContraDireccion();
  derAdelante.pasoEnSuDireccion();

  derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

  delay(tiempoEntrePasos);
}

void retroceder(int tiempoEntrePasos){
  
  
  izqAdelante.pasoContraDireccion();
  izqAtras.pasoEnSuDireccion();

  derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

  delay(tiempoEntrePasos);

  
  derAdelante.pasoContraDireccion();
  derAtras.pasoEnSuDireccion();

  derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

    delay(tiempoEntrePasos);

}


void girarIzq(int tiempoEntrePasos){
  izqAdelante.pasoContraDireccion();
  izqAtras.pasoEnSuDireccion();



  derAtras.pasoContraDireccion();
  derAdelante.pasoEnSuDireccion();

   derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

  delay(tiempoEntrePasos);
}

void girarDer(int tiempoEntrePasos){

  derAtras.pasoEnSuDireccion();
  derAdelante.pasoContraDireccion();
  
  izqAtras.pasoContraDireccion();
  izqAdelante.pasoEnSuDireccion();

  derAdelante.avance();
  derAtras.avance();
  izqAdelante.avance();
  izqAtras.avance();

  delay(tiempoEntrePasos);
}