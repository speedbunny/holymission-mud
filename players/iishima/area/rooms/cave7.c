inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="A cave";
long_desc=("\
\n\
  This cave is very damp.  Chills run up and down your spine as you look\n\
  around.   There are many stalagtites and stalagmites every where.  You\n\
  notice a strange carving to your left.  It looks quite old. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave4","northwest",
           "players/iishima/area/rooms/cave8","east"});
items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Sever rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",
        "moister","This water was formed due to moister in the cave",
        "carving","This carving is quite old. It is of a man being slain by a dark knight"});

clone_list = ({ 1, 2, "bat", "players/iishima/area/monsters/bear", 0 });

::reset(arg);
replace_program("room/room");
}
