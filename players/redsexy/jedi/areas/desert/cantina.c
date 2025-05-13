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

        short_desc = "Approaching a structure on the edge of the desertland";     
        long_desc = "\
You shiver with delight as, just barely in the distance, you spot a \
building of some kind.  You feel as if you have been walking around in \
circles over this vast desert wasteland, and you long to find the right \
path to take you to this shelter.  Sweating profusely through the heat \
and feeling rather thirsty with the ever sweltering sun beating down,  \
your only thought is of how to reach this place.\n\n";

  items = ({
            "sand", "The sand spreads on for miles and miles in every \
direction",            
            "desert", "Miles of sand make this island look the same all \
over",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
            "shelter", "The building seems to be to the south, but the heat \
prevents you from going that way directly",
            "building", "You can just make out the shape of some kind of \
shelter on the horizon",
            "sun", "Two evil suns in the sky heat this desert landscape with \
an alarming ferocity"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/cantina");
}


