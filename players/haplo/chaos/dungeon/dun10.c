/* Air flow source of KBLs dungeon cavern */

inherit "room/room";
reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Air flow source of KBL's cavern dungeon";
    long_desc = "You see many fragemented rocks lying about. Light filters\n"+
                "from above and you can feel the cool air flowing out here.\n"+
                "The cavern is north of here down a slope.\n";
    dest_dir = ({"players/kbl/dungeon/dun9","north",
                 "players/kbl/grounds/gro31","up"});
    smell = "Air is damp and cool";
    items = ({"rocks","Many rocks lying about and most crumble to your touch",
              "light","The light filters down from above. It feels warm",
              "cavern","The cavern is north and is filled with darkness"});
  }
}

init()
{
  ::init();
}
