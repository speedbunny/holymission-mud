inherit "room/room";

void reset(int arg){
if (arg) return;
set_light(2);
short_desc="In a valley";
long_desc=("\
\n\
  You are standing at the eastern entrance to the razaur town.  To the west\n\
  Is a huge mountain chain.  To the east is the small town of the Zalpurs. \n\
  This part of the valley is the habitat for many small animals.  Small\n\
  rabbits hop up and down, playing games in the clover. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val12","east"});

items=({"mountains","This mountain chain stretches across the valley",
        "chain","This mountain chain stretches across the valley",
        "mountain chain","This mountain chain stretches across the valley", 
        "mountain","This mountain chain stretches across the valley", 
        "rabbits","These little, white rabbits hop around playing games with each other"});
         

clone_list = ({ 1, 3, "rabbit", "players/iishima/area/monsters/rabbit", 0 });
::reset(arg);
replace_program("room/room");
}

