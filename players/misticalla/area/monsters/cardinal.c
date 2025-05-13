
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("cardinal");
  set_alias("cardinal");
  set_short("A beautiful red cardinal");
  set_long("A beautiful red cardinal. It is searching\n" +
	   "for things to make its nest now. You'd best\n" +
           "not disturb it.\n");
  set_level(3);
  set_size(1);
  set_aggressive(0);
  add_money(5);
 }
}

