inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("opal");
  set_short("fire opal");
  set_long("A gorgeous fire opal. This is what dwarves and magicians "+
    "dream about. It is so beautiful, you could spend hours staring "+
    "at it. It is almost as if it were another world unto itself.\n");
  set_alias_list(({ "gem", "fire opal", "fire gem", "jewel" }));
  set_value(5000 + random(10001));
  set_info("The fire opal is a naturally found magical jewel. It is "+
    "rumoured that wars were fought over it in days of past, however, "+
    "they were thought to be all gone. An enchanter can use the opal "+
    "in powerful enchantments, although it is the fire giants who "+
    "prize it above all others.\n");
}
