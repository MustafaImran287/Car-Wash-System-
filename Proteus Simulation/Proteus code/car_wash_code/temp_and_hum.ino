void temp_hum()
{
   int data=DHT.read11(DHT_Pin);
   int  temp= DHT.temperature;
   int hum=DHT.humidity;
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setCursor(1, 1);
   display.print("Temperature = ");
   display.println(temp);
   display.print("Humidity = ");
   display.println(hum);
   display.display(); 
  
   temperature = String(temp);
   humidity = String (hum);
   if (temp < optimal_temperature1)
   {
      send_initial_par_to_pi();
	    all_good = false;
     display_oled_string("cannot start, optimal temeprature conditions fails");
   }
   else if (temp >= optimal_temperature1 && temp <= optimal_temperature2)
   {
          send_initial_par_to_pi();
    
             all_good = true;    
    
   }
   else
   {
      send_initial_par_to_pi();
    all_good = false;
    display_oled_string("cannot start, optimal temeprature conditions fails");
    
   }
  

}
