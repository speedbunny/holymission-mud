inherit "room/room";
 
object fernis;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a small valley";
  long_desc="You're in a small valley.\n"+
   "this is the plave where the Fernis used to be.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/darkpath","down",
   });
   fernis=clone_object("players/bobo/kmonster/fernis");
   move_object(fernis,this_object());
}
 
