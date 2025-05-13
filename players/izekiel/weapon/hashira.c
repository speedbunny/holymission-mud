
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("hashira");
  set_alt_name("pole");
  set_alias("pole arm");
  set_class(15);
  set_value(250);
  set_weight(3);
  set_two_handed();
  set_short("hashira");
  set_long(
   "A four foot long pole, with a 16-inch blade on the end of it. It \n"+
   "is a sort of lance, with ornate carvings near the base of the pole.\n"+
   "The carving is of a dragon, inlaid with glistening diamonds and strips\n"+
   "of gold.\n");
}
