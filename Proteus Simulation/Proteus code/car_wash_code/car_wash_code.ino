#include<EEPROM.h>
#include<Wire.h>
#include <SPI.h>
#include<SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht.h>

dht DHT;

#define relay_water_pump 4  //relay trigger pin for water pump
#define relay_soap_pump 5   //relay trigger pin for soap pump
#define relay_reverse_inverter 6   //relay trigger pin for reverse inverter
#define relay_forward_inverter 7   //relay trigger pin for forward inverter

#define forward_limit_s 13   //forward limit sensor
#define home_s 12  // home sensor
#define reverse_limit_s 11   // reverse limit sensor

#define DHT_Pin 10           // temperatue and humidity pin
#define trigger 9 
#define echo 8
#define trigger2 3
#define echo2 2

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);




int check = 1;
int count = 1;

long total_cycle = 1;
long water_cycle = 1;
long soap_cycle = 1;
long w_s_delay = 1;
long s_w_delay = 1;

int optimal_temperature1 = 25;
int optimal_temperature2 = 50;
long optimal_water_level = 150;
long optimal_soap_level = 150;
int time_for_cycle = 10;   //in seconds

String input;
String car_type = "nill";


int chk_serial = 0;
bool all_good = false;
bool start = false;

String water_level_s = "WLL";  //WLH,WLL,WLF
String soap_level_s = "SLL";   //SLH,SLL,SLF
String home_sensor_s = "NSH";  //NSH,SSH
String forward_sensor_s = "NSF"; //NSF,SSF
String reverse_sensor_s = "NSR";  //NSR,SSR
String water_pump_s = "WPF";  //WPF,WPO
String soap_pump_s = "SPF";   //SPF,SPO
String motor_s = "MF";       //MF,MO
String temperature = "0";
String humidity = "0";
String progress = "0";
String percentage = "0";
String finish_s = "NFIN"; //FIN,NFIN


void setup() {
  
  Serial.begin(9600);
  io_setup();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
   { 
   Serial.println(F("SSD1306 allocation failed"));
   for(;;);
   }

}

void loop() {
  percentage = "0";
  finish_s = "NFIN";
  receive_gui_parameters();
  do{
     temp_hum();
     delay(1000);
     water_level();
     delay(1000);
     soap_level();
     delay(1000);
     
	 }
  while(all_good == false);
  display_oled_string("System finding home");
  find_home();
  display_oled_string("System at home");
  delay(1000);
  start = true;
  if(start == true)
  {
  vehicle_wash_process(total_cycle,water_cycle,soap_cycle);
	finish_s = "FIN";
	send_initial_par_to_pi();
  delay(1000);
  }
  all_good = false;

  

}
