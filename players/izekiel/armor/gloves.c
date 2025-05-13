
inherit "obj/armour";

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("gloves");
  set_alias("gauntlets");
  set_short("Leather Gloves");
  set_long(
   "A pair of gloves, made of the finest rawhide. There is double-thick\n"+
   "leather over the knuckles of the gloves, so that one's fist does not\n"+
   "get damaged when punching someone's teeth in.\n");
  set_value(40);
  set_weight(1);
  set_type("glove");
  set_ac(1);
}
