void water_spray()
{
  digitalWrite(relay_soap_pump, HIGH);
  while(check != 3)
  { 
    digitalWrite(relay_soap_pump, HIGH);
    digitalWrite(relay_water_pump, LOW);
    water_pump_s = "WPO";
    soap_pump_s = "SPF";
	progress = "Water Wash Cycle in Progress";
    send_initial_par_to_pi(); 
    motor_fwd();
    if(!digitalRead(forward_limit_s))
    {
      while(!digitalRead(forward_limit_s))
      {
      }
      
      check = 1;
      while(digitalRead(reverse_limit_s))
      {
        digitalWrite(relay_water_pump, LOW);
         water_pump_s = "WPO";
         soap_pump_s = "SPF";
         send_initial_par_to_pi(); 
         motor_bwd();
      }
      if(!digitalRead(reverse_limit_s))
      {
        while(!digitalRead(reverse_limit_s))
        {
        }
        check = 2;
        while(digitalRead(home_s))
        {
          digitalWrite(relay_water_pump, LOW);
           water_pump_s = "WPO";
           soap_pump_s = "SPF";
           send_initial_par_to_pi(); 
           motor_fwd();
        }
      }
      if(!digitalRead(home_s))
      {
        while(!digitalRead(home_s))
        {
        }
        check = 3;
        motor_stop();
      }
    }
  }
}
