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

        short_desc = "Somewhere near a town in the desertland";     
        long_desc = "\
You are walking through what seems to be miles and miles of desert \
wasteland, the sun beating down your neck and your sense of direction \
blurred by the sameness of the area you travel.  This area spreads out \
for many miles in every direction and you think you may well be lost.  \
Unlike the other parts of this desert,  there are footprints here, \
and you imagine that this area must be travelled through regularly. You \
realise there must be some kind of town near here, and pray that you can \
find it before you die.\n\n";

  items = ({
            "sand", "The sand spreads out for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
            "footprints", "They seem to track to the south from here and \
towards some kind of town",
            "sun", "Two suns emit heat so powerful you are surprised you \
haven't melted",
            "refuge", "You think the footprints may lead you to a refuge"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/wasteland");
}


