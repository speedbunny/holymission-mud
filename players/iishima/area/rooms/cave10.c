inherit "room/room";

void reset(int arg){

if (arg) return;

set_light(1);
short_desc="A cave";
long_desc=("\
\n\
  This cave is very damp.  Chills run up and down your spine as you look\n\
  around.   There are many stalagtites and stalagmites every where.  Water\n\
  slowly drips from the top of the cave.  Every once in a while a drop hits\n\
  you on the head.  There is a pit to the south, below you.  \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave9","north",
           "players/iishima/area/rooms/cave8","west",
           "players/iishima/area/rooms/knightroom","down"});

items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Several rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave"});
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",


::reset(arg);
replace_program("room/room");
}
 
