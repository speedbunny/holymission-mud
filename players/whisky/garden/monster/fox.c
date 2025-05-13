inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if (!arg) {
   set_name("baby fox");
   set_alt_name("fox");
    set_alias("baby fox");
    set_short("A smart baby fox");
    set_long("It's looking at you like it's searching someone to play.\n");
    set_level(2);
    set_size(2);
    set_al(100);
    set_aggressive(0);
    set_whimpy();
   set_dead_ob(this_object());
    move_object(clone_object("players/whisky/garden/obj/fox_jacket"),
	this_object());
    command("wear jacket");
  }
}
 
 
   monster_died(ob) {
  move_object(clone_object("players/whisky/garden/monster/m_fox"),
             environment(this_object()));
 say("Suddenly mother fox arrives angrily.\n");
  return 0;
}

