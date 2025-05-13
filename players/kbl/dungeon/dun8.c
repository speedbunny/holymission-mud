/* Pool of water created by water falling from cavern ceiling */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Pool formed from water falling from cavern ceiling";
    long_desc = "Waist deep pool you now stand in is created from the water\n"+
                "falling from the cavern ceiling. The spray hits your face\n"+
                "in a fine mist. It feels refreshing. The water from the\n"+
                "pool leaves out through a opening in the north wall. It\n"+
                "is full of water, so it looks like the only way to enter\n"+
                "the opening is by swimming underwater. Above you and to\n"+
                "the south is a hole in a stalagmite. Much too far up for\n"+
                "you to reach though. The noise from the falling water makes\n"+
                "your ears hurt.\n";
    smell = "Air is extremely wet but is very fresh";
    property = "no_sneak","no_steal";
    items = ({"pool","Waist deep pool has a irregular rocky bottom. Water\n"+
                     "falls real close to and moves you back and forth",
              "cavern","Looking around you see the cavern about you",
              "cavern ceiling","The ceiling has cracks in it allowing the\n"+
                       "water to come through and fall to where your at",
              "ceiling","Has cracks in it allowing the water to come\n"+
                        "through and fall to where your at",
              "water","Your standing in it",
              "mist","Its hitting your face",
              "opening","A shallow arch way going north. Its full of water",
              "hole","A dark hole in a stalagmite. It might lead somewhere",
              "stalagmite","Many here, but only one with a hole in it",
              "cracks on ceiling","You can't make out much detail from here"});
  }
}

init()
{
  ::init();
  add_action("enter_it","enter");
  add_action("dive","dive");
  add_action("dive","swim");
}

enter_it(str)
{
  if(!str)
   return;
  if(str == "hole")
  {
    switch(this_player()->query_dex())
    {
      case 1..8:
        write("You try to enter the hole by climbing the stalagmite but\n"+
              "its to slick and you slide back down into the pool.\n");
        break;
      case 9..100:
        write("You climb the slick stalagmite and enter the hole!\n");
        this_player()->move_player("into hole#players/kbl/dungeon/dun7");
        break;
      default:
        write("You can't eve make it out of the pool! You fall back\n"+
              "into the pool with a slash!\n");
        break;
     }
     return 1;
  }
  if(str == "opening")
  {
    write("Maybe you should try swimming to or diving underwater to opening.\n");
    return 1;
  }
}

dive(str)
{
  if(!str)
   return;
  if(str == "to opening" || str == "underwater to opening")
  {
    if(this_player()->query_weight() < 16)
    {
      write("You go underwater and swim towards the opening...\n");
      write("You feel a current of water pulling you along.\n");
      this_player()->move_player("by diving to opening#players/kbl/dungeon/dun11");
      return 1;
    }
    write("You weight to much! You feel it you went underwater, you may\n"+
          "sink to the bottom!\n");
    return 1;
  }
}
