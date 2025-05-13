/* Narrow passageway in the cavern */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Narrow passageway";
    long_desc = "You are in a narrow passageway between two huge limestone\n"+
                "formations. The passageway slopes down sharply from south\n"+
                "to north. Its very cramped in here. You can hear water\n"+
                "flowing somewhere. The noise seems to bounce around here.\n";
    dest_dir = ({"players/kbl/dungeon/dun4","north",
                 "players/kbl/dungeon/dun10","south"});
    smell = "Limestone dust in the air makes you thirsty";
    property = "no_hide";
    items = ({"passageway","Formed by water at sometime in the past. Narrow\n"+
                           "and has a low ceiling",
              "limestone","Makes up the walls and ceiling of this passageway",
              "limestone formations","You look at the limestone on the walls"});
  }
  event();
}

init()
{
  ::init();
}

event()
{
  if(random(25) > 20)
   transfer(clone_object("players/kbl/objs/norker"),this_object());
}
