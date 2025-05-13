inherit "room/room";
#define SN "\n"

reset(arg) {
  ::reset(arg);
  set_light(1);
/*  no_castle_flag = 0; */
  short_desc ="Pool";
  long_desc = "The current grows stronger here and you get the notion that you might not"+SN+
  "be able to return if you keep following it to the north. You can return to the"+SN+
  "south if you don't want to brave the mountain stream."+SN;
  
  dest_dir=({"/players/silas/caves/pool2","south",});
  smell="A fresh breeze is coming from the north.+SN";
}
init() {
 add_action("north","north");
  ::init();
}

north(str)
{
  if(str!="")
    {
      say(this_player()->query_name() +" slowly starts swimming to the north.\n");
      call_out("drift", 1, this_player());
      return 1;
    }
  write("What do you want to pull ?\n");
  return 1;
}

drift(spiller)
{
   tell_object(spiller, "You lose your footing!\n"
                      + "You are pulled away by the current!\n");
   call_out("drift_2", 3, spiller);
   return 1;
}

drift_2(spiller)
{
  tell_object(spiller, "You are drifting...is that a waterfall up ahead?\n");
  call_out("drift_3", 3, spiller);
  return 1;
}

drift_3(spiller)
{
  tell_object(spiller, "A waterfall! Aiyeeeee.....\n");
  call_out("drift_4", 3, spiller);
  return 1;
}
drift_4(spiller)
{
  tell_object(spiller, "SPLASH!\n");
  call_other(spiller, "move_player",
             "is pulled away by the current#players/silas/fghant/pool");
  return 1;
}
