void compare_car_type(String car1)
{
   if (car1 == "Sedan")
   { 
     

     display_gui_parameters(car1);
     
    }
   else if (car1 == "MPV")
   {
     display_gui_parameters(car1);
   }

   else if (car1 == "MiniCar")
   { 
     
      display_gui_parameters(car1);
    
   }


}


void display_gui_parameters(String car)
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(1, 1);
  display.print("Selected Car = ");
  display.println(car);
  display.display(); 
  delay(1000);
   display.clearDisplay();
     display.setTextColor(WHITE);
     display.setCursor(1, 1);
     display.print("Total Cycles = ");
     display.println(total_cycle);
     display.display(); 
     delay(1000);

     display.clearDisplay();
     display.setTextColor(WHITE);
     display.setCursor(1, 1);
     display.print("Water Cycles = ");
     display.println(water_cycle);
     display.display(); 
     delay(1000);

     
     display.clearDisplay();
     display.setTextColor(WHITE);
     display.setCursor(1, 1);
     display.print("Soap Cycles = ");
     display.println(soap_cycle);
     display.display(); 
     delay(1000);

     display.clearDisplay();
     display.setTextColor(WHITE);
     display.setCursor(1, 1);
     display.print("First delay = ");
     display.println(w_s_delay);
     display.display(); 
     delay(1000);

     display.clearDisplay();
     display.setTextColor(WHITE);
     display.setCursor(1, 1);
     display.print("Second delay = ");
     display.println(s_w_delay);
     display.display(); 
     delay(1000);


}
