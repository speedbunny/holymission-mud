inherit "room/room";

reset(arg) {
  if(!present("ghoul")) {
    object b;
    int i;
    for(i=0;i<3;i++) {
      move_object(b=clone_object("obj/monster"),this_object());
      b->set_name("ghoul");
      b->set_short("A horrid undead ghoul");
      b->set_long("This horrendous creature guards the entrance to the tower.\n");
      b->set_level(20);
      b->set_chance(40);
      b->set_spell_dam(20);
      b->set_spell_mess1("Ghoul wails loudly.");
      b->set_spell_mess2("Ghoul wails loudly.");
      b->set_al(-250);
      b->set_aggressive(1);
    }
  }
  if(arg) return;
  short_desc="Entrance to tower";
  long_desc="To the south, you can see the entrance to a huge tower.\n"
	+ "To the west, the ground feels uneven and rather soft.\n";
  dest_dir=({ "players/moonchild/gnome/vlord", "south",
	"players/moonchild/gnome/bats", "west" });
  items=({ "tower", "A tall dark forbidding place" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("south", "south");
}

south() {
  if(present("ghoul")) {
    write("The ghoul bars your way!\n");
    return 1;
  }
}
