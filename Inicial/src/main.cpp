#include <Arduino.h>
#include <Bounce2.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


#define pinLed 5
#define buttonPinUp 2
#define buttonPinDown 4
LiquidCrystal_I2C lcdzinho(0x27,20,4);

int brightnessIntensity = 0; // Nível de 0 a 100

Bounce debouncer_1 = Bounce();
Bounce debouncer_2 = Bounce();

/*
bool estadoAnteriorBotao = 0;
bool estadoBotao = 0; 
bool estadoLed = 0;

void setup() {
 Serial.begin(9600);

 pinMode(pinLed, OUTPUT);
 
 pinMode(pinBotao, INPUT_PULLUP);
}

void loop() {
 estadoBotao = digitalRead (pinBotao);
  
  //botao clicado
  if (estadoAnteriorBotao == 0 && estadoBotao == 1){
      estadoLed = !estadoLed; //! significa diferente
  }
 
  
  if (estadoLed == 1){
    digitalWrite(pinLed, HIGH);
  }
  else {
    digitalWrite(pinLed, LOW);
  }
  
  estadoAnteriorBotao = estadoBotao;

}*/

/*Objetos
Bounce btn = Bounce();

void setup() {
  Serial.begin(9600);
  btn.attach(pinBotao1, INPUT_PULLUP);//pinMode
}

void loop() {
  btn.update();//digitalRead

  Serial.println(btn.fell());
  //pressionado - retorna true quando o botao for pressionado
  
  Serial.println(btn.read());
  //le o botao e retorna a leitura
  
  Serial.println(btn.rose());
  //retorna true quando o botao for solto
  
   Serial.println(btn.changed());
  //retorna true quando existe uma alteração
  
  
   Serial.println(btn.currentDuration());
  //retorna o tempo do estado atual do botao
  
  Serial.println(btn.previousDuration());
  //retorna o tempo do estado anterior do botao

  delay(1000);
}*/

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  
  digitalWrite(pinLed, LOW); 

  debouncer_2.attach(buttonPinDown, INPUT_PULLUP);
  debouncer_2.interval(25);
  debouncer_1.attach(buttonPinUp, INPUT_PULLUP);
  debouncer_1.interval(25);

  lcdzinho.init();//inicia
  lcdzinho.backlight();


  Serial.println("Pronto para controlar o brilho. Use os botões.");
}

void loop() {
  debouncer_1.update();
  debouncer_2.update();

  if (debouncer_1.fell()) {
    if (brightnessIntensity < 100) {
      brightnessIntensity += 10;
    }
  }

  if (debouncer_2.fell()) {
    if (brightnessIntensity > 0) {
      brightnessIntensity -= 10;
    }
  }

  int brightnessValue = map(brightnessIntensity, 0, 100, 0, 255);

  analogWrite(pinLed, brightnessValue);
  Serial.println(brightnessValue);
  
 
  delay(20); 

}