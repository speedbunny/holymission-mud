inherit "/obj/monster";

object armour_;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("kirk");
  set_alias("rd");
  set_short("Kirk, the killer RD");
  set_long("This is Kirk.  He is the RD of Jake's place.  Don't mess with him!\n");
  add_money(2000);
  set_size(3);
  set_level(20);
  set_al(1000);
  set_hp(2000);
  set_wc(25);
  set_ac(10);
  set_aggressive(0);
armour_=clone_object("players/jake/armour/jacket");
  move_object(armour_,this_object());
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
