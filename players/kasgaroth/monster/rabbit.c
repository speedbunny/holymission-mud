/*Monster description corrected by Silas*/
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rabbit");
  set_short("A rabbit");
  set_long("This rabbit is looking around for fresh vegetables to eat.\n");
  set_race("mammal");
  set_level(1);
  set_al(-50);
  set_wc(2);
  set_ac(2);
  add_money(50);
}
