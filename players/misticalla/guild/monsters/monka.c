
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("praying monk");
  set_alias("monk");
  set_short("An old praying monk");
   set_long("An old monk who is silently praying.\n");
 set_level(8);
  set_size(1);
  add_money(20);
 }
}
