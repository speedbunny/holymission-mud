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
	"players/bobo/krooms/castle/dungeon4","east",
	"players/bobo/krooms/swamps/under_sw9","west",
   });

   guard=clone_object("players/bobo/kmonster/dun_guard");
   move_object(guard,this_object());
}
