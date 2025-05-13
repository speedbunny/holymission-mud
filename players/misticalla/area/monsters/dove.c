
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("Grey dove");
  set_alias("dove");
  set_short("A peaceful looking dove");
  set_long("The bird of peace sits here as\n" +
	   "quiet as can be. Please don't\n" +
	   "kill the poor defenseless dove.\n");
  set_level(2);
  set_size(1);
  set_aggressive(0);
 }
}

