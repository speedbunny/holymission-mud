inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("leather");
   set_alias("rotting");
   set_type("armour");
   set_size("medium");
   set_short("Rotting leather");
   set_long("Rotting leather armor covered in dirt.\n");
   set_ac(1);
   set_weight(1);
   set_value(1);
}
