inherit "room/room";
#define MITE "/players/kbl/objs/mite"

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Dead end passage";
    long_desc = "Small alcove here in the cavern. Not much here.\n";
    dest_dir = ({
                 "/players/kbl/dungeon/dun12","east",
                });
    items = ({
              "alcove","There's not much here but empty space",
              "cavern","Its all around you",
             });
  }
  event();
}

init()
{
  ::init();
}

event()
{
  if(random(30) > 25)
   transfer(clone_object(MITE),this_object());
}
