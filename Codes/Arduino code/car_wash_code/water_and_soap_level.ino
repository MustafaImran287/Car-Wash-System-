void water_level()
{
  long duration, distance;
 
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  distance = convert_to_dis(duration);
  
   if (distance == 0)
   {
     water_level_s = "WLF";
     send_initial_par_to_pi();
     all_good = false;
   }
   if (distance <= optimal_water_level)
   {
    water_level_s = "WLH";
    send_initial_par_to_pi();
     if (all_good == true)
          {
             all_good = true;
          }
        else
          {
             all_good = false;
          }
   }
   else if (distance != 0 && distance > optimal_water_level)
   {
     water_level_s = "WLL";
     send_initial_par_to_pi();
	 all_good = false;
   }
  
 
}


void soap_level()
{
  long duration, distance;
  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger2, LOW);

  duration = pulseIn(echo2, HIGH);
  distance = convert_to_dis(duration);

   if (distance == 0)
   {
     soap_level_s = "SLF";
     send_initial_par_to_pi();
     all_good = false;
   }
   
   if (distance <= optimal_soap_level)
   {
    soap_level_s = "SLH";
    send_initial_par_to_pi();
     if (all_good == true)
          {
             all_good = true;
          }
       else
          {
             all_good = false;
          }
	
   }
   else if (distance != 0 && distance > optimal_soap_level)
   {
     soap_level_s = "SLL";
     send_initial_par_to_pi();
	   all_good = false;
   }
  
  
}

long convert_to_dis(long dur)
{
 return dur / 29 / 2;
}
