/* Making your way through the maze of limestone formations */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Twisting throught the limestone formations on cavern floor";
    long_desc = "The formations tower above you and there's not much room\n"+
                "to do much but go northwest or south. The water falling\n"+
                "noise is close but your unsure of the direction.\n";
    dest_dir = ({"players/kbl/dungeon/dun6","northwest",
                 "players/kbl/dungeon/dun12","west",
                 "players/kbl/dungeon/dun4","south"});
    smell = "Air is moist but tastless";
    property = "no_hide";
    items = ({"formations","Limestone stalagmites tower above you"});
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
  if(random(20) > 15)
   transfer(clone_object("players/kbl/objs/bat"),this_object());
}
