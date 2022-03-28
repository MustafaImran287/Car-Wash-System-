void receive_gui_parameters()
{
     chk_serial = 0;
  while( chk_serial != 6)
  {
    
   if ( chk_serial == 0){
      if (Serial.available() > 0) {
      car_type = Serial.readStringUntil('\n');
      Serial.println("car_rec");
      chk_serial = 1;
      }
      }
      if ( chk_serial == 1)
      {
      if (Serial.available() > 0) {
      water_cycle = Serial.readStringUntil('\n').toInt();
      Serial.println("wsc_rec");
      chk_serial = 2;
      }
      }
      if ( chk_serial == 2)
      {
      if (Serial.available() > 0) {
      soap_cycle = Serial.readStringUntil('\n').toInt();
      Serial.println("ssc_rec");
      chk_serial = 3;
      }
      }
      if ( chk_serial == 3)
      {
      if (Serial.available() > 0) {
      w_s_delay = Serial.readStringUntil('\n').toInt();
      Serial.println("dw_rec");
      chk_serial = 4;
      }
      }
      if ( chk_serial == 4)
      {
      if (Serial.available() > 0) {
      s_w_delay = Serial.readStringUntil('\n').toInt();
      Serial.println("ds_rec");
      chk_serial = 5;
  
      }
      }
      if ( chk_serial == 5)
      {
      if (Serial.available() > 0) {
      total_cycle = Serial.readStringUntil('\n').toInt();
      Serial.println("oc_rec");
      chk_serial = 6;
  
      }
      }
  }
      
     
  
}
