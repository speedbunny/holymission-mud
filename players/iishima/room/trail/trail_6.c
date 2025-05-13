inherit "room/room";
object rabbit1;

void reset(int arg){

::reset(arg);
if (arg) return;

if (!rabbit1){
rabbit1 = clone_object("players/iishima/monsters/rabbit");
move_object(rabbit1,this_object());
}

set_light(2);
short_desc="A dusty trail";
long_desc="     This area is mostly barren. To the east the path goes straight into the\n"+
          "distance and to the west it begins to weave south. There are more trees there\n"+
          "which give it more shade.\n";
          
dest_dir=({"players/iishima/room/trail/trail_5","east",
             "players/iishima/room/trail/trail_7","south"});
items=({"path","An old, worn down path made of dirt. There are some hoof prints in it",
        "trail","An old, worn down trail made of dirt. There are some hoof prints in it",
        "sun","AHHHHHHHHH! You are blind",
        "trees","The trees to the south make a great shade"});

replace_program("room/room");
}

