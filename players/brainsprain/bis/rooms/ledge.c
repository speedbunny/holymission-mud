inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "A road leading up the mountainside";
  long_desc =
    "This is the side of a vast mountain.  You are on a handcarved staircase "+
    "leading up to Castle Bismarck.  It also leads down to Towpath.  The "+
    "mountainside has several ornate murals painted onto its surface.\n";
  set_light(1);
  dest_dir = ({
    br+"/mountainside","down",
    br+"/castle_path","up"
  });
  items = ({
    "murals",
    "Paintings of Bismarck's victories over the heathens",
    "paintings",
    "Murals on the side of the mountain",
    "painting",
    "A mural on the side of the mountain",
    "staircase",
    "Stairs carved out of the living stone",
    "keep",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",
    "stone","The side of the mountain",
    "kladash",
    "Mount Kladash, on which Bismarck Keep resides",
    "towpath",
    "The Town of Towpath",
    "surface",
    "The surface of the mountainside",
    "mountainside",
    "The side of the mountain",
    "mural",
    "A painting of Bismarck's victories over the heathens",
    "mountain",
    "Mount Kladash, on which Bismarck Keep resides",
    "stairs",
    "Stairs carved out of the living stone",
  });
  ::reset(arg); 
  replace_program("room/room");
  
}
