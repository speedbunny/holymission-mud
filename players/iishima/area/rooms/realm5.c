inherit "room/room";

void reset(int arg){

if (arg) return;
set_light(1);
short_desc="The Dragon Realms";
long_desc=("\
\n\
  You have now entered the realm of the dragons.  The dragons here come in\n\
  many sizes and colors.  Huge volcanos tower above you, but looks like small\n\
  toys to the dragons.  From this great height, you can see the whole dragon\n\
  realm ...  except for one dark spot in the distance. \n\
\n\
");

dest_dir=({"players/iishima/area/rooms/realm4","down"});

clone_list = ({ 1, 1, "dragon", "players/iishima/area/monsters/whitedragon", 0 });
::reset(arg);
replace_program("room/room");
}
