/* Level 1 stairs and entrance */

inherit "room/room";

reset(arg)
{

  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Stair way on northeast side of giant pine";
    long_desc = "You see the stairs continue upward and there's a opening\n"+
                "leading into the tree here. You are about 200 meters off\n"+
                "the ground here. East a white wall can be seen rising as\n"+
                "high up as you can see. The tree brushes against it making\n"+
                "a grating noise like wood on stone.\n";
    dest_dir = ({"players/kbl/pine/lvl2s","up",
                 "players/kbl/pine/base2","down",
                 "players/kbl/pine/lvl1a","enter"});
    smell = "Air is fresh and has a sweet pine taste";
    property = "no_hide","no_sneak";
  }
}

init()
{
  ::init();
}
