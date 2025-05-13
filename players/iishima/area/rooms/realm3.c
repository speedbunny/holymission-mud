inherit "room/room";


void reset(int arg){

if (arg) return;

set_light(1);
short_desc="The Dragon Realms";
long_desc=("\
\n\
  You have now entered the realm of the dragons.  The dragons here come in\n\
  many sizes and colors.  Huge volcanos tower above you, but looks like small\n\
  toys to the dragons. \n\
\n\
");


dest_dir=({"players/iishima/area/rooms/realm2","south",
           "players/iishima/area/rooms/realm4","east"});


clone_list = ({ 1, 2, "dragon", "players/iishima/area/monsters/bluedragon", 0 });
::reset(arg);
replace_program("room/room");
}
