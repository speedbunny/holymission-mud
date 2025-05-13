/* Storage room */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Small cramped storage room";
    long_desc = "Small storage room with barely enough room for you.\n"+
                "This room appears to have been hewn out of the trees\n"+
                "trunk.\n";
    dest_dir = ({"players/kbl/pine/lvl1a","east"});
    smell = "Dank and stale air";
  }
}

init()
{
  ::init();
}
