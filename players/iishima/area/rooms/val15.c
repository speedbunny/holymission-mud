inherit "room/room";
void reset(int arg){
if (arg) return;
set_light(2);
short_desc="In the knights quarters";
long_desc=("\
\n\
  This is main meeting place of the knights.  They greatly detest being\n\
  interrupted.   Upon entering all heads turn to you.  You have an uneasy\n\
  feeling about being here and you want to leave. \n\
\n\
");
dest_dir=({"players/iishima/area/rooms/val14","southwest"});

clone_list = ({ 1, 3, "knight", "players/iishima/area/monsters/zalkni", 0 });
::reset(arg);
replace_program("room/room");
}
