/* Squat building in drow destroyed village */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Large low ceiling room with burnt remains around\n"+
                 "shattered ruins of thick pine tables.";
    long_desc = "Large room that looks as if it was some sort of eating\n"+
                "area. Everything has been burnt here including some\n"+
                "humonoid remains. Looking you see no windows or other\n"+
                "exits.\n";
    dest_dir = ({"players/kbl/pyramid1","north"});
    smell = "Burnt flesh mixed with burnt pine";
  }
}

init()
{
  ::init();
}
