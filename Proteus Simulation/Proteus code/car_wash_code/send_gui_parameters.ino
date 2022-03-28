void send_initial_par_to_pi()
{
  
   
}

void display_oled_string(String s1)
{
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setCursor(1, 1);
   display.print(s1);
   display.display(); 
 

}

void display_oled_int(int i1)
{
   display.clearDisplay();
   display.setTextColor(WHITE);
   display.setCursor(1, 1);
   display.print(i1);
   display.display(); 


}
