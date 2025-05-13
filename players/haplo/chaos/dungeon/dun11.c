inherit "room/room";
int  fnd;

reset(arg)
{
  if(!arg)
  {
    fnd = 0;
    set_light(1);
    short_desc = "Bottom of a natural pit. Many vines hang down from above";
    long_desc = "A 5 meter in diameter pit with water rushing by to\n"+
                "the east. The water comes from a opening in the south\n"+
                "wall and exits through another opening in the north wall.\n"+
                "The water is traveling at a high rate, you feel afraid\n"+
                "of it. You look up and see a opening with what looks\n"+
                "blue sky above that. Many vines hang down and you feel\n"+
                "you might be able to climb them.\n";
    items = ({"pit","You are standing at the bottom of it",
              "wall","It seems to be a natural erosion in the earth",
              "walls","Something looks weird on the east wall",
              "vines","Many sturdy vines grow down and touch the water",
              "vine","Sturdy vine grows down and touches the water",
              "water","Black water flowing fast from south to north",
              "sky","You look up at the sky. Looks a soft blue",
              "blue sky","You look up at the sky. Looks a soft blue"});
  }
}

init()
{
  ::init();
  add_action("climb","climb");
  add_action("search","search");
  add_action("enter","enter");
}

climb(str)
{
  if(!str)
   return;
  if(str == "vines" || str == "vine")
  {
    write("You start climbing the vines...\n");
    this_player()->move_player("by climbing vines#players/kbl/big_forest2");
    return 1;
  }
}

search(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "vines":
    case "walls":
         fnd = 1;
         tell_object(this_player(),"You found a crack in the east wall under"+
                                   " the vines.\n");
         break;
    default:
         tell_object(this_player(),"Search where?\n");
  }
  return 1;
}

enter(str)
{
  if(!str)
   return;
  if(!fnd)
  {
    tell_object(this_player(),"Enter what?\n");
    return 1;
  }
  if(str == "crack")
  {
    transfer(this_player(),"/players/kbl/dungeon/dun8");
    tell_room(this_object(),capitalize(this_player()->query_real_name())+
              " enters a crack in the wall.\n");
    command("look",this_player());
    return 1;
  }
}
