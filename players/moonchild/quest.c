inherit "room/room";

reset(arg) {
  object board;
  if(!present("board")) {
    move_object(board=clone_object("obj/board"),this_object());
    board->set_name("quest");
    board->set_file("players/moonchild/save/quest");
  }
  if(arg) return;
  set_light(1);
  short_desc="Quest room";
  long_desc="Here you can write down your fresh ideas about the future of the"+
    " quests in Holy Mission. Every new idea is welcome, think about it.\n";
/*
  long_desc="Vote here on which quests you think should be dropped from the Mud.\n";
*/
}
