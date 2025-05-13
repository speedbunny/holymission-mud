inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("waraxe");
  set_alt_name("two-handed axe");
  set_alias("axe");
  set_class(10);
  set_short("A waraxe");
  set_long("This seems to be a very normal waraxe.\n");
  set_value(3000);
  set_weight(4);
}

get() {
  if(this_player()->query_race() == "dwarf")  
      this_object()->set_class(15);
  return 1;
}
