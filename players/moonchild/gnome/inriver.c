inherit "room/room";

reset(arg) {
  if(!present("octopus")) {
    object o;
    move_object(o=clone_object("obj/monster"),this_object());
    o->set_name("octopus");
    o->set_short("An octopus");
    o->set_long("An octopus with long arms, reaching for you.\n");
    o->set_al(-50);
    o->set_whimpy(-1);
    o->set_level(8);
    o->set_chance(100);
    o->set_spell_dam(2);
    o->set_spell_mess1("Octopus seems to smile.");
    o->set_spell_mess2("Octopus grazed you.");
    o->set_dead_ob(this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="An underground river";
  long_desc="You are swimming deep in an underground river.\n"
	+ "To the west you can make out a cave entrance.\n";
  dest_dir=({ "players/moonchild/gnome/cave", "west",
	"players/moonchild/gnome/river", "up" });
  items=({ "cave", "It's a cave alright",
	"entrance", "It's a cave alright" });
  property=({ "no_teleport", "no_sneak" });
}

init() {
  ::init();
  add_action("west", "west");
  if(interactive(this_player())) call_out("no_air",10,0);
}

west() {
  if(!present("octopus")) reset();
  write("The octopus bars your way.\n");
  return 1;
}

monster_died(ob) {
  tell_room(environment(ob),"As the octopus dies, another arrives.\n");
  call_out("reset",1,0);
}

no_air() {
  if(!present(this_player())) return;
  write("You are gasping for air, and you come to the surface.\n");
  this_player()->move_player("up#players/moonchild/gnome/river");
}
