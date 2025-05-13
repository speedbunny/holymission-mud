inherit "obj/soft_drink";
object owner;

drink(str) {
  ::drink(str);
  owner = this_player();
  set_heart_beat(1);
  call_out("stop_beat",20);
  return 1;
}

heart_beat() {
  owner->attack();
}

stop_beat() {
  set_heart_beat(0);
  write("Bummer! What a letdown.\n");
}

reset(arg) {
  ::reset(arg);
  if (arg) return;
  short_desc = "A haste potion";
  alias = "potion";
  value = 500;
  strength = 1;
  weight = 2;
  drinker_mess = "You feel full of Vim and Vigor!\n";
  empty_container = "bottle";
}
