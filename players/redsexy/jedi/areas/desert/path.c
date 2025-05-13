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

        short_desc = "Following a cobble path through the desert wasteland.";     
        long_desc = "\
You are on some kind of makeshift path, which now winds away from the palace  \
and seems to be heading into some kind of town.  You feel happy to have found \
some sign of a civilised way of survival in this barren wasteland, but an  \
ominous voice in the back of your head tells you not to get too comfortable \
in your illusions of safety.  You walk on through the heat, praying that you   \
will never again have to endure such preposterous conditions for the sake of   \
proving yourself as a great adventurer. \n\n";

  items = ({
            "sand", "The sand is replaced with cobblestones here",            
            "desert", "Miles of sand make this wateland look the same all \
over, but this path offers you hope of an escape",
            "wasteland", "This derelict wasteland is the most disturbing \
place you have ever seen",       
            "palace", "The palace can no longer be seen from here",
            "path", "The path is paved unevenly with cobblestones",
            "cobblestones", "Uneven cobblestones that form a path",
            "sun", "Two evil suns in the sky heat this desert landscape with \
an alarming ferocity",
            "town", "There seems to be a town at the end of this ever winding \
path"
 });
  if(strstr(file_name(), "#")!=-1)
        replace_program("players/redsexy/jedi/areas/desert/path");
}


