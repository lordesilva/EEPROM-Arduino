/*
Zerar EEPROM
EEPROM = Endereços todos

*/

#include <EEPROM.h>

uint32_t EEPR=0;
String Rtx;
String Ttx;
uint8_t Valor;
uint16_t ini;
uint16_t fim;

void setup()
{
    Serial.begin(9600); 	// Inicializa a comunicação serial
	
	
	Serial.println("Para gravar na EEPROM,"); 
	Serial.println("enviar Gra mais os endereços de");
	Serial.println("inicio e de fim com 4 digitos,");
	Serial.println("mais o Valor a gravar com 3");
	Serial.println("digitos e maximo Valor de 255");
	Serial.println("Exemplo: Gra-0000-0200-255 ou Gra-0050-1500-000");
	Serial.println("");
	
	Serial.println("Para Ler da EEPROM,");
	Serial.println("enviar Ler mais o endereço de");
	Serial.println("inicio e de fim com 4 digitos");
	Serial.println("Exemplo: Ler-0000-0200 ou Ler-0050-0500");
			
}


void loop()
{
	
   if (Serial.available()>0)
	{
	 Rtx = Serial.readStringUntil('\n');

		if (Rtx.startsWith("Gra"))		// Gravar EEPROM
		{
		  Rtx.remove(0,4);
		//  Serial.println("Rtx");
		//  Serial.println(Rtx);
		  delay(300);
		  Ttx=Rtx.substring(0,4);
		//  Serial.println("Ttx");
		//  Serial.println(Ttx);
		  delay(300);
		  ini=Ttx.toInt();
		  Serial.println("ini");
		  Serial.println(ini);
		  delay(300);
		  Rtx.remove(0,5);
		  fim=Rtx.toInt();
		  Serial.println("fim");
		  Serial.println(fim);
		  delay(300);
		  Rtx.remove(0,5);
		  Valor=Rtx.toInt();
		  Serial.println("Valor");
		  Serial.println(Valor);
      Serial.println("");
		  Serial.println("+=+=+ GRAVANDO EEPROM +=+=+");
		  Serial.println("");
		  delay(300);
		 
			while (ini < fim) //mega
			{
			 EEPROM.write(ini,Valor);	
       delay(150);
			 Serial.println("");
			 Serial.print(ini);
			 Serial.println(" < EEPROM | Valor >");
       Serial.println(EEPROM.read(ini));		// Confirma dado gravado	 
			 ini++;
			}	
			Serial.println("");
			Serial.println("");
			Serial.println("Feito, Grato por usar nosso app.");
			Serial.println("           <Lorduino>");
		}
	
	
		if (Rtx.startsWith("Ler"))		// Ler EEPROM
		{ 
		  Rtx.remove(0,4);
		//  Serial.println("Rtx");
		//  Serial.println(Rtx);
		  delay(300);
		  Ttx=Rtx.substring(0,4);
		//  Serial.println("Ttx");
		//  Serial.println(Ttx);
		  delay(300);
		  ini=Ttx.toInt();
		  Serial.println("ini");
		  Serial.println(ini);
		  delay(300);
		  Rtx.remove(0,5);
		  fim=Rtx.toInt();
		  Serial.println("fim");
		  Serial.println(fim);
		  delay(300);
		  // Rtx.remove(0,5);
		  // Dado=Rtx.toInt();
		  // Serial.println("Dado");
		  //Serial.println(Dado);
          Serial.println("");
	      Serial.println("+=+=+ LEITURA EEPROM +=+=+");
		  Serial.println("");
		 
			while (ini < fim)
			{		     
			 Serial.println("");
			 Serial.print(ini);
			 Serial.println(" < EEPROM | Valor >");
			 Serial.println(EEPROM.read(ini));
			 delay(150);
			 ini++;
			} 
			 Serial.println("");
			 Serial.println("");
			 Serial.println("Feito, Grato por usar nosso app.");
			 Serial.println("           <Lorduino>");
		}
			
	}		
			 
}