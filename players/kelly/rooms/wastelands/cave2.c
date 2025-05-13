inherit "room/room";
 
object hydra;
 
reset(arg) {
    if (arg) return;
    set_light(0);
    no_castle_flag=1;
    short_desc="A cave";
    long_desc="This is the den of a big seasnake.\n"+
      "A lots of bones lie around.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/cave1","south",
   });
 
   items=({
   "bones","These are the bones of unsuccessful spelaeologists",
   });
 
   hydra=clone_object("players/kelly/monster/hydra");
   move_object(hydra,this_object());
 
 
}
 
