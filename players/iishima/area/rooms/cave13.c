inherit "room/room";

void reset(int arg){

if (arg) return;

set_light(1);
short_desc="A Cave";
long_desc=("\
\n\
  This is the lair of the dragons.  Some are friendly, but some are VERY\n\
  dangerous.   Enter their realm at your own risk. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave11","south",
           "players/iishima/area/rooms/realm1","enter"});

items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Sever rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",
        "moister","This water was formed due to moister in the cave"});


clone_list = ({1, 1, "dragon", "players/iishima/area/monsters/bdragon", 0 });
::reset(arg);
replace_program("room/room");
}
