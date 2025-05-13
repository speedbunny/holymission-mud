inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="The Dragon Realms";
long_desc=("\
\n\
  You have now entered the realm of the dragons.  The dragons here come in\n\
  many sizes and colors.  Huge volcanos tower above you, but looks like small\n\
  toys to the dragons.  Dragons fly over your head spitting fire and causing\n\
  destruction to anything they pass. \n\
\n\
");


dest_dir=({"players/iishima/area/rooms/realm5","up",
           "players/iishima/area/rooms/realm6","down",
           "players/iishima/area/rooms/realm3","west"});

clone_list = ({ 1, 1, "blue dragon", "players/iishima/area/monsters/bluedragon", 0,
                2, 1, "red dragon", "players/iishima/area/monsters/reddragon", 0 });
::reset(arg);
replace_program("room/room");
}
