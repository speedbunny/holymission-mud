
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

set_name("old monk");
  set_alias("monk");
   set_short("An old monk");
   set_long("An old monk who is silently praying.\n");
 set_level(8);
  set_size(1);
  add_money(20);
 }
}
