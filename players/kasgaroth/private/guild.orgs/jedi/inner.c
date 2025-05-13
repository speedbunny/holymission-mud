inherit"room/room";
 
#define GM "guild/master"
#define this_guild GM->query_number("jedi")
 
reset(arg) {
  object board;
 
  if(arg) return;
  short_desc="Inner Jedi-guild";
  long_desc="You are in the sanctuarium of the Jedi guild.\n" +
	 "Only members of the guild can enter this room.\n"+
	 "There is a sign attached to the wall.\n"+
     "To the east there is a room, where you can ask for a cloak.\n";
  set_light(2);
  no_castle_flag=1;
  dest_dir=({
     "players/kelly/guild/room","north",
     "players/kelly/guild/caperoom","east",
  });
  items=({
     "room","The Cloakroom is brightly lit",
     "sign","You can read it",
  });
  board=clone_object("obj/board");
  board->set_name("jedi");
  board->set_short("The Jedi guild board");
  board->set_file(GM->query_dir(this_guild)+"/innerboard");
  move_object(board,this_object());
}
 
init() {
  ::init();
  if(this_player()->query_guild()!=this_guild) {
    write("You are not allowed here.\n");
    this_player()->move_player("this holy place#players/kelly/guild/room");
    return;
  }
  add_action("read","read");
}
 
read(str) {
  if(str!="sign") return;
  say(this_player()->query_name()+" reads the sign.\n");
  write("If you want to help Jedi who just started you can leave equipment here.\n");
  return 1;
}
 
