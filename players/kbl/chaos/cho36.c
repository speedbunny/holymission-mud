/* Dead End in the dark crystal cave (NOT) */

inherit "room/room";
int pass_found;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    pass_found = 0;
    set_light(0);
    short_desc = "Dead end in dark crystal cave";
    long_desc = "This is a dead end. The walls are not smooth here and a\n"+
                "constant thumping can be heard. You feel heat here.\n";
    dest_dir = ({"players/kbl/chaos/cho35","south"});
    smell = "There's a acid tinge to the air here";
    property = "no_hide";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("east","east");
  add_action("north","north");
  add_action("search","search");
  add_action("touch","touch");
}


north()
{
  if(pass_found)
  {
    write("You enter north fracture slit.\n");
    this_player()->move_player("into north slit#players/kbl/chaos/cho10");
    return 1;
  }
  else
  {
    if(this_player()->query_dex() > 17)
    {
      write("You brush against some sharp crystal on north wall.\n");
      this_player()->hit_players(5);
      say(this_player()->query_name()+" brushes against a sharp crystal.\n");
      return 1;
    }
    else
    {
      write("You get cut by a sharp crystal on north wall.\n");
      this_player()->hit_player(10);
      say(this_player()->query_name()+" is cut deeply by a crystal on north wall\n");
      return 1;
    }
  }
}

east()
{
  if(pass_found)
  {
    write("You enter east fracture slit.\n");
    this_player()->move_player("east into slit#players/kbl/chaos/cho44");
    return 1;
  }
  else
  {
    write("Things look strange here as you back away quickly!\n");
    if((this_player()->query_int()/(this_player()->query_intoxination()+1)) < 4)
    {
     write("You run away in fright!!!! You saw a gross figure in the crystal!\n");
     say(this_player()->query_name()+" runs away south, screeming!!\n");
     this_player()->move_player("running southward#players/kbl/chaos/cho35");
     return 1;
    }
   else
   {
     write("Something flashed in the brownish rock, but it was only a\n");
     write("sparkle of light reflecting in the brownish crystal rock.\n");
     command("shiver",this_player());
     return 1;
   }
  }
}


look_it(str)
{
  if(str == "at walls" || str == "at wall" || str == "walls" || str == "wall")
  {
    say(this_player()->query_name()+" looks at the wall here.\n");
    write("Looking closer you see the walls are rippled for some reason.\n");
    write("Alot of stress has been placed on the lattice structure of the\n");
    write("dark crystal here. You notice a outcropping of brownish\n");
    write("crystal on the eastern wall. It looks DEADLY sharp and radiates\n");
    write("intense HEAT.\n");
    if(pass_found)
    {
      write("The brownish crystal outcropping is far enough away that you\n");
      write("can safely pass north or east.\n");
    }
    return 1;
  }
  if(str == "at outcropping" || str == "outcropping")
  {
    say(this_player()->query_name()+" looks at outcropping.\n");
    write("This outcropping of brownish crystal is extremely HOT. You can\n");
    write("feel the heat on the opposite side of the cave. You feel if you\n");
   write("touch the outcropping you will most certainly DIE!\n");
    return 1;
  }
  if(str == "at slit" || str == "slit")
  {
    if(pass_found)
    {
      say(this_player()->query_name()+" looks at slit.\n");
      write("A high density crystal pressure ridge is rubbing against the\n");
      write("exterior dark crystal that you currently stand on. The crystal\n");
      write("near the slit is seperating, whichs indicates this passageway\n");
      write("might collapse sometime in near future.\n");
      return 1;
    }
    else
    {
      write("What slit??\n");
      return 1;
    }
  }
}

search(str)
{
  if(!str)
   return;
  if(str == "walls" || str == "wall")
  {
   if(!pass_found)
   {
    say(this_player()->query_name()+" finds at slit in the northeast corner.\n");
    write("You find a fracture along two sides of a fissure joint running\n");
    write("down the north and east walls. The narrow slit north looms with\n");
    write("darkness but the east slit has a reddish tint of light coming\n");
    write("coming from it.  The crystal along the slits seems to move at\n");
    write("your touch.\n");
    pass_found = 1;
    return 1;
   }
   else
   {
     write("You see a slit in the north and east walls.\n");
     return 1;
   }
  }
}

touch(str)
{
  if(!str)
   return;
  if(str == "outcropping" || str == "brownish crystal")
  {
    write("You take INSANE heat damage, discharged from the outcropping!\n");
    say(this_player()->query_name()+" takes INSANE heat damage from brownish crystal outcropping!\n");
    this_player()->hit_player(80);
    return 1;
  }
  if(str == "walls" || str == "wall")
  {
    say(this_player()->query_name()+" touchs the wall.\n");
    write("The crystal on the wall is loosing its lattice structure. Its\n");
    write("shreading like wheat from the pressure here. It crumbles to your\n");
    write("touch.\n");
    return 1;
  }
}
