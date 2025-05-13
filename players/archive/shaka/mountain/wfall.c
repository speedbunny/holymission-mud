inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Water fall";
  long_desc="You're standing in front of a waterfall, falling down in \n"+
            "in a lake below in the valley. It seems that there is some \n"+
            "sort of cave behind the waterfall. \n";
  dest_dir= ({"/players/shaka/mountain/path3","west",});
  items = ({"waterfall","maybe you can enter it",
            "cave","maybe you can enter it"});
}

init() {
  ::init();
  add_action("enter_fall","enter");
}

enter_fall(arg)
{
 if (arg == "waterfall" || arg == "cave")
  {
   write("You move yourself behind the waterfall.\n");
   this_player()->move_player(" moves behind the waterfall#players/shaka/fairy/behind");
   return 1;
  }
}
