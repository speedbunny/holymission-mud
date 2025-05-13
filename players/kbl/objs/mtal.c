inherit "obj/monster";

int count;
string walk;

reset(arg) {
  ::reset();
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
  set_heart_beat(1);
  set_dead_ob(this_object());
  walk=({ "north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest", });
}

heart_beat() {
  ::heart_beat();
  count++;
  if(count>4) {
    motivate();
    count=0;
  }
}

motivate() {
  int dir,ct,flag;
  ct=0;
  while(!flag && ct<10) {
    ct++;
    dir=random(8);
    flag=command(walk[dir],this_object());
  }
}

monster_died() {
  "players/moonchild/goblins/disp"->more();
  return;
}
