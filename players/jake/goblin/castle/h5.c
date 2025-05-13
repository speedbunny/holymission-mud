inherit "room/room";
int i;
object goblin;
reset (arg) {
if (!goblin) {
for (i=0;i<4;i++) {
goblin=move_object(clone_object("players/jake/goblin/castle/monsters/drunkard"),this_object());
}
if (arg) return;
set_light(2);
short_desc = "h5 ballroom";
long_desc = 
           "The castle ballroom.\n"
        +  "It appears that you have just missed a large celebration.\n"
        +  "A very large dining table lies overturned in the center of the room.\n"
        +  "Gold and silver goblets lay scattered across the floor.\n"
        +  "There are food stains all over the place.\n";
items = ({
 "floor","A red stone floor with numerous food stains covering it",
 "ceiling","A white stone ceiling with several stains on it",
 "wall","Grey stone walls.  There are crooked portraits hanging on the.\nFood stains cover the walls",
 "goblets","Gold and silver goblets.\nThey now lay scattered across the floor",
 "table","A very large over-turned wooden dining table",
 "untensils","Silver forks and knives scattered on the floor",
 "portraits","Pictures of famous goblin knights",
 "stains","Food and alcohol stains all over the place",
   });
dest_dir = ({
  "players/jake/goblin/castle/h4","west",
  "players/jake/goblin/castle/h5a","east",
 "players/jake/goblin/castle/j3","south",
  });
}
}
