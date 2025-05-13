inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A yard in front of a gate";
  long_desc="You're standing on a yard in front of a huge castle gate.\n"+
   "To the north is the gate.\n";
  dest_dir=({
	"players/bobo/krooms/mythwood/trach2","south",
   });
   items=({
    "gate","It's an iron gate, but you can see no hole for a key a something like that",
   });
	move_object(clone_object("players/bobo/kmonster/eye"),this_object());
}

init() {
::init();
  add_action("north","north");
}

north() {
  write("There's no way of passing the gate.\n");
  return 1;
}

open() {
   write("The gate begins to melt.\nYou are moved through the iron gate.\n");
   this_player()->move_player("north#players/bobo/krooms/castle/caslte_hall");
   return 1;
}
