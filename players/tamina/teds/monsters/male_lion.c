inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  random_move();
  random_move();
  random_move();
  if(arg) return;
  set_name("golden lion");
  set_alias("male lion");
  set_race("lion");
  set_short("A Massive Golden Maned Lion");
  set_long("This lion has a gold mane and tail. You can see\n"+
           "the muscles riple and tense under his amber fur.\n");
  set_level(14);
  set_ac(7);
  set_wc(35);
  set_hp(400);
  set_ep(500000);
  set_al(10);
  set_aggressive(1);
  set_move_at_reset();
  set_spell_mess1("Golden Lion rips with his claws");
  set_spell_mess2("Golden Lion rips you with his claws");
  set_chance(60);
  set_spell_dam(45);
}
