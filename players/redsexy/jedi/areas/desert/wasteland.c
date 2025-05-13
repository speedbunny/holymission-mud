inherit "room/room";

setup(str) {
  int exit;
  dest_dir=explode(str, "#");
  exit=0;
  while(exit<sizeof(dest_dir)) {
    dest_dir[exit]="players/redsexy/jedi/areas/desert/d"+dest_dir[exit];
    exit+=2;
  }

        set_light(1);

        short_desc = "Venturing over a vast landscape of desertland";     
        long_desc = "\
You are walking through what seems to be miles and miles of desert \
wasteland, the sun beating down your neck and your sense of direction \
blurred by the sameness of the area you travel.  This area spreads on \
for many miles in every direction and you think you may well be lost.  \
You cannot imagine how you ended up in such a godforsaken place, and \
long to find a refuge of some kind.\n\n";

  items = ({
            "sand", "The sand spreads on for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",
            "sun", "Two suns emit heat so powerful you are surprised you \
haven't melted",
            "refuge", "You doubt you will ever find refuge in this hellhole"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/wasteland");
}


