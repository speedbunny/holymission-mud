inherit "room/room";

object proboard,conboard,lvlboard;

reset(arg) {
  object board;

  if(arg) return;
  set_light(1);
  dest_dir=({ "room/arches/general","north" });
  short_desc="Archwizzards guild";
  long_desc=
     "This is the archwizzards private room to discuss about wizards.\n"+
     "There is a proboard, a contraboard and a levelboard.\n"+
     "Instead of the normal commands you have to enter:\n"+
     "  proread, contranote or levelremove ....\n";
  move_object(clone_object("players/rasta/proboard"),this_object());
  move_object(clone_object("players/rasta/conboard"),this_object());
  move_object(clone_object("players/rasta/lvlboard"),this_object());
}

init() {
  ::init();
}
