inherit "obj/armour";

reset(arg){
 if(arg)return;
  set_name("armour");
  set_short("Black Armour");
  set_long("This black armour is composed of thousands of small rings all\n"+
           "woven together in fine mesh.  Its looks very strong.\n");
  set_ac(5);
  set_weight(7);
  set_type("armour");
  set_size("large");
  set_value(3000);
 }
