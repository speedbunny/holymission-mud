/* Along the Fissure Joint wall */

inherit "room/room";
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Climbing the fissure joint wall";
   long_desc = "You are climbing along a section of the fissure joint\n"+
                "wall. A constant vibration can be felt throught the wall.\n"+
                "Below you can see a jutting ledge of dark crystal. The\n"+
                "ground heaves a little as the brown crystal, left of the\n"+
                "ledge, detachs and falls away towards the vortex. Very\n"+
                "powerful forces must be at work here.\n";
    dest_dir = ({"players/kbl/chaos/cho3","up",
                 "players/kbl/chaos/cho32","down"});
    property = "no_steal";
    smell = "Heavy duty sulfur type smell all around";
    items = ({"ground","Where you are standing is a narrow ledge along\n"+
                       "a wall of dark crystaline material. With your\n"+
                       "back to the wall, you make your way here",
              "brown crystal","Looks very brittle"});
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
}


look_it(str)
{
  if(!str)
   return;
  if(str == "at wall" || str == "wall")
  {
    if(this_player()->query_dex() >=12)
    {
      say(this_player()->query_name()+" looks at something on the wall.\n");
      write("By your best dexterity, you turn you body and can see the\n");
      write("words in common language, carved into the wall. They read\n");
      write("`Oh light beam, grant me a suit to travel upwards.' Looks\n");
      write("a fine blade carved these words in this crystal wall.\n");
      return 1;
    }
    else
    {
      if(this_player()->query_dex() <= 7)
      {
        write("You fall down the fissure joint wall!\n");
        say(this_player()->query_name()+" falls down fissure joint wall!\n");
       this_player()->hit_player(20);
        write("You get hurt during the fall.\n");
        this_player()->move_player("falling down#players/kbl/chaos/cho32");
        write("Your in a different place, the hardway.\n");
        return 1;
      }
      else
      {
        write("You almost slip!! You just bearly catch yourself.\n");
        say(this_player()->query_name()+" almosts slips!\n");
        return 1;
      }
    }
  }
  if(str == "at vortex" || str == "vortex")
  {
    say(this_player()->query_name()+" looks at the vortex.\n");
    write("The vortex is a little closer and the swirling cloud of\n");
    write("material is more defined. Looks like water swirling in a\n");
    write("whirlpool of red, green and blue glittering lights, then\n");
    write("vanishing into the vortex.\n");
    return 1;
  }
  if(str == "at ledge" || str == "ledge")
  {
    say(this_player()->query_name()+" looks at ledge below.\n");
    write("You can see its made from dark crystal and that pieces of\n");
    write("brownish crystal break off from the left side of the ledge.\n");
    return 1;
  }
}
