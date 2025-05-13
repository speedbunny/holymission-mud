inherit "room/room";

reset(arg) {
  int i;
  if(!present("spider")) {
    for(i=random(3);i<5;i++)
	move_object(clone_object("players/moonchild/cave/spider"),this_object());
  }
  if(arg) return;
  short_desc="In a pit";
  long_desc="You are in a dirty, mucky pit. You could probably climb out\n"
	+ "or you might be able to go north through a hole in the wall.\n";
  dest_dir=({ "players/moonchild/gnome/cubs", "north",
	"players/moonchild/gnome/pit", "up" });
  items=({ "hole", "To the north, there is a hole in the pit wall" });
  property=({ "no_teleport" });
}

move(str) {
  switch(query_verb()) {
  case "up":
	if(this_player()->query_weight() < 10 + random(15)) return ::move(str);
	write("You try to climb up but fall back down due to the weight you are carrying.\n");
	say(this_player()->query_name() + " tries to climb out but falls.\n");
	return 1;
	break;
  case "north":
	if(this_player()->query_weight() < 10) return ::move(str);
	write("You are carrying too much to squeeze through!\n");
	return 1;
	break;
  }
}
