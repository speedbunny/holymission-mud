inherit "obj/armour";

reset(arg){
if (arg) return;

  set_name("cloak");
  set_short("White Cloak");
  set_long("This sturdy cloak gleams a pristine white.  You see a unicorn\n"+
           "embroidered on the side of it.\n");
  set_weight(2);
  set_value(350);
  set_type("cloak");
  set_ac(1);
  set_size("any");

}
