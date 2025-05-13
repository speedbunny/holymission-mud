inherit "room/room";
void reset(int arg) {

if (arg) return;

set_light(1);
short_desc="A cave";
long_desc=("\
\n\
  This cave is very damp.  Chills run up and down your the spine.  Every once\n\
  in a while a drop hits you on the head.  There are many stalagmites and\n\
  stalagtites everywhere.  Strange noises come from all around you.  You\n\
  cannot wait to leave this place. \n\
\n\
");
 
dest_dir=({"players/iishima/area/rooms/cave1","north",
           "players/iishima/area/rooms/cave3","south",
           "players/iishima/area/rooms/cave4","east"});

items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Huge rocks in front of you stand erect. A few even reach the ceiling",
        "water","This water was formed due to moisture in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",

        "moisture","This water was formed due to moisture in the cave"});

clone_list = ({ 1, 2, "bat", "players/iishima/area/monsters/bat", 0 });
::reset(arg);
replace_program("room/room");
}
