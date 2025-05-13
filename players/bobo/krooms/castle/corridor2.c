inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A cross-vault";
  long_desc="You're standing on a cross-vaulting.\n";
  dest_dir=({
	"players/bobo/krooms/castle/castle_yard","north",
	"players/bobo/krooms/castle/corridor1","south",
	"players/bobo/krooms/castle/cellar_top","east",
	"players/bobo/krooms/castle/tower20","west",
   });
}

