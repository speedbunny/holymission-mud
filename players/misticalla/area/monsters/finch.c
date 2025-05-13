
inherit "/obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {

  set_name("yellow finch");
  set_alias("finch");
  load_chat(10,({"CHiiirrrp\n"}));
  set_short("A little yellow finch");
  set_long("A tiny yellow finch flutters around\n" +
	   "the vine searching for food and seeds\n" +
	   "to nibble on. Its hard beak will peck\n" +
	   "your eyes out if you aren't careful\n");
  set_level(3);
  set_size(1);
  set_aggressive(0);
  add_money(2);
 }
}

