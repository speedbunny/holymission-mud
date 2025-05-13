inherit "obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Frost Giant Longsword");
 set_alias("longsword");
 set_short("A Frost Giant Longsword");
 set_long("This longsword seems larger than your average longsword, and heavyer.\n");
 set_class(13);
 set_weight(4);
 set_value(500);
}
