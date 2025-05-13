inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="Bleak moor";
  long_desc="You are on a bleak moor, surrounded by a range of dark mountains.\n"
	+ "A huge carven idol stands here, waiting for people to worship it.\n";
  dest_dir=({ "players/moonchild/gnome/bats", "south" });
  items=({ "mountains", "They look so like mountains you forgot you were underground",
	"idol", "It is an unholy creation indeed" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("pray", "worship");
  add_action("pray", "pray");
}

pray(str) {
  if(query_verb()=="worship" && str!="idol") return;
  write("You bow down and worship the idol.\n");
  say(this_player()->query_name() + " worships the idol.\n");
  if(present("cross",this_player())) {
    int i;
    write("You hear an evil voice laughing at you. A sudden fear overwhelms you.\n");
    for(i=0;i<8;i++) this_player()->run_away();
  } else {
    write("You feel that the idol is pleased with you.\n"
	+ "You feel yourself move through the dimensions.\n");
    say(this_player()->query_name() + " vanishes abruptly.\n");
    transfer(this_player(), "players/moonchild/gnome/cave");
  }
  return 1;
}
