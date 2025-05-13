inherit "room/room";

reset(arg) {
  object board;

  if(arg) return;
  set_light(1);
  dest_dir=({ "/room/adv_guild","down" });
  short_desc="Archwizzards guild";
  long_desc=
     "This is the archwizzards private room to discuss about wizards.\n"+
     "There is a proboard, a contraboard and a levelboard.\n"+
     "Instead of the normal commands you have to enter:\n"+
     "  proread, contranote or levelremove ....\n";
  move_object(clone_object("players/llort/arch_guild/proboard"),this_object());
  move_object(clone_object("players/llort/arch_guild/conboard"),this_object());
  move_object(clone_object("players/llort/arch_guild/lvlboard"),this_object());
}

init() {
  if(!this_player()->query_level()>39){
    write("\n\nYou get blasted by an immense fireball!\n\n\n");
    this_player()->move_player("X#room/church");
    return;
  }
  ::init();
}

