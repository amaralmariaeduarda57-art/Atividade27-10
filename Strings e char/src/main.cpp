#include <Arduino.h>

//char - mais recomendado para uso profissional
//String - mais facil

char palavra[] = {'O','l','a',' ','M','u','n','d','o','\0'};
char palavra2 []= "Ola Mundo";
String palavra3 = "Ola Mundo";
palavra3.toLowerCase();
String palavra3Lower = palavra3;

void setup() {
  Serial.begin(9600);
  Serial.println();  
  Serial.println(palavra2);  

  //-------------------------- Funcoes para char ------------------------------
strcpy(palavra2, "Senai"); //substitui o valor anterior
//Serial.println(palavra2);

//Serial.println(strncmp(palavra2, "Senai")); //se for igual retorna 0
//if (strcmp(palavra2, "Senai") == 0) {

  //Serial.println("São iguais");
//}

//else{
//Serial.println("São diferentes"); 

//}

Serial.println(strncmp(palavra2, "Senai", 5)); 
//compara a quantidade de caracteres

if(!strncmp(palavra2, "Senai", 5)); {
}

//Serial.println("Quantidade de caracteres iguais");
//}

//strstr(); //procura dentro da string pela primeira ocorrencia de uma substring
//if(strstr(palavra2, "NAI")) 
//{
//Serial.println("palavra encontrada");
//}
//Serial.println(strcat(palavra2, "-SP")); 
//concatena duas strings, ou seja junta
 

//---------------------------Funcoes para string------------------------------
//Serial.println(palavra3.length()); //retorna a quantidade de caracteres
//Serial.println(palavra3.charAt(2)); //retorna o caracter da posição indicada
//Serial.println(palavra3.substring(2, 5)); //retorna um pedaço da string original
//Serial.println(palavra3.indexOf('M')); //retorna a posição do elemento procurado
//Serial.println(palavra3.indexOf('O')); //retorna a posição do ultimo elemento procurado

//equals() //Compara se é igual
//if(palavra3.equalsIgnoreCase("ola mundo"))
//Serial.println("Iguais");{
//}

//if(palavra3.startsWith("Ola")) 
//Serial.println("o inicio e igual");{
//}

//if(palavra3.endsWith("DO)"))
//{Serial.println("o fim e igual");}


//palavra3.toUpperCase();//converte para caixa alta
//palavra3.toLowerCase();//converte para caixa baixa
//Serial.println(palavra3);

//String valor = "100";
//int numero = valor.toInt(); 
//float numeroF = valor.toFloat(); 

String texto = "texto            ";
texto.trim(); //remove espaços em branco 

String instrucao = "Led = ON";
instrucao.replace("ON", "OFF");

}

void loop() {
  
}


