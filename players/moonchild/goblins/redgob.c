inherit "obj/monster";

int count;

reset(arg) {
  object scalper;
  ::reset(arg);
  if(arg) return;
  count=0;
  set_name("red goblin");
  set_race("goblin");
  set_short("An ugly red goblin");
  set_long("This a truly ugly red goblin. He stinks of undigested food and decaying\n"
	+ "corpses and really does seem to be one of the most appallingly unattractive\n"
	+ "creatures that you've ever met.\n");
  set_level(20);
  set_ac(20);
  set_chance(50);
  set_spell_dam(75);
  set_spell_mess1("Red goblin pounds its attacker.");
  set_spell_mess2("Red goblin pounds you.");
  set_al(-125);
  set_whimpy(50);
  set_dead_ob(this_object());
  if(present("knife",this_object())) return;
  scalper=clone_object("players/moonchild/goblins/scalper");
  transfer(scalper,this_object());
  init_command("wield knife");
}

heart_beat() {
  if(++count>4) {
    random_move();
    count=0;
  }
  ::heart_beat();
}

monster_died() {
  "players/moonchild/goblins/disp"->more();
  return;
}
