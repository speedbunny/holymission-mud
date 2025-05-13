inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("plate");
   set_type("armour");
   set_alt_name("platemail");
   set_size("medium");
   set_short("steel platemail");
   set_long("A fine set of platemail shining brightly.\n");
   set_ac(4);
   set_weight(2);
   set_value(700);
}
