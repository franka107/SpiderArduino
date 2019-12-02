

//#include <Arduino.h>
#include <Servo.h>

class Pata
{
private:
  // pines para los servos:
  int hombro = 0, codo = 1, mano = 2;
  int delayEntreServos = 300;
  int delayEntrePosiciones = 300;

  int hombro_pos_ini,codo_pos_ini,mano_pos_ini;

  int pos_hombro_adelante, pos_hombro_atras;
  int pos_codo_arriba,pos_mano_arriba;
  int pos_codo_abajo, pos_mano_abajo;

  Servo servo[3];
  void brazoCodoArriba()
  {
    //moverServo(mano, pos_mano_arriba,true);
    moverServo(codo, pos_codo_arriba,true);
  }

  void brazoCodoAbajo()
  {
    //moverServo(mano, pos_mano_abajo, true);
    moverServo(codo, pos_codo_abajo, true);
  }

  void moverServo(int servo_num, int pos, boolean con_delay) // TO DO: cuando un servo no llega a su posición se calienta la fuente, corregir esto
  {
    do
    {
      servo[servo_num].write(pos);
      //Serial.println("dentro de mover servo");
      if(con_delay){
      delay(delayEntreServos);
      }
    } while (!verificarPosicion(servo_num, pos));
  }

public:

  void setPosesCodoManoArriba(int pos_codo_arriba, int pos_mano_arriba){
    this->pos_codo_arriba=pos_codo_arriba;
    this->pos_mano_arriba=pos_mano_arriba;
  }

  void setPosesCodoManoAbajo(int pos_codo_abajo, int pos_mano_abajo){
    this->pos_codo_abajo = pos_codo_abajo;
    this->pos_mano_abajo = pos_mano_abajo;
  }

  // Función que enlaza los objetos servos con el pin correspondiente
  void init(int hombro_init, int codo_init, int mano_init)
  {
    servo[0].attach(hombro_init); // hombro 4
    servo[1].attach(codo_init);   // codo 2
    servo[2].attach(mano_init);   // mano 3
  }

  void posInicial()
  {
    moverServo(hombro, hombro_pos_ini, true); // hombro 4
    moverServo(codo, codo_pos_ini, true);     // codo 2
    moverServo(mano, mano_pos_ini, true);     // mano 3
    delay(delayEntrePosiciones * 2);
  }

  void posInicial(int hombro_pos_ini, int codo_pos_ini, int mano_pos_ini)
  {
    this->hombro_pos_ini = hombro_pos_ini;
    this->codo_pos_ini = codo_pos_ini;
    this->mano_pos_ini = mano_pos_ini;
    
    moverServo(hombro, hombro_pos_ini, true); // hombro 4
    delay(delayEntreServos/2);
    moverServo(codo, codo_pos_ini, true); // codo 2
    delay(delayEntreServos/2);
    moverServo(mano, mano_pos_ini, true); // mano 3
    delay(delayEntrePosiciones);
    
  }

  void setPosesHombro(int pos_hombro_adelante, int pos_hombro_atras){
    this->pos_hombro_adelante = pos_hombro_adelante;
    this->pos_hombro_atras = pos_hombro_atras;
  }

  void posAtras(boolean intermedio)
  {
    // paso intermedio atras
    if (intermedio)
    {
      brazoCodoArriba();
    }
    // paso final atras
    moverServo(hombro, pos_hombro_atras, true);
    brazoCodoAbajo();
  }

  void posAdelante(boolean intermedio)
  {
    // paso intermedio delante
    if (intermedio)
    {
      brazoCodoArriba();
    }
    // paso final delante
    moverServo(hombro, pos_hombro_adelante, true);
    brazoCodoAbajo();
  }

  void pasoEnSuDireccion()
  {
    posAdelante(true);
    //delay(delayEntrePosiciones);
  }

  void pasoContraDireccion()
  {
    posAtras(true);
    //delay(delayEntrePosiciones);
  }

  boolean verificarPosicion(int servo_num, int pos_deseada)
  {
    if (servo[servo_num].read() >= pos_deseada * 0.95 && servo[servo_num].read() <= pos_deseada * 1.05)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void avance(){
    moverServo(hombro,hombro_pos_ini, false);
  }

  void abajo(){
    moverServo(codo,180, false);
    moverServo(mano,170, false);
    //delay(200);
   
  }
  void arriba(){
    posInicial();
  }

};
