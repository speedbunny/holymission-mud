/* Hallway off of entrance from outside stairs on 1st level */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Carved hallway inside giant pine on 1st level";
    long_desc = "This hallway goes north into the blackness and south\n"+
                "you see the light of a opening going outside. The walls\n"+
                "have that carved look. There's a doorway to the west side\n"+
                "of the hallway.\n";
    dest_dir = ({"players/kbl/pine/lvl1c","north",
                 "players/kbl/pine/lvl1s","south",
                 "players/kbl/pine/lvl1d","west"});
    smell = "Air tastes bland here with a hint of rotten wood";
  }
}

init()
{
  ::init();
}
