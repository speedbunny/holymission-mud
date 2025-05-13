inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("imp");
  set_alt_name("demon");
  set_short("A small imp");
  set_long("A small imp grinning evilly. Beware of its sharp talons.\n");
  set_level(6);
  set_size(1);
  set_wc(5);
  set_al(-50);
  set_aggressive(1);
  set_race("imp");
  add_money(20+random(31));
}

