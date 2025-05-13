inherit "room/room";

object guard;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In a dungeon";
    long_desc="You in the dungeon of the castle.\n"+
      "This seems to be the a guard room.\n";
    dest_dir=({
    "players/kelly/rooms/swamps/under_sw9","west",
    "players/kelly/rooms/castle/dungeon4","east",
   });

   guard=clone_object("players/kelly/monster/dun_guard");
   move_object(guard,this_object());
}
 
