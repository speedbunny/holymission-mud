inherit "room/room";

void reset(int arg) {
if (arg) return;

set_light(2);
short_desc="A cave";
long_desc=("\
\n\
  This is the layer of the huge bear.  He is the ruler of all bears in the\n\
  cave.   He does not like to be bothered.  You can see remains of other\n\
  humans who tried to enter his layer.  You fear for your life. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave11","up"});

items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Sever rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",
        "moister","This water was formed due to moister in the cave"});

clone_list=({1, 1, "bear", "players/iishima/area/monsters/hugebear", 0});
::reset(arg);
replace_program("room/room");
}
