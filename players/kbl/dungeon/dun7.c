/* Winding through the formations on the cavern floor */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Twisting around the formations on cavern floor";
    long_desc = "Tight passageway between these formations doesn't allow\n"+
                "for much room here. You can hear alot of water moving\n"+
                "very close by. A large hole in a stalagmite here catches\n"+
                "your eye.\n";
    dest_dir = ({"players/kbl/dungeon/dun6","south"});
    smell = "Air is odorless here but very moist";
     items = ({"formations","The stalagmites tower high above you",
             "stalagmites","One of them has a big hole in it",
             "hole","Its deep and seems to lead down towards the north"});
    property = "no_hide";
  }
}

init()
{
  ::init();
  add_action("enter_it","enter");
}

enter_it(str)
{
  if(!str)
   return;
  if(str == "hole")
  {
    write("You enter the hole in the stalagmite.\n");
    write("You start to slide downward... the sounds of a waterfall is\n"+
          "coming up quick!!!\n\n\n"+
          "You splashdown into a pool of water...\n");
    this_player()->move_player("by entering hole#players/kbl/dungeon/dun8");
    say(this_player()->query_name()+" falls out of a hole in a stalagmite\n"+
        "and falls headlong into the pool of water here!!\n");
    return 1;
  }
}
