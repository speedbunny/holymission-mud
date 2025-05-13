inherit "obj/armour";

 reset (arg) {
  ::reset(arg);
  if (arg) return;

   set_name("Blacksmith Apron");
   set_alias("apron");
    set_type("armour");
  set_size(3);
   set_short("blacksmith apron");
   set_long("The apron is covered in soot and grime from use by the blacksmith.\n");
   set_weight(1);
   set_ac(0);
   set_value(100);
 }
