inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
  set_name("platemail");
   set_type("armour");
   set_alt_name("armor");
   set_size("x-large");
   set_short("Fiend platemail");
   set_long("A huge set of platemail forged in hellfire.\n");
   set_ac(6);
   set_weight(7);
   set_value(1000);
}
