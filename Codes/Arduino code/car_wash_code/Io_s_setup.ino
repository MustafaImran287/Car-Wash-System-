void io_setup()
{
  pinMode(relay_water_pump, OUTPUT);
  pinMode(relay_soap_pump, OUTPUT);
  pinMode(relay_reverse_inverter, OUTPUT);
  pinMode(relay_forward_inverter, OUTPUT);
  
  pinMode(forward_limit_s, INPUT_PULLUP);
  pinMode(reverse_limit_s, INPUT_PULLUP);
  pinMode(home_s, INPUT_PULLUP);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);

  digitalWrite(relay_forward_inverter, HIGH);
  digitalWrite(relay_reverse_inverter, HIGH);
  digitalWrite(relay_soap_pump, HIGH);
  digitalWrite(relay_water_pump, HIGH);

  
}
