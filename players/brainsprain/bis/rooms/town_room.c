inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
object board;

void reset(int arg) {
  
  short_desc = "Towpath Town Room";
  long_desc =
    "People bustle about this room as they prepare for a town meeting. "+
    "Here people come to leave notes as to what the mayor can do to improve "+
    "the town.  The walls are covered with pictures of famous citizens.  The "+
    "northern wall is dominated with a picture of Count Bismarck.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-16","south",
  });
  items = ({
    "wall",
    "A large picture of Count Bismarck dominates this wall",
    "count",
    "Count Bismarck",
    "bismarck",
    "The name of the family that rules this land",
    "picture",
    "Picture of Count Bismarck",
    "room",
    "The Towpath Town Room",
    "walls",
    "They are covered with pictures",
    "people",
    "The citizens of Towpath",
    "towpath",
    "The town you are in",
    "pictures",
    "Pictures of famous citizens",
  });
#if 0
  board = clone_object("/obj/board");
  board->set_name("Townpath Town Board");
  board->set_file(bi+"/town_board");
#else
  board = clone_object("/boards/private_boards/brainsprain_bis");
#endif
  move_object(board,this_object());
  ::reset(arg);  
  replace_program("room/room");
}

