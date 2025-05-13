inherit "room/room";

status sacd;

reset(arg) {
  sacd=0;
  if(arg) return;
  short_desc="A dark temple";
  long_desc="You are standing in a dark temple. A small room is to the south,\n"
	+ "and you can hear some shrieking noises coming from the north.\n"
	+ "An intricately carved altar stands before you.\n";
  dest_dir=({ "players/moonchild/gnome/bats", "north",
	"players/moonchild/gnome/prison", "south",
	"players/moonchild/gnome/bystat", "west" });
  items=({ "altar", "An intricately carved altar. A plaque on it says:\n"
	+ "Sacrifice money to recieve your blessings" });
  property=({ "no_teleport" });
}

init() {
  ::init();
  add_action("sacrifice", "sacrifice");
}

sacrifice(str) {
  int no;
  if(!str) return;
  if(str=="money" || str=="coins") {
    write("But how many coins do you want to sacrifice?\n");
    return 1;
  }
  if(!(no=(str=="1 coin")) && !sscanf(str,"%d coins",no)) return;
  if(this_player()->query_money()<no) {
    write("You don't have that many coins.\n");
    return 1;
  }
  if(no<0) {
    write("Don't be silly.\n");
    return 1;
  }
  this_player()->add_money(-no);
  write("You sacrifice the coins.\n");
  say(this_player()->query_name() + " sacrifices some money.\n");
  no+=(random(2001)-4000-this_player()->query_alignment());
  if(no < -2500) {
    write("A flash of lightning strikes you from above.\n");
    say(this_player()->query_name() + " is struck by a flash of lightning.\n");
    tell_room(this_object(), "A voice says: Do not treat me with contempt!\n");
    this_player()->hit_player(10+random(66));
  } else if(no < 0 || sacd) write("Nothing happens.\n");
  else {
    object c;
    tell_room(this_object(), "Something appears on the altar!\n");
    move_object(c=clone_object("players/moonchild/gnome/crystal"),this_object());
    c->set_type(2);
    sacd=1;
  }
  return 1;
}
