inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("plate");
   set_type("armour");
   set_alt_name("platemail");
   set_size("medium");
   set_short("black platemail");
   set_long("A fine set of platemail humming softly.\n");
   set_ac(6);
//    set_weight(2);
   set_value(1000);
}
