#include <SoftwareSerial.h> 
SoftwareSerial gsmSerial(2,3);
int pin = 0;
int tempc = 0; 
void setup()
{
gsmSerial.begin(9600);
delay(5000);
}
void loop() {
tempc = 0;
tempc = ( 5.0 * analogRead(pin) * 100.0) / 1024.0;
sendTextMessage();
delay(90000);
}
void sendTextMessage() {
gsmSerial.print("AT+CMGF=1\r");
delay(100);
gsmSerial.println("AT+CMGS=\"+71234567890\"");
delay(100);
gsmSerial.print("Temp: ");
gsmSerial.print(tempc);
gsmSerial.println(" C");
delay(100);
gsmSerial.println((char)26);
}
