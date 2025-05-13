/* Along northwest base of giant pine */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Tiny pine area, along northwest base of giant pine";
    long_desc = "So many small pines are growing here there's no place\n"+
                "to go but back the way you came it seems. The small\n"+
                "pines are neat. They move to your touch and feel silky\n"+
                "smooth.\n";
    dest_dir = ({"players/kbl/pine/base1","southeast"});
    smell = "Odor of pine makes your senses tingle with its sweet and\n"+
            "bitter fragrance";
    property = "no_hide";
  }
}

init()
{
  ::init();
}
