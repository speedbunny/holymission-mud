inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  random_move();
  random_move();
  random_move();
  if(arg) return;
  set_name("white lion");
  set_alias("female lion");
  set_race("lion");
  set_short("A Beautiful White Lion");
  set_long("This lion has a white mane and tail. You can see\n"+
           "the muscles riple and tense under the amber fur.\n");
  set_level(10);
  set_ac(6);
  set_wc(29);
  set_hp(300);
  set_ep(300000);
  set_al(10);
  set_aggressive(1);
  set_whimpy(25);
  set_move_at_reset();
  set_spell_mess1("White Lion rips with her claws");
  set_spell_mess2("White Lion rips you with her claws");
  set_chance(30);
  set_spell_dam(45);
}
