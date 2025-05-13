/* Players first Entrance to Parallel Plane of Chaos */
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
  set_light(0);
  property = "no_steal";
   short_desc = "Dead End Rift";
   long_desc = "Distant rumblings tell a story of unstability here. White\n"+
               "light seems to dance on the rift creating shimmering globes\n"+
               "that fly into the blackness above you. Your body feels ok,\n"+
               "but your skin crawls. Shielding your eyes against your light\n"+
               "emissions you can see a faint green glow to the landscape\n"+
               "that looks like a desolate rocky plateau. Protruding ridges\n"+
               "peek above the rim of the rift. The ground doesn't feel\n"+
               "like any you have ever walked on.\n";
  dest_dir = ({"players/kbl/chaos/cho2","east"});
   items = ({"shimmering globes","Balls of decaying light",
             "green glow","The glowing comes from everything here. Not\n"+
                          "bright enough to provide lighting for you but\n"+
                          "gives a errie green outline to all shapes."});
   smell = "The air smells bland";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("eas","east");
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at rift")
  {
    say(this_player()->query_name()+" looks around at the surrounding rift.\n");
    write("The glossy dark rift is made of some sort of crystal. You light\n");
    write("creates dancing light patterns off of the shiny black crystal\n");
    write("that makes up the rift. Impossible to climb up the rift here\n");
    write("because the ground is so smooth.\n");
    return 1;
  }
  if(str == "at landscape" || str == "at ground" || str == "ground" || str == "lanscape")
  {
   say(this_player()->query_name()+" bends down and looks at the ground.\n");
    write("You bend down and feel the ground. Smooth in some places like\n");
    write("glass and in others like frozen ripples on a pond. The footing\n");
    write("seems ok here.\n");
    return 1;
  }
  if(str == "at ridges" || str == "ridges")
  {
    say(this_player()->query_name()+" looks at ridges.\n");
    write("Just bearly seen are the tips of the ridges. Not much detail.\n");
    return 1;
  }
  if(str == "at blackness")
  {
    say(this_player()->query_name()+" stares up into the blackness.\n");
    write("Blackest black you've ever seen. Seems to pull you in as you\n");
    write("look into this deep ebony blackness. You get the feeling you\n");
    write("might get lost forever.\n");
    return 1;
  }
}

eas()
{
  say(this_player()->query_name()+" leaves east towards a sharp ridge\n"+
      "of dark crystal.\n");
  write("You leave east towards...\n");
}
