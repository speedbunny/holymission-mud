inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("plate");
   set_type("leg");
   set_alt_name("helmet");
   set_size("medium");
   set_short("steel helmet");
   set_long("A rusty looking steel helmet\n");
   set_ac(1);
   set_weight(2);
   set_value(500);
}
