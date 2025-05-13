inherit "room/room";

object dragon;

void reset(int arg){
if (arg) return;
set_light(2);
short_desc="The Dragon Realms";
long_desc=("\
\n\
  You have now entered the realm of the dragons.  The dragons here come in\n\
  many sizes and colors.  There is a rumor of a great dragon lord who once\n\
  ruled this place.  You keep that in mind as you look around. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/cave13","out",
           "players/iishima/area/rooms/realm2","north"});


items = ({ "entrance", "This place looks very mystical yet very old" });
clone_list = ({ 1, 1, "dragon", "players/iishima/area/monsters/greendragon", 0 });

::reset(arg);
replace_program("room/room");
}
