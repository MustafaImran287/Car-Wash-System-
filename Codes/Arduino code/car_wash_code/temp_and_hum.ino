void temp_hum()
{
   int data=DHT.read11(DHT_Pin);
   int  temp= DHT.temperature;
   int hum=DHT.humidity;
  
   temperature = String(temp);
   humidity = String (hum);
   if (temp < optimal_temperature1)
   {
      send_initial_par_to_pi();
	    all_good = false;
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
    
   }
  

}
