inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mummy lord");
  set_alias("lord");
  set_short("Mummy Lord");
  set_long("This is the almighty Mummy Lord he rules this part of the castle... You look like a toothpick to him\n");
  set_race("mummy");
  set_level(20);
  set_al(-1000);
  set_hp(800);
  set_aggressive(1);
  set_whimpy();
  return 1;
}

