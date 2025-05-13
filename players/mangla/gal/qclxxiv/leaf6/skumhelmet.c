inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("skum helmet");
      set_alias("helmet");
      set_type("helmet");
      set_ac(1);
      set_short("A skum helmet");
      set_long(
"A skum helmet, especially good armour against all kinds of skum, and, in fact"
			+",\nagainst monsters in general.\n");
      set_value(75);
      set_weight(1);
  }
}
 
