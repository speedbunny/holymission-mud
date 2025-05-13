inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("plate");
   set_type("armour");
   set_alt_name("o-yoroi");
   set_size("medium");
   set_short("ancient o-yoroi");
   set_long("A fine suit of ancient o-yoroi, bearing "+
   "the Symbol of Ryu!\n");
   set_ac(6);
   set_arm_light(2);
//    set_weight(2);
   set_value(1000);
}
