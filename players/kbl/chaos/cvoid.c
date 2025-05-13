/* Void below PPO Chaos */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Garbage pile below Chaos";
   long_desc = "You stand on a pile of fused garbage from 100+ generations\n"+
                "of DOC. Its just floating here in the void. RGB light hits\n"+
                "you directly in the eyes here causing trails of light that\n"+
                "persist when you close your eyes. This pile is stationary\n"+
                "below Chaos and its gravity seems to hold you here for the\n"+
                "most part.\n";
    property = "no_hide","no_steal";
    smell = "The air is bland here";
  }
}

init()
{
  ::init();
  add_action("look_it","look");
  add_action("look_it","scan");
  add_action("look_it","l");
  add_action("look_it","exa");
  add_action("search","search");
  add_action("push","push");
  add_action("enter","enter");
}

push(str)
{
  if(!str)
   return;
  if(str == "off garbage to chaos" || str == "off to chaos")
  {
    write("You push off garbage heading up...\n");
    this_player()->move_player("by pushing off garbage#players/kbl/chaos/cho43");
    say(this_player()->query_name()+" arrives coming up out of hole!\n");
    if(this_player()->query_dex() > 18)
    {
      say(this_player()->query_name()+" makes a nice landing on the ledge.\n");
      write("You land perfectly on the ledge surrounding the hole.\n");
      return 1;
    }
    if(this_player()->query_dex() > 12)
    {
      say(this_player()->query_name()+" just makes the ledge, stumbling.\n");
      write("You stumble as you land on the ledge.\n");
      return 1;
    }
    say(this_player()->query_name()+" trips and falls back into hole!\n");
    write("You trip and fall back into hole!\n");
    this_player()->move_player("be falling back into hole!#players/kbl/chaos/cvoid");
    return 1;
  }
  if(str == "off garbage to vortex" || str == "off to vortex")
  {
    write("You push off garbage towards the vortex!!!\n");
    this_player()->move_player("by pushing off to vortex!#room/void");
    return 1;
  }
}

enter(str)
{
  if(!str)
   return;
  if(str == "slit")
  {
    write("You enter the great Arch Demon Of Chaos's private chamber!\n");
    this_player()->move_player("by entering slit#players/kbl/chaos/private2");
    return 1;
  }
}

look_it(str)
{
  if(!str)
   return;
  if(str == "at vortex" || str == "vortex")
  {
    write("The RGB light is almost blinding against the blackness of the\n");
    write("void which surrounds everything. The vortex seems so close\n");
    write("that you may be able to reach it some how. Normal movement\n");
    write("here is like being underwater.\n");
    return 1;
  }
  if(str == "at void" || str == "void")
  {
    if(this_player()->query_int() > 12)
    {
      write("You see a slit to the north, just hanging in the void, maybe\n");
      write("you can enter it.\n");
      return 1;
    }
    if(this_player()->query_int() > 6)
    {
      write("You see a shimmering slit to the north, but it vanishes. Hmmmm.\n");
      return 1;
    }
    write("The void is black and seems as if there's nothing out there.\n");
    return 1;
  }
  if(str == "at chaos" || str == "chaos")
  {
    write("The Parallel Plane of Chaos is above you. It green overall\n");
    write("glow is the only way you could have told the difference\n");
    write("between the PP of Chaos and the surrounding void. Normal\n");
    write("movement here is not the same and you feel like your\n");
    write("swimming, buts there's no water!\n");
    return 1;
  }
  if(str == "at garbage" || str == "garbage")
  {
    write("The garbage is made up of all kinds of junk items and crystal.\n");
    write("You see axes, knives, swords, helms, armours, crystals, key,\n");
    write("money and more... All of it is fused together an not takeable.\n");
    return 1;
  }
}

search(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "garbage":
         write("You find nothing special\n");
         return 1;
    case "void":
         write("You wave your hands about in the void all around you.\n");
         look_it("void");
         return 1;
  }
}
