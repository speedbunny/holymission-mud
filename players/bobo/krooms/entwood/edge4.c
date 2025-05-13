inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="At the edge of a forest";
  long_desc="You are at the edge of a big forest.\n"+
   "You can enter it to the west, but you have a strange feeling here.\n"+ 
   "It seems that this forest has hundreds of eyes, that stare at you, just\n"+
   "waiting for you to enter. To the east there lies a small plain.\n";

  dest_dir=({
	"players/bobo/krooms/entwood/wood5","north",
	"players/bobo/krooms/entwood/edge3","south",
	"players/bobo/krooms/mountains/plain4","east",
	"players/bobo/krooms/entwood/wood3","west",
   });
  
   items=({
     "forest","A thick forest with some very high trees",
     "eyes","Well, in fact you don't see them, but you think there are", 
   });
 
}
 
