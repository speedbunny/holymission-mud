/* North fracture pathway */

inherit "room/room";
int sec_d;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    sec_d = 0;
    set_light(0);
    short_desc = "Fracture along fissure joint";
    long_desc = "Here it looks as if the lower density dark crystal has\n"+
                "been seperated from the high density dark crystal. This\n"+
                "area is trembles continously and you feel this passageway\n"+
                "might not be here for long. The north wall is smooth and\n"+
                "blocks the passageway.\n";
    dest_dir = ({"players/kbl/chaos/cho36","south"});
    smell = "a tinge of acidity sulfur greets your nostrals";
    property = "no_hide";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("north","north");
  add_action("search","search");
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at joint" || str == "at fissure" || str == "joint" ||
     str == "fissure")
  {
    say(this_player()->query_name()+" looks at fissure joint.\n");
    write("This pressure ridge of high density dark crystal looks smooth\n");
    write("and unbreakable. It moves very slowly as you look closer, but\n");
    write("it moves in a curving motion, back into the wall, very strange!\n");
    return 1;
  }
  if(str == "at north wall" || str == "north wall")
  {
    say(this_player()->query_name()+" looks at north wall.\n");
    write("The wall is unnaturally smooth. The part near the fissure is\n");
     write("seperated, showing the semi-metallic rods that provide\n");
     write("stabilization for the north wall against the movement of the\n");
     write("fissure joint.\n");
     if(sec_d)
      write("A secret door can be seen here, ajar.\n");
     return 1;
  }
  if(str == "up")
  {
    say(this_player()->query_name()+" looks up.\n");
    write("You can see the seperation of the north wall from the natural\n");
    write("ceiling. Dust is falling here and decays as if falls past you.\n");
    write("The dust is do fine by the time it reachs your level, it cannot\n");
    write("be seen.\n");
    return 1;
  }
  if(str == "down")
  {
    say(this_player()->query_name()+" looks down.\n");
    write("Dust covers you feet. So fine is this 'dust' that it flows like\n");
    write("water along the floor of this area. It decays at your touch.\n");
    return 1;
  }
}

search(str)
{
  int val;
  if(!str)
   return;
  if(str == "north wall")
  {
    if(!sec_d)
    {
      val = (this_player()->query_dex()+this_player()->query_int())-
            this_player()->query_intoxination()/2;
      if(val > 47)
      {
      say(this_player()->query_name()+" finds secret door in north wall.\n");
      write("You find a secret door in north wall. It was well hidden.\n");
      sec_d = 1;
      return 1;
      }
      else
      {
        say(this_player()->query_name()+" can't seem to find anything here.\n");
       write("You can't seem to find anything here\n");
        return 1;
      }
    }
    else
    {
      write("You can see a secret door there already.\n");
      return 1;
    }
  }
}

north()
{
  if(sec_d)
  {
    write("You enter secret door to...\n");
    this_player()->move_player("through secret door#players/kbl/chaos/cho9");
    return 1;
  }
  return;
}
