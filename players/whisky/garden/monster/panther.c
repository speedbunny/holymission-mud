inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("panther");
     set_short("A big black panther");
     set_long("It's stares at you with glowing eyes. It looks very stong and\ndangerous.\n");
     set_spell_mess1("CHHHHHHHHhhhhhhhhhhhh ");
     set_spell_mess2("CHHHHHHHHhhhhhhhhhhhh");
     set_chance(95);
     set_race("cat");
     set_level(15);
     set_size(3);
     set_al(-400);
     set_wc(25);
     set_ac(8);
     set_aggressive(1);
     move_object(clone_object("players/whisky/garden/obj/p_fur"),this_object());
     move_object(clone_object("players/whisky/garden/obj/stone"),this_object());
  }
}
 
 
