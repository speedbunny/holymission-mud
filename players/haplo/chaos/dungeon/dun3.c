/* Natural cavern: ledge looking down into the depths */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Ledge overlooking a huge cavern";
    long_desc = "The light provided seems to stimulate the green moss into\n"+
                "a spectacular array of bluegreen luminosity! You see a\n"+
                "distant waterfall, coming directly down from the cavern\n"+
                "ceiling, north of this ledge. Down is the cavern spread\n"+
                "before you. All kinds of natural fluid rock formations\n"+
                "can be seen. A spiral pathway leads down and a semi-\n"+
                "natural opening can be seen to the south of this ledge.\n";
    dest_dir = ({"players/kbl/dungeon/dun1","south",
                 "players/kbl/dungeon/dun4","down"});
    smell = "Cool crisp clean air... You inhale deeply";
    items = ({"moss","Green moss growing in patchs on the walls of the cavern",
              "green moss","Growing in patchs on the walls of the cavern",
              "waterfall","Water falling from the ceiling ends up in a\n"+
                          "pool on the floor of the cavern. The water\n"+
                          "then flows out through a opening in the\n"+
                          "north cavern wall",
              "pool","Not much detail to be seen from here",
              "ledge","A rough piece of limestone",
              "opening","You can't see much of it, the waterfall blocks\n"+
                        "your view",
              "pathway","The pathway spirals sharply down to the cavern floor",
              "semi-natural opening","This opening leads south into\n"+
                                     "blackness",
              "fluid rock formations","Beautiful and colorful limestone\n"+
                          "formations. Must have taken along time to\n"+
                          "create these. They are 50 meters tall",
              "limestone","Whiteish brown crumbly rock"});
  }
}

init()
{
  ::init();
  if(random(50) > 45)
  {
    write("You see a large bat flying down from the ceiling!\n");
    transfer(clone_object("players/kbl/objs/bat"),this_object());
  }
}
