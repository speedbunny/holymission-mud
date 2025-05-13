inherit "room/room";
 
object fernis;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a small valley";
  long_desc="You're in a small valley.\n"+
   "This is the place where the Fernis uses to be.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/darkpath","down",
   });
   fernis=clone_object("players/kelly/monster/fernis");
   move_object(fernis,this_object());
}
 
