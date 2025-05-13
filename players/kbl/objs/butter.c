inherit "obj/monster";

int count;

reset(arg) {
  ::reset();
  if(arg) return;
  count=0;
  set_name(({ "white", "blue", "yellow", "red" })[random(4)] + " butterfly");
  set_race("butterfly");
  set_short("A pretty " + lower_case(query_name()));
  set_long(short() + ", fluttering around happily.\n");
  set_level(1);
  set_wc(2);
  set_al(125);
  set_hp(15);
  set_whimpy(50);
  msgin="flutters in";
  msgout="flutters off";
}

heart_beat() {
  if(++count>4) {
    random_move();
    count=0;
  }
  ::heart_beat();
}
