inherit "/players/goldsun/green_island/obj/genAxe";

 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_type(1);
 set_name(query_type()+" axe");
 set_alias("axe");
 set_short("A "+query_type()+" axe");
 set_long("The axe looks nice.\n");
 set_value(100);
 set_weight(1);
 }

