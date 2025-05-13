
inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("ninja star");
  set_alias("battleaxe");
  set_class(12);
  set_short("A battleaxe");
  set_long("A long handled, double bladed battleaxe. \n");
  set_value(2500);
  set_weight(1);
  return 1;
}

