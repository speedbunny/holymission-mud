inherit "room/room";
reset(arg){
::reset(arg);
if(arg)return;
set_light(1);

short_desc="Starslayers breeding pit\n.";
long_desc="This dark hole passes as Starslayers lab for testing \n"+
"wierd and wonderful creatures that he creates with the power of ed\n";
dest_dir=({"player/room/starslayer/workroom","hame"});
dest_dir=({"players/starslayer/workroom","hame"});
}
