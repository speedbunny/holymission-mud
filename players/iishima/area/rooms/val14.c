inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(2);
short_desc="In the knights quarters";
long_desc=("\
\n\
  This is the knights quarters.  All Zalpur knights live here.  To the north\n\
  is the main meeting place of the knights.  They do not like people walking\n\
  in on their meetings. \n\
\n\
");
         
dest_dir=({"players/iishima/area/rooms/val12","south",
           "players/iishima/area/rooms/val15","northeast"});

::reset(arg);
replace_program("room/room");
}

