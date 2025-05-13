inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Fire Giant Longsword");
 set_alias("longsword");
 set_short("A Fire Giant Longsword");
 set_long("This longsword seems larger than your average longsword, and heavier.\n");
 set_class(13);
 set_weight(4);
 set_value(500);
}
