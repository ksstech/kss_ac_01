#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti WiFiMulti;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}


void loop() 
{
int cn=0;
String ssid;  

   Serial.println("\n\n   WIFI scan start ... ");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println(" Done.");
    if (n == 0) {
        Serial.println("   no networks found");
    } else {
        Serial.print("   ");
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print("   ");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print("\t\t");
            Serial.print(WiFi.RSSI(i));
            Serial.print("dBm");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }


Serial.println("\n  WIFI Client Test\r\n  Enter data in this style : SSID,Passwd \n");
while (ssid!=String("exit"))
{    
    if (Serial.available() > 0)
    {
        // First read the string until the ',' in your example
        // "ssid,paaswd" this would read the "ssid" as a String
        ssid = Serial.readStringUntil(',');
        // We now have "passwd\n" left in the Serial buffer, so we read that.
        // The end of line character '\n' or '\r\n' is sent over the serial
        // terminal to signify the end of line, so we can read the
        // remaining buffer until we find that.
        String passwd = Serial.readStringUntil('\n');

      if (ssid!=String("exit"))
      {
        Serial.print("    SSID : ");
        Serial.println(ssid);
        Serial.print("  Passwd : ");
        Serial.println(passwd);

        // We start by connecting to a WiFi network
        WiFiMulti.addAP(ssid.c_str(), passwd.c_str());

        Serial.print("\n  Waiting for WiFi : ");

           while(WiFiMulti.run() != WL_CONNECTED) {
               Serial.print(".");
               delay(100);
               cn++;
               if (cn==12) 
               {
               Serial.println("\r\n  Connection ERROR! Check your setup and credentials"); 
               break;
               }            
           }

         if (cn<12){
         Serial.print("Connected!\r\n  IP address: ");
         Serial.println(WiFi.localIP());
         delay(500);   
         }
         //Serial.println("\n  Done.");
      }
   }
}
delay(5000);
Serial.println("\r\n  WIFI test done. restarting...\n\n");
}
