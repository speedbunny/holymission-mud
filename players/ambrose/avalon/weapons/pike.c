inherit"obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("pike");
  set_short("A sharp pike");
  set_long("This pike looks well cared for, ready to smite your enemies.\n");
  set_class(12);
  set_value(750);
  set_weight(4);
}
