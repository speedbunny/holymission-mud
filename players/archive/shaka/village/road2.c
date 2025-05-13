inherit "room/room";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  short_desc="A small road";
  long_desc="The road ends in the green hills. You're standing \n"+
            "in front of the hobbit land. Bigfolk please watch you're\n"+
            "head!\n";
  dest_dir=({"players/shaka/village/vil1","south",
            "players/shaka/village/road1","north",});
  items =({"hills","hills used as houses by the hobbits",
           "land","the proud land of the hobbits"});
}

init() {
  ::init();
  add_action("south","south");
}

south() 
{
  this_player()->move_player("south#players/shaka/village/vil1");
  return 1;
}
