inherit "obj/monster";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("fire giant king");
  set_alias("king");
  set_short("The Fire Giant King");
  set_race("giant");
  set_long(
    "This is the King of the Fire Giants (And he looks it). This must be "+
    "the largest, strongest giant you have ever seen!\n"
  );
  set_level(25);
  set_ac(16);
  set_wc(40);
  set_size(4);
  set_al(-850);
  set_aggressive(1);
  set_chance(35);
  set_spell_dam(60 + random(30));
  set_spell_mess1("The King calls down a rain of fire.\n");
  set_spell_mess2("The King calls down a rain of fire on your head!\n");
}
