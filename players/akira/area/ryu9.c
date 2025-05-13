inherit "room/room";
reset(tick){
if(tick) return;
set_light(1);
short_desc= "In a Pocket Dimension";
long_desc= "This is a dimensional prison created to hold the Great Dragon "+
           "Ryu. The gound has a light mist covering it, an th air is dry "+
           "and musty. The walls of this dimension are in a state of flux, "+
           "this makes it very hard to tell where you are going. Powerful "+
           "magic must have been used to create this prison.\n";
items= ({ "walls", "The seem to move and change shapes.",
          "mist", "The mist is a light green color."});
dest_dir = ({ "players/akira/area/ryu6", "south",
              "players/akira/area/ryu8", "west",
              "players/akira/area/ryu5", "southwest" });
}
