inherit "obj/armour";

reset(arg){
if(arg) return;
  set_name("gloves");
  set_short("Black Gloves");
  set_long("These black gloves seem to conform to your hands as you fit\n"+
           "them on.  You feel like you could crush stones with your\n"+
           "bare hands with these.\n");
  set_type("gloves");
  set_weight(2);
  set_ac(0);
  set_size("large");
  set_value(2000);
  modify_stat(0,2);
 }
