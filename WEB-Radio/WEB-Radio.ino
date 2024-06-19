/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: ESP32 WEB-Radio - WEB-Server - AP-WLAN Config
Senderliste: https://rrradio.de/radiosender/
**************************************************************************************************
Version: 15.01.2023
**************************************************************************************************
Board: ESP32vn IoT UNO  V1.0.6
**************************************************************************************************
Libraries:
ai-esp32-rotary-encoder-master
LiquidCrystal_I2C-master
**************************************************************************************************
C++ Arduino IDE V1.8.19
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json
*************************************************************************************************

 * WEB-Radio
 * Following Parts:
 * - audio          : streaming and decoding audio data
 * - lcdisplay      : show station data an LCD
 * - rotary         : initialize and handle choosing senders
 * - senderlist     : senderlist by flash-values - or, if not present, by defaults
 * - senderconfig   : asynchronus webinterface to store sendernames und -urls
 *   senderconf.h   : html-template for above
 * - wlanconfig     : seperate program to get WLAN-config per webinterface
 *   wlanconf.h     : html-template for above
 *   
 *   Used libraries (included in their parts): 
 *   - ESPwebRadio  : Preferences.h
 *   - audio        : ESP8266audio (AudioFileSourceICYStream.h, AudioFileSourceBuffer.h, AudioGeneratorMP3.h, AudioOutputI2S.h)
 *   - lcdisplay    : LiquidCrystal_I2C.h
 *   - rotary       : AiEsp32RotaryEncoder.h
 *   - senderconfig : ESPAsyncWebServer.h, Preferences.h
 *   - wlanconfig   : WiFi.h, Preferences.h, ESPAsyncWebServer.h
 */

#include <Preferences.h>

//structure for stationlist
typedef struct {
  char url[100];  //stream url
  char name[100]; //stations name
} Station;

#define STATIONS 21 //0-21 number of available stations

//station list (stations can now be modified by webinterface)
Station stationlist[STATIONS];

//instances of prefernces
Preferences pref;
Preferences sender;

//global variables
uint8_t curStation = 0;   //index for current selected station in stationlist
uint8_t actStation = 0;   //index for current station in station list used for streaming 
uint32_t lastchange = 0;  //time of last selection change


//setup
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // -------------------
  setup_senderList();
  setup_audio();
  setup_rotary();
  setup_lcdisplay();
  //init WiFi
  Serial.println("Connecting to WiFi");
  while (!makeWLAN()) {
    Serial.println("Cannot connect :(");
    delay(1000);
  }
  Serial.println("Connected");
  setup_senderConfig();
  // -------------------

  //set current station to 0
  curStation = 0;
  //start preferences instance
  pref.begin("radio", false);
  //set current station to saved value if available
  if (pref.isKey("station")) curStation = pref.getUShort("station");
  //set active station to current station 
  //show on display and start streaming
  actStation = curStation;
  showStation();
  startUrl();
}

// main loop
void loop() {
  //check if stream has ended normally not on ICY streams
  if (!loop_audio()) {
    Serial.printf("MP3 done\n");

    // Restart ESP when streaming is done or errored
    delay(10000);

    ESP.restart();
  }
  //read events from rotary encoder
  rotary_loop();

}
