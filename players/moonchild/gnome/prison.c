inherit "room/room";

reset(arg) {
  object p;
  remove_call_out("reset");
  if(!present("prisoner")) {
    move_object(p=clone_object("obj/monster"),this_object());
    p->set_name("prisoner");
    p->set_short("A prisoner has been shackled to the cell");
    p->set_long("A long-lost prisoner, shackled to the cell.\n"
	+ "He looks emaciated and tired, not surprisingly.\n");
    p->set_al(1000);
    p->set_level(1);
    p->set_wc(1);
    p->set_hp(70);
    p->set_male();
  }
  if(arg) return;
  short_desc="Prison cell";
  long_desc="This is a bare prison cell. It is almost entirely empty.\n";
  dest_dir=({ "players/moonchild/gnome/dtemple", "north" });
  property=({ "no_teleport" });
}

extra_reset() { call_out("reset",300,1); }

init() {
  ::init();
  add_action("open", "open");
  add_action("open", "loosen");
  add_action("free", "free");
}

free(str) { if(str=="prisoner") return open("shackles"); }

open(str) {
  object c;
  if(str!="shackles" || !present("prisoner")) return;
  write("You open the shackles and the prisoner climbs out.\n");
  say(this_player()->query_name()
	+ " opens the shackles and the prisoner climbs out.\n");
  tell_room(this_object(), "Prisoner says: I'm free! Thank you "
	+ this_player()->query_name() + ".\n");
  write("Prisoner whispers to you: This might be of use to you.\n");
  say("Prisoner whispers something to " + this_player()->query_name() + ".\n",
	this_player());
  if(transfer(c=clone_object("players/moonchild/gnome/cross"),this_player())) {
    move_object(c,this_object());
    tell_room(environment(this_player()),"Prisoner drops the cross.\n");
  } else {
    write("Prisoner gives cross to you.\n");
    say("Prisoner gives cross to " + this_player()->query_name() + ".\n",
	this_player());
  }
  tell_room(environment(this_player()),"Prisoner leaves north.\n");
  destruct(present("prisoner"));
  return 1;
}
