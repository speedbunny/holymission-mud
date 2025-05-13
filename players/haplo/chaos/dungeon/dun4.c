/* Cavern floor */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Floor of the cavern. This is a large chamber";
    long_desc = "Stalagmites rise from the floor to almost meet the\n"+
                "stalactites coming down from the chamber ceiling. The\n"+
                "only ways through the maze of limestone formations is\n"+
                "north or south here. You can see a slim pathway leading\n"+
                "up along the south wall. The noise of water falling is\n"+
                "almost most deafening here because it resounds through\n"+
                "the limestone formations.\n";
    dest_dir = ({"players/kbl/dungeon/dun5","north",
                 "players/kbl/dungeon/dun9","south",
                 "players/kbl/dungeon/dun3","up"});
    smell = "Air is moist and there is a hint of bat dung lingering";
  }
}

init()
{
  ::init();
}
