
/* (C) Rasta */

#define SPZ "players/herp/games/spz"
#define TREASURY        "players/rasta/room/treasury"
#define H               6
#define W               7
#define TP              this_player()

inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
    dest_dir=({"/players/rasta/room/cellar","southeast"});
    short_desc="Noble Passage";
    long_desc=
   "You have arrived at the nobelest of all the passages your walk has taken\n"
  +"you through. You are walking along a fascade decorated with colored pottery\n"
  +"shards.\n"
  +"To the west you see the entrance to the formidable Puzzle of Herp's.\n"; 
 no_castle_flag = 1;
  }
}

init() {
  ::init();
  add_action("west","west");
}

west() {
object spz;

  spz=clone_object(SPZ);
  spz->set_exit(TREASURY);
  spz->set_2nd_exit(this_object());     /* Added by Herp */
  spz->set_player(this_player());
  spz->set_dimension(H,W);
  TP->move_player("west",spz);
  return 1;
}










