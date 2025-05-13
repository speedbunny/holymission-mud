/* Down by the One Falls pool */

inherit "room/room";
object frog;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Bottom of One Falls";
    long_desc = "The spray from the waterfall hits your face. Ahhhh! Its\n"+
                "really refreshing. The water is foamy and flows out the\n"+
                "seemingly unreachable gorge. You think entering the water\n"+
                "might be fatal because of the swirling movement of the water\n"+
                "here. You see a gap between the waterfall and the cliff.\n"+
                 "The forest surrounds you scanning north to south.\n";
    dest_dir = ({"players/kbl/falls_cav1","east",
                 "players/kbl/big_forest2","north",
                 "players/kbl/falls1","up"});
    smell = "A moist musty odor greets your nose";
    property = "no_hide";
    items = ({"gap","Between the waterfall and the cliff is a dark space with\n"+
                    "a narrow ledge leading east to it",
              "dark space","The dark space between waterfall and cliff. Maybe\n"+
                           "you should go east",
              "forest","Many blue leaf maples surround this small clearing\n"+
                       "near the waterfall pool. The sway gently in the\n"+
                       "breeze",
              "blue leaf maples","You scan north to south. Beautiful soft\n"+
                       "blue leafs shutter in the breezes that catch their\n"+
                       "slim line bodies",
              "blue leafs","Many blue leafs here, but none on the ground!",
              "the ground","Exposed dirt where the path is shows its rich\n"+
                           "texture",
              "cliff","You look up at the cliff that goes up and out of sight\n"+
                      "above the tree tops",
              "tree tops","to far up from here to get any detail",
              "narrow ledge","Made from quartz crystal, very slick when wet!"});
    genfrog();
  }
}


init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
}


genfrog()
{
  int val;

  val = random(45);
  if(val > 5)
  {
    if(!frog || !living(frog))
    {
      frog = clone_object("players/kbl/objs/frog");
      transfer(frog,this_object());
    }
    else
    {
    say("A frog jumps out of the water and hopes off into the forest.\n");
    write("A frog jumps out of the water and hopes off into the forest.\n");
    }
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at pool" || str == "pool")
  {
    say(this_player()->query_name()+" looks down at pool.\n");
    write("The pool looks very deep and dangerous. Little eddy currents\n");
    write("spin off the bottom of the falls which would suck you down to\n");
    write("your death.\n");
    return 1;
  }
  if(str == "at waterfall" || str == "waterfall")
  {
    say(this_player()->query_name()+" looks at waterfall.\n");
    write("Waterfalls are so beautiful and this one is no exception.\n");
    write("The colors from the spray dance around and you find yourself\n");
    write("staring a while at them.\n");
    return 1;
  }
  if(str == "at gorge" || str == "gorge")
  {
    say(this_player()->query_name()+" looks at gorge.\n");
    write("Barely visible, this steep gorge must have been cut by a\n");
    write("glacier, many moons ago.\n");
    return 1;
  }
}
