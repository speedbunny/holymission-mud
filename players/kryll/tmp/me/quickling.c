inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("quickling");
  set_alias("brownie");
  set_alt_name("fairy");
  set_short("A small fairy");
  set_long(
    "A small fairy that resembles a sprite or brownie, however, "+
    "unlike their cousins, this creature is evil and loves mischief.\n"
  );
  set_level(7);
  set_size(1);
  set_dex(35);
  set_al(-150);
  set_aggressive(1);
  set_race("fairy");
  add_money(50+random(51));
}

