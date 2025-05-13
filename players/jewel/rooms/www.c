inherit "/room/room";

object board;

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    dest_dir=({
      "/players/jewel/rooms/amazon","west"
    });
    short_desc="WWW Room";
    long_desc="All around you are stars. Everyone all over the world can \
look into the night sky and see stars. We are one world. This room is \
for posting your WWW address, and for discussion of World Wide Web \
related topics!\n";
  }
  if(!board) {
    board=clone_object("/boards/private_boards/jewel_www");
    transfer(board,this_object());
  }
}
