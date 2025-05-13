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

        short_desc = "Somewhere near the Port of Mos Eisley in the desertland";     
        long_desc = "\
You are walking through what seems to be miles and miles of desert \
wasteland, the sun beating down your neck and your sense of direction \
blurred by the sameness of the area you travel.  This area spreads on \
for many miles in every direction but you can make out the port in the \
distance and you can hear the Dune Sea, so you know that you are not \
lost yet.  \n\n";

  items = ({
            "sand", "The sand spreads on for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
            "port", "You can just see the Port of Mos Eisley to your north  \
over the desertland",
            "sea", "You can hear the waves of the Dune Sea lashing against \
the port from where you stand",
            "refuge", "You think the footprints may lead you to a refuge"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/port");
}


