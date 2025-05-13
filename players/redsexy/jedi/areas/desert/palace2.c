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

        short_desc = "Nearing a grand palace hidden in the desertlands.";     
        long_desc = "\
You are on some kind of makeshift path, heading towards a grand structure \
to your south.  Cobblestones laid down in the sand lead in two directions \
from here, and you are uncertain of which direction to take.  The sun is \
almost making you sick, projecting such intense heat, and if you were to \
go directly towards the palace at least you would find immediate shelter.  \
But in the heat of the sun you cannot be certain if your sense of direction \
is just playing tricks on you, and you remain uncertain on which way to turn. \n\n";

  items = ({
            "sand", "The sand isreplaced with cobblestones here, leading \
in two directions",            
            "desert", "Miles of sand make thiswateland look the same all \
over, but thispath offers you hope of an escape",
            "wasteland", "Thisderelict wasteland isthe most disturbing \
place you have ever seen",       
            "shelter", "The palace to the south isa very regal structure. \
You are certain it would be heavily guarded",
            "palace", "A grand and regal structure.  You cannot help but to \
wonder if you could ever break through the security here",
            "structure", "A grand and regal structure.  You cannot help but to \
wonder if you could ever break through the security here",
            "path", "The path ispaved unevenly with cobblestones",
            "cobblestones", "Uneven cobblestones that form a path",
            "sun", "Two evil suns in the sky heat thisdesert landscape with \
an alarming ferocity"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/palace2");
}


