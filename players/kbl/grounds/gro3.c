/* Southeast corner outside KBLs castle */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Southeast corner outside of KBL's castle";
    long_desc = "You stand next to the steel gray wall on the southeast\n"+
                "of Kbls castle. Large spire of rock rises 45 degrees\n"+
                "from the whole east base of the castle. The way is blocked\n"+ 
                "north and south. North is the spire and south is a\n"+
                "75 meter drop. East, the drop off is 150 meters but\n"+
                "it looks like you could go down that way. You can hear\n"+
                "winds shifting overhead but very little wind makes it\n"+
                "to this spot.\n";
    dest_dir = ({"players/kbl/grounds/gro1","west",
                  "players/kbl/grounds/gro31","down"});
    smell = "The air is cool and odorless";
    property = "no_hide";
    items = ({"wall","Wall is looks like a rock-metal combination",
              "spire","Rocky spire looks like it was forced up by the\n"+
                      "the weight of the castle",
              "castle","Extends high above you and to the north and west",
              "east base","Small pieces of rocky rubble are piled here",
             "valley","The valley extends far to the horizon south. You\n"+
                      "can see a large body of water way off to the west\n"+
                      "as you scan the valley from west to east. East the\n"+
                      "valley continues towards the horizon. Looking\n"+
                      "directly south you see another mountain range off\n"+
                      "in the distance, it almost blends in with the\n"+
                      "color of the valley, at this distance",
             "mountains","The mountains extend eastward from this point,\n"+
                         "you cannot see the westward track of mountains\n"+
                         "from this area of the castle"});
  }
}

init()
{
  ::init();
  add_action("nor","north");
  add_action("sou","south");
  add_action("eas","east");
  wind();
}

wind()
{
  if(call_other("/players/kbl/grounds/gro1","query_wind_set"))
  smell = call_other("/players/kbl/grounds/gro1","query_wind_smell");
  else
   smell = "The air is cool and odorless";
}

nor()
{
  write("The way is blocked by too much debris!\n");
  say(this_player()->query_name()+" cannot go north because of rocky debris.\n");
  return 1;
}

sou()
{
  write("South the drop is 75 meters down a steep loose rocky slope.\n"+
        "You shy away.\n");
  say(this_player()->query_name()+" thinks twice about going south.\n");
  return 1;
}


eas()
{
  write("East the drop off is 150 meters! Its more cliff like tho and\n"+
        "looks climbable.\n");
  say(this_player()->query_name()+" goes over to the east drop off.\n");
  return 1;
}
