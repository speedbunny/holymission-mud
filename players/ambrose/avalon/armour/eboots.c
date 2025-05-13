inherit "obj/armour";

reset(arg){
 if(arg)return;


  set_name("boots");
  set_short("Black Boots");
  set_long("These long black boots fit snugly on your feet.  Not only\n"+
           "will these protect your feet, but they protect your lower leg\n"+
           "from attack.\n");
  set_value(300);
  set_weight(2);
  set_ac(2);
  set_type("boot");
  set_size("large");
 }
