inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Entrance hall of the castle";
  long_desc="This is the entrance hall of the castle. To the north there's an opening\n"+
   "into a corridor. To the south you can leave the castle.\n"+
   "There are a lot of paintings at the walls.\n";
  dest_dir=({
	"players/bobo/krooms/castle/corridor1","north",
	"players/bobo/krooms/castle/castle_entr","south",
   });
   items=({
    "paintings","Most of them show the archwizard Kelly, and one shows the thief Marc",
   });
}
 
