inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
    set_name("robes");
   set_type("cloak");
   set_alt_name("black");
   set_size("medium");
   set_short("Fine robes of black silk");
   set_long("Fine robes of black silk\n");
   set_ac(1);
   set_weight(2);
   set_value(500);
}
