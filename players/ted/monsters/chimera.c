inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("chimera");
 set_alias("chimera");
 set_aggressive(1 );
 set_long("This huge monster has three heads: a snake, a lion and a goat.\n");
 set_level(17);
 set_hp(750);
 set_ac(7);
 set_wc(20);
 set_al(-200 );
 set_chance(20 );
 set_spell_mess2("The Chimera burns you with a blast of flame!");
 set_spell_mess1("The Chimera breaths fire");
 set_spell_dam(30 );
}
