/* I have an untracked file called secrets.h with the following code
//========================= Variables for wifi server setup =============================

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "your_ssid_here"; // WiFi Router ssid
char pass[] = "your_secret_here"; // WiFi Router password

// copy it from the mail received from Blynk
char auth[] = "your_secret_here";
//const char* server = "api.thingspeak.com";

// Thingspeak Write API
const char* server = "api.thingspeak.com";
const char* api_key = "your_secret_here"; // API write key
*/

//============================ Connect to WiFi Network =========================================

void wifi_connect()
{
  if (App == "BLYNK")  // for posting datas to Blynk App
  {
    Serial.printf("Connecting to %s\n", App);
    Blynk.begin(auth, ssid, pass);
  }
  else if (App == "Thingspeak")  // for posting datas to Thingspeak website
  {
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      //  Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
  }
  else
  {
    WiFi.begin(ssid, pass);
    //Serial.print(App);
    Serial.println(" is not a valid application");
  }

}
