inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Cloud City Cells";
    long_desc = "You are in a area with fluffy white clouds all around.\n";
    dest_dir = ({
                 "/room/church","church",
                 "/players/kbl/workroom","kbl",
                });
  property = "no_clean_up";
  }
}

init()
{
  ::init();
  event();
}

event()
{
  switch(random(10))
  {
    case 2:
        tell_room(TO,"Distant lightning bolts cross the sky.\n");
        break;
    case 4:
        tell_room(TO,"The wind whistles by giving you a happy feeling.\n");
        break;
    case 6:
        tell_room(TO,"You hear distant thunder.\n");
        break;
    case 8:
        tell_room(TO,"The sun peaks through the clouds momentarily.\n");
        break;
    default:
        tell_room(TO,"The air feels fresh with the gental breeze.\n");
  }
}
