inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Chaotic Cloud Cells";
    long_desc = "You are in a room with horribly turbulent weather.\n";
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
        tell_room(TO,"Several lightning bolts cross the sky.\n");
        break;
    case 4:
        tell_room(TO,"Rain comes down hard and wind picks up fast!\n");
        break;
    case 6:
        tell_room(TO,"Several close flashes followed by alot of thunder!\n");
        break;
    case 8:
        tell_room(TO,"The wind wips by almost taking you with it.\n");
        break;
    default:
        tell_room(TO,"The wind swirls around with rain dancing in its flow\n");
  }
}
