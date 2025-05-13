/* Along the Dark Crystal Wall */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Along the dark crystal wall";
    long_desc = "Below can be seen the vortex wanting to pull you in. You\n"+
                "hang on with fear of falling as you make your way along\n"+
                "this very narrow ledge here.\n";
    dest_dir = ({"players/kbl/chaos/cho32","up",
                 "players/kbl/chaos/cho34","down"});
    property = "no_steal","no_hide";
    smell = "The air is bland here";
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
  if(str == "at wall")
  {
   if(this_player()->query_dex() >= 12)
   {
     say(this_player()->query_name()+" turns and looks at wall.\n");
     write("By your best dexterity you turn your body and see words carved\n");
     write("into the wall, they say: 'use me for a bribe, Dark Crystal is'\n");
     write("tasty!'. Jum Jum!\n");
     return 1;
   }
   else
   {
     if(this_player()->query_dex() <= 7)
     {
        write("You fall into the VORTEX!!!\n");
        say(this_player()->query_name()+" falls into the VORTEX!!!\n");
        this_player()->move_player("falling toward vortex#room/void");
        return 1;
      }
      else
      {
        say(this_player()->query_name()+" almost slips off the ledge.\n");
        write("You almost slip! A piece of ledge falls off into the void.\n");
        write("The crystal is sharp, you cut yourself. Ouch!\n");
        this_player()->hit_player(5);
        return 1;
      }
    }
  }
  if(str == "at vortex" || str == "vortex")
  {
    say(this_player()->query_name()+" looks at the vortex.\n");
    write("The vortex is very large an threatens to pull you in. You can\n");
    write("feel the tug on you life energy. It wants you!\n");
    return 1;
  }
  if(str == "at narrow ledge" || str == "narrow ledge")
  {
    say(this_player()->query_name()+" looks at the narrow ledge under foot.\n");
    write("This is a narrow ledge on the dark crystal cliff wall. It looks\n");
    write("very solid and will not break from your weight.\n");
    return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks back up to ledge over vortex.\n");
    write("You can see the underside of the ledge. Its gouged from many\n");
    write("pieces of crystal falling away. Its faint green glow shows\n");
    write("its shape against the black background of the void.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down to cave entrance.\n");
    write("Below you can be seen a cave entrance. Maybe you will make it\n");
    write("there, hopefully.\n");
    return 1;
  }
}
