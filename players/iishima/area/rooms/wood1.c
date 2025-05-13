inherit "room/room";
void reset(int arg)
{

 if (arg) return;

  set_light(1);
  short_desc = "An old trail in a forest";
long_desc=("\
\n\
  As you walk along the old trail, you feel very alone.  Cold chills run up\n\
  and down your spine as you get the feeling you are being watched.  A small\n\
  animal scratches around in the trees above.  You think you see some light\n\
  to the west.  To the south, you see the entrance to a cave. \n\
\n\
");
 
  dest_dir=({
             "/players/iishima/area/rooms/cave1.c","south",
             "/players/iishima/area/rooms/val1.c","north",
             "/players/iishima/area/rooms/wood2.c","west"});

   items = ({"cave","The cave looks very dark and damp",
 
             "animal", "You cannot tell what kind of animal is making the noise, but you think it may be a squirrel",
"trail", "The trail is very dusty and has not been used in ages",
"trees", "These trees are very tall and very old.  They seem to reach the clouds",
"tree", "You notice one smaller tree and you think you hear an animal in it",

});
clone_list = ({1, 1, "squirrel", "players/iishima/area/monsters/squirrel", 0 });

::reset(arg);
replace_program("room/room");
}

 
