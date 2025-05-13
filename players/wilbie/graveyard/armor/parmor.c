inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("plate");
   set_type("armour");
   set_alt_name("platemail");
   set_size("medium");
   set_short("steel platemail");
   set_long("A fine suit of brightly glowing steel platemail, bearing "+
   "the Symbol of Illumitar!\n");
   set_ac(6);
   set_arm_light(2);
//    set_weight(2);
   set_value(1000);
}
