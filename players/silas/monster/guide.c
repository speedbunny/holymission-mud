inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("guide");
  set_alias("erwin");
  set_short("Erwin, the tour guide");
  set_long("He looks and acts like a typical tour guide. The only difference is that\nnobody bothers to listen to him anymore.\n");
  set_race("human");
  set_level(12);
  set_al(100);
  set_hp(400);
  set_wc(9);
  set_ac(4);
  set_aggressive(0);
  set_whimpy();
  move_object(clone_object("players/silas/obj/wbreaker"),
  this_object());
  init_command("wear windbreaker");
  move_object(clone_object("players/silas/obj/eglove"),
  this_object());
  init_command("wear gloves");
  load_chat(20,({
   "Erwin says: The beautiful chasm ahead of you has been here for eons.\n",
   "Erwin says: F'ghant offers all kinds of recreational opportunities!\n",
   "Erwin says: Fighters are welcome here also, enjoy the view.\n",
   "Erwin clears his throat.\n",
   "Erwin fills a glass with water out of the pool and drinks it.\n",
               }));
  return 1;
}


