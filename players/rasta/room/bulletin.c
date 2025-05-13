
inherit "room/room";
object board;
reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir=({"players/rasta/room/entrance","west",
"players/rasta/room/brat","north",
 "players/rasta/room/dustroad","east"});

  short_desc="Bulletin Room";
  long_desc=
 "This room has been especially designed for those of you out there\n"
+"who haven't been lucky enough to find a pen pal yet !. Put a short note \n"
+"about yourself onto this board and add your (email) address. Maybe you get\n"
+"lots of answers.\n";
transfer(clone_object("/boards/private_boards/rasta_friend"),this_object());
  }
}
