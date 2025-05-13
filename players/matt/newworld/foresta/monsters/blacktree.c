inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tree");
  set_short("Black tree");
  set_long("A hideously deformed black tree, animated by pure evil.\n");
  set_alias("black tree");
  set_race("tree");
  set_level(10);
  set_hp(150);
  set_al(-500);
  set_aggressive(1);
  add_money(500);
  load_a_chat(40, ({
    "The black tree swings its branches madly.\n",
    "The tree roars and howls.\n"
  }));
}
