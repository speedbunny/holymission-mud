
inherit "room/room";
object board;
reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir=({"players/rasta/room/entranc1","west",
"players/rasta/room/brat1","north",
 "players/rasta/room/dustroa1","east"});

  short_desc="Bulletin Room";
  long_desc=
 "This room has been especially designed for those of you out there\n"
+"who haven't been lucky enough to find a pen pal yet !. Put a short note \n"
+"about yourself onto this board and add your (email) address. Maybe you get\n"
+"lots of answers."
;
board=clone_object("obj/board");
board->set_file("players/rasta/board_file");
board->set_name("Love and Friendship");
move_object(board,this_object());
  }
}
