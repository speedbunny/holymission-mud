
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("raven");
  set_alias("raven");
  set_short("A beautiful raven");
  set_long("This raven is suprisingly large and\n" +
	   "will start pecking at your head soon.\n");
  set_level(5);
  set_size(1);
  set_aggressive(1);
 }
}

