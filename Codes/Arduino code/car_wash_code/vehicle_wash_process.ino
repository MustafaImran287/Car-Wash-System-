void vehicle_wash_process(int total_cycles, int water_cycles, int soap_cycles)
{ 
  int total_c = 1;
  int water_c = 1;
  int soap_c = 1;
  int prog = 0;
  int w_prog = 0;
  int s_prog = 0;
  int w_prog2 = 0;
while (total_c <= total_cycles)
{
while (water_c <= water_cycles)
{
    check = 1;
    water_spray();
	progress = "First Water Spray done";
	send_initial_par_to_pi();
	w_prog = (33 / ((total_cycles +1)-total_c)) * (1/((water_cycles + 1)- water_c));
	prog = w_prog + s_prog + w_prog2;
	percentage = String(prog);
	send_initial_par_to_pi();
	water_c++;
    
}
delay(w_s_delay*1000);

while (soap_c <= soap_cycles)
{
    check = 1;
    soap_spray();
	progress = "Soap Spray done";
	send_initial_par_to_pi();
	s_prog = (33 / ((total_cycles +1)-total_c)) *(1/((soap_cycles + 1)-  soap_c));
	prog = w_prog + s_prog + w_prog2;
	percentage = String(prog);
	send_initial_par_to_pi();
	soap_c++;
    

}
delay(s_w_delay*1000);
water_c = 1;
while (water_c <= water_cycles)
{
    check = 1;
    water_spray();
	progress = "Second Water Spray done";
	send_initial_par_to_pi();
	w_prog2 = (33 / ((total_cycles +1)-total_c)) * (1/((water_cycles + 1)- water_c));
	prog = w_prog + s_prog + w_prog2;
	percentage = String(prog);
	send_initial_par_to_pi();
	water_c++;
    
}

total_c++;
water_c = 1;
soap_c = 1;

}
   
    start = false;
  
}
