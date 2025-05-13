inherit "room/room";

void reset(int arg) {

if (arg) return;
set_light(2);
short_desc="A cave";
long_desc=("\
\n\
  This cave is very damp.  Chills run up and down your spine as you look\n\
  around.   There are many stalagtites and stalagmites every where.  Many\n\
  ancient paintings and writings are located on the cave walls. \n\
\n\
");


dest_dir=({"players/iishima/area/rooms/cave5","west",
           "players/iishima/area/rooms/cave9","southeast"});
items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
        "cave","The cave has little light and the walls are damp",
        "stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
         "stalagmite","You notice one hug rock standing tall enough to reach the ceiling",
        "stalagmites","Sever rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",
        "moister","This water was formed due to moister in the cave",
        "painting","This old painting is of a man slaying a bear",
        "paintings","There are many paintings. Some are hard to understand",
        "writings","It reads: 'ncsmlc jqc ruwzqj'"});
clone_list = ({ 1, 3, "bear", "players/iishima/area/monsters/bear", 0 });

::reset(arg);
replace_program("room/room");
} 
