
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("maltese falcon");
  set_alias("falcon");
  load_chat(8,({"The falcon pecks at the vine and looks at you.\n"}));
  set_short("A rare maltese falcon");
  set_long("You are quite shocked to see this rare carnivorous\n" +
	   "bird. You are sure that it will be very difficult\n" +
	   "to kill if it has survived this long in the wild.\n" +
	   "Falcons are birds of prey, it is strong and\n" +
           "compact. Its wings are long and powerful.\n");
  set_level(9);
  set_size(2);
  set_aggressive(0);
  add_money(100);
 }
}

