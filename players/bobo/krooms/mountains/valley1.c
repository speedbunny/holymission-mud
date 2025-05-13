inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In a narrow valley";
  long_desc="You're in a narrow valley that becomes wider to the west.\n"+
   "A path leads upwards to the east.\n";
  dest_dir=({
	"players/bobo/krooms/mountains/stonepath3","east",
	"players/bobo/krooms/mountains/valley2","west",
   });
   items=({
     "valley","It is small and extends from here down to west",
   });
}
 
