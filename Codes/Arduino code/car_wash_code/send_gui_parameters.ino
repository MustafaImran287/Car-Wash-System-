void send_initial_par_to_pi()
{
  int chk = 0;
    while (chk == 0)
    {
      Serial.println(water_level_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
          if (reply == "PiRec0")
            {
            
              chk = 1;
            }
      }
    }

  while (chk == 1)
    {
      Serial.println(soap_level_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec1")
            {
              
              chk = 2;
            }
      }
    }
	
  while (chk == 2)
    {
      Serial.print("t");
      Serial.println(temperature);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
        
          if (reply == "PiRec2")
            {
             
              chk = 3;
            }
      }
    }

  while (chk == 3)
    {
      Serial.print("h");
      Serial.println(humidity);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec3")
            {
              
              chk = 4;
            }
      }
    }

  while (chk == 4)
    {
      Serial.println(motor_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
        
          if (reply == "PiRec4")
            {
             
              chk = 5;
            }
      }
    }
	
  while (chk == 5)
    {
      Serial.println(home_sensor_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec5")
            {
              
              chk = 6;
            }
      }
    }

    while (chk == 6)
    {
      Serial.println(forward_sensor_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
        
          if (reply == "PiRec6")
            {
              
              chk = 7;
            }
      }
    }

    while (chk == 7)
    {
      Serial.println(reverse_sensor_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec7")
            {
              
              chk = 8;
            }
      }
    }

    while (chk == 8)
    {
      Serial.println(water_pump_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
        
          if (reply == "PiRec8")
            {
           
              chk = 9;
            }
      }
    }

    while (chk == 9)
    {
      Serial.println(soap_pump_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec9")
            {
             
              chk = 10;
            }
      }
    }

   while (chk == 10)
    {
      Serial.print("p");
      Serial.println(progress);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec10")
            {
             
              chk = 11;
            }
      }
    }

    while (chk == 11)
    {
      Serial.print("g");
      Serial.println(percentage);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
        
          if (reply == "PiRec11")
            {
           
              chk = 12;
            }
      }
    }
	
	while (chk == 12)
    {
      Serial.println(finish_s);
      Serial.println("");
      if (Serial.available() > 0) 
      {
          String reply = Serial.readStringUntil('\n');
         
          if (reply == "PiRec12")
            {
           
              chk = 13;
            }
      }
    }

   

   

}
