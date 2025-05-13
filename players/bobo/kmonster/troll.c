inherit "obj/monster";
 
 
reset(arg) {
::reset(arg);
  if(arg) return;
  set_name("troll");
  set_race("troll");
  set_size(4);
  set_level(9);
  set_hp(120);
  set_wc(8);
  set_ac(4);
  set_al(-50);
  set_short("A troll");
  set_long("This is one of the rare Mythwood trolls.\n");
  set_aggressive(1);
  set_spell_mess1("The troll says: Mumble");
  set_spell_mess2("The troll says: I'll rip out your guts!");
  set_chance(15);
  set_whimpy(1);
}
