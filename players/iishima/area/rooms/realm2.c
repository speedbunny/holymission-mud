inherit "room/room";

void reset(int arg){

if (arg) return;

set_light(1);
short_desc="The Dragon Realms";
long_desc=("\
\n\
  You have now entered the realm of the dragons.  The dragons here come in\n\
  many sizes and colors.  There is a rumor of a great dragon lord who once\n\
  ruled this place.  You keep that in mind as you look around. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/realm1","south",
           "players/iishima/area/rooms/realm3","north"});


clone_list = ({ 1, 1, "green dragon", "players/iishima/area/monsters/greendragon", 0,
                2, 1, "blue dragon", "players/iishima/area/monsters/bluedragon", 0 });
::reset(arg);
replace_program("room/room");
}
