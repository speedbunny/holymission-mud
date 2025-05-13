
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("bluebird");
  set_alias("bluebird");
  load_chat(7,({"Bluebird chirps: Would you like me to sing for you?\n"}));
  set_short("A small bluebird");
  set_long("A cute little bluebird.  It looks at\n" +
	   "you and flutters around happily.\n");
  set_level(2);
  set_size(1);
  set_aggressive(0);
  add_money(3);
 }
}

