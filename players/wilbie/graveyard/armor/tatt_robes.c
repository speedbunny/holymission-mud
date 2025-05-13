inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("robes");
   set_alias("robe");
   set_type("armour");
   set_size("medium");
   set_short("Tattered robes");
   set_long("A tattered robe covered in dirt.\n");
   set_ac(1);
   set_weight(1);
   set_value(1);
}
