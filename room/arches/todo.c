inherit "/room/room";

void reset(int arg) {
  object ob;
  ::reset(arg);
  if(arg)
    return;
  set_light(1);
  dest_dir=({
    "/room/arches/general","north",
  });

  short_desc="Archwizards to-do discussion room";
  long_desc="You are in the to-do discussion room of the Archwizards.\n"
           +"Take a look at the board and participate in Their Wisdom...\n";

  transfer(clone_object("/boards/arch_todo"),this_object());
}

void init() {
  if(!this_player()->query_archwiz() || !interactive(this_player())) {
    this_player()->move_player("quickly#/room/arches/general");
    return;
  }
  ::init();
}
