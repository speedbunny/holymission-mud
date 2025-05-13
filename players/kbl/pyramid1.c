/* Village near Kbl's library */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Low wooden huts and buildings";
    long_desc = "A small hut is to your north and a squat building is\n"+
                "to the south. East looks like it heads into the middle of\n"+
                "this village. You can see a smoldering fire coming from a\n"+
                "pit in the center of this village. West a pathway leads out\n"+
                "of the village.\n";
    dest_dir = ({"players/kbl/pyramid2","south",
                 "players/kbl/pyramid3","north",
                 "players/kbl/pyramid4","east",
                 "players/kbl/plane3","west"});
    smell = "Animal hair and burnt flesh dominate the air *uck*";
  }
}

init()
{
  ::init();
}
