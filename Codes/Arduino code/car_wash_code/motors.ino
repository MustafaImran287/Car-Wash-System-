void motor_fwd()
{
  digitalWrite(relay_forward_inverter, LOW);
  digitalWrite(relay_reverse_inverter, HIGH);
  motor_s = "MO";
 
  if(count == 1)
  {
      forward_sensor_s = "SSF";
      reverse_sensor_s = "NSR";
      home_sensor_s = "NSH"; 
      send_initial_par_to_pi();
    count=2;
  }
  if(count == 3)
  {
      forward_sensor_s = "SSF";
      reverse_sensor_s = "NSR";
      home_sensor_s = "NSH"; 
      send_initial_par_to_pi();
    count=4;
  }
}
void motor_bwd()
{
   motor_s = "MO";
  digitalWrite(relay_forward_inverter, HIGH);
  digitalWrite(relay_reverse_inverter, LOW);
  if(count == 2)
  {
      forward_sensor_s = "NSF";
      reverse_sensor_s = "SSR";
      home_sensor_s = "NSH"; 
      send_initial_par_to_pi();
    count=3;
  }
}
void motor_stop()
{
  motor_s = "MF";
  water_pump_s = "WPF";
  soap_pump_s = "SPF";
  forward_sensor_s = "NSF";
  reverse_sensor_s = "NSR";
  home_sensor_s = "SSH"; 
  send_initial_par_to_pi();
  digitalWrite(relay_forward_inverter, HIGH);
  digitalWrite(relay_reverse_inverter, HIGH);
  digitalWrite(relay_water_pump, HIGH);
  digitalWrite(relay_soap_pump, HIGH);
  if(count == 4)
  {
    count=1;
  }
}

void find_home()
{ 
  int check_home = 0;
  while( check_home == 0)
  {
  int loop_count = 0;
  progress = "System finding home !!!";
  send_initial_par_to_pi();
  int loop_limit = (time_for_cycle * 1000)/100;
  if (digitalRead(home_s))
  {
	  digitalWrite(relay_forward_inverter, LOW);
	  digitalWrite(relay_reverse_inverter, HIGH);
	  motor_s = "MO";
	  forward_sensor_s = "SSF";
      reverse_sensor_s = "NSR";
      home_sensor_s = "NSH"; 
      send_initial_par_to_pi();
  
   do
   {
     if (!digitalRead(home_s)) 
	 {
	  digitalWrite(relay_forward_inverter, HIGH);
      digitalWrite(relay_reverse_inverter, HIGH);
	  motor_s = "MF";
	  forward_sensor_s = "NSF";
      reverse_sensor_s = "NSR";
      home_sensor_s = "SSH"; 
      progress = "Home Reached !!!";
      send_initial_par_to_pi();  
      loop_count = loop_limit;
	  check_home = 1;
	  return;
        
    }
   else 
        {
          loop_count++;
        }
  delay(100);   
   }
   while(loop_count < loop_limit);
   loop_count = 0;
   
   digitalWrite(relay_forward_inverter, HIGH);
   digitalWrite(relay_reverse_inverter, LOW);
   motor_s = "MO";
   forward_sensor_s = "NSF";
   reverse_sensor_s = "SSR";
   home_sensor_s = "NSH"; 
   send_initial_par_to_pi();
   do
   {
     if (!digitalRead(home_s)) 
	 {
	  digitalWrite(relay_forward_inverter, HIGH);
      digitalWrite(relay_reverse_inverter, HIGH);
	   motor_s = "MF";
	  forward_sensor_s = "NSF";
      reverse_sensor_s = "NSR";
      home_sensor_s = "SSH"; 
      progress = "Home Reached !!!";
      send_initial_par_to_pi();  
      loop_count = loop_limit;
	  check_home = 1;
	  return;
        
    }
   else 
        {
         loop_count++;
        }
  delay(100);   
   }
   while(loop_count < loop_limit);
  }
  else
  {
	  progress = "System at home !!!";
    send_initial_par_to_pi();
    check_home = 1;
    return;
  }
  
  
}

}
