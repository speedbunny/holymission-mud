inherit "room/room";


object bear1;
object bear2;

void reset(int arg){
if (!bear1){
bear1 = clone_object("players/iishima/area/monsters/bear");
move_object(bear1,this_object());
}
if (!bear2){
bear2 = clone_object("players/iishima/area/monsters/bear");
move_object(bear2,this_object());
}

::reset(arg);
if(!arg){
set_light(2);
short_desc="A cave";
long_desc=("\
\n\
  This cave is very damp.  Chills run up and down your spine as you look\n\
  around.   There are many stalagtites and stalagmites every where.  Water\n\
  slowly drips from the top of the cave.  Every once in a while a drop hits\n\
  you on the head. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave6","east",
	   "players/iishima/area/rooms/cave4","southwest"});
items=({"stalagtite","This huge rock is hanging from the ceiling and almost touches the ground",
	"stalagtites","These rocks hang from the ceiling. Some almost reach the ground",
        "stalagmite","You notice one huge rock standing tall enough to reach the ceiling",
        "stalagmites","Sever rocks in front of you stand erect and several reach the ceiling",
        "water","This water was formed due to moister in the cave",
"drop", "You look up and a drop lands right between your eyes",
"cave", "The cave is very dark and damp",

        "moister","This water was formed due to moister in the cave"});
}
replace_program("room/room");
}

