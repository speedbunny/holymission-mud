/* Winding through the formations on the cavern floor */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Twisting around the formations on cavern floor";
    long_desc = "Tight passageway between these formations doesn't allow\n"+
                "for much room here. You can hear alot of water moving\n"+
                "very close by.\n";
    dest_dir = ({"players/kbl/dungeon/dun7","north",
                 "players/kbl/dungeon/dun5","southeast"});
    smell = "Air is odorless here but very moist";
    items = ({"formations","The stalagmites tower high above you"});
    property = "no_hide";
  }
  event();
}

init()
{
  ::init();
}

event()
{
  if(random(10) > 5)
   transfer(clone_object("players/kbl/objs/mite"),this_object());
  if(random(25) > 20)
  {
   transfer(clone_object("players/kbl/objs/bat"),this_object());
   transfer(clone_object("players/kbl/objs/bat"),this_object());
  }
}
