inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  set_name("knight");
  set_alias("knight");
  set_alt_name("knight");
  set_race("human");
  set_gender(1);
  set_short("The Last Crusader");
  set_long("This is the very last of the Crusaders. He had won the privilage\n"+
          "to guard and indeed has been guarding the Grail for centuries\n"+ 
          "undisturbed, alone in his holy mission. Until now. Kinda makes\n"+
          "you feel guilty somehow.\n");
  set_level(35);
  set_al(1000);
  set_aggressive(0);
  set_chance(40);
  set_spell_dam(40+random(40));
  set_whimpy(-1);
  set_spell_mess1("The crusader curses you. You feel sick.");
  set_spell_mess2("The knight's sword plunges deep into your body.");
  set_hp(12345);
  set_wc(15);
  set_ac(15);
  move_object(clone_object("players/etmol/grail/objects/ksword.c"),this_object());
  command("wield sword");
  add_money(10000);
}
