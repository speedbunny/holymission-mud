inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("small horned demon");
  set_alias("horned demon");
  set_alt_name("fairy");
  set_short("A small horned demon");
  set_long(
    "A small horned demon that is less than 3 feet tall. The small "+
    "horns that protrude out from its head, its sharp teeth, "+
    "claws and thick skin is what makes this demon a formidable opponent.\n"
  );
  set_level(9);
  set_wc(10);
  set_ac(3);
  set_size(2);
  set_al(-150);
  set_aggressive(1);
  set_race("demon");
  add_money(50+random(51));
}

