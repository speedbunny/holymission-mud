inherit "obj/monster";

int count;
query_property(str) { return str=="no_clean_up"; }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  count=0;
  set_name("yellow goblin");
  set_race("goblin");
  set_short("An ugly yellow goblin");
  set_long("This a truly ugly yellow goblin. He stinks of undigested food and decaying\n"
	+ "corpses and really does seem to be one of the most appallingly unattractive\n"
	+ "creatures that you've ever met.\n");
  set_level(16);
  set_wc(32);
  set_al(-125);
  set_whimpy(50);
  add_money(100+random(401));
  set_dead_ob(this_object());
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
