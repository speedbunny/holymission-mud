inherit "room/room";
void reset(int arg)
{

 if (arg) return;

  set_light(1);
  short_desc = "An old trail in a forest";
long_desc=("\
\n\
  The light from the west now looks brighter now.  You think you see\n\
  something moving where the light is coming from. \n\
\n\
");

  dest_dir=({"/players/iishima/area/rooms/wood1.c","east" });

::reset(arg);
replace_program("room/room");
}
