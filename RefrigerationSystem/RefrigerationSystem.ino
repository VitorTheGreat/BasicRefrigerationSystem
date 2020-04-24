// LCD
#include <LiquidCrystal.h> // Adiciona a biblioteca "LiquidCrystal" ao projeto
LiquidCrystal lcd(12, 13, 7, 6, 5, 4); // Pinagem do LCD

const int sensorPin = A2; //Pino analógico usado pelo sensor
float temperatura = 0; //Variavel do tipo float para a temperatura

//rele
int sinalparaorele = 2; //Pino onde o rele esta conectado

void setup()
{
  lcd.begin(16, 2); // Inicia o lcd de 16x2
  pinMode(sinalparaorele, OUTPUT); //Define o pino como saida
}

void loop()
{
    
  temperatura = (analogRead(sensorPin) * 0.0048828125 * 100); //Conta para mostrar a temperatura em Celsius

  if (temperatura > 25.55) { //Se a temperatura for maior que 25.55
    digitalWrite(sinalparaorele, HIGH); //Aciona o rele
  }
  else { //Se não
    digitalWrite(sinalparaorele, LOW); //Desliga o rele
  }
  
  lcd.setCursor(2, 0);      // 2 = 2 colunas para a direita. 0 = Primeira linha
  lcd.print("Temperatura"); // Imprime um texto
  lcd.setCursor(2, 1);      // 2 = 2 colunas para a direita. 1 = Segunda linha
  lcd.print(temperatura);   //Imprime a temperatura no display
  delay(1000); //INTERVALO DE 1 SEGUNDO

}
