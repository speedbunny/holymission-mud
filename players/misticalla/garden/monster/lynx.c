inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("lynx");
     set_alias("aggressive lynx");
     set_short("an aggressive lynx");
     set_long("It's stares at you with glowing eyes. It looks very stong and\ndangerous.\n");
     set_spell_mess1("The Lynx spits: CHHHHHHHH !!!");
     set_spell_mess2("The Lynx spits: CHHHHHHHH !!!");
     set_chance(95);
     set_race("cat");
     set_level(4);
     set_size(2);
     set_al(-400);
     set_wc(8);
     set_ac(2);
     set_aggressive(1);
     
move_object(clone_object("players/misticalla/garden/obj/fur"),this_object());
     command("wear fur");
  }
}
 
 
