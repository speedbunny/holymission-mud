/* the village square after the fire has been put out */
inherit "room/room";

void reset(int arg) {
object man;

   if(!(man=present("man")) || !living(man)) {
      transfer(clone_object("/players/uglymouth/vikings/monsters/burned"),this_object());
      }

   if(arg) return 0;

   set_light(1);
   short_desc="The village square looks like a pool of thick black mud";
   long_desc="You are at the village square. \n"
           + "You stand up to your ankles is some kind of thick black mud, \n"
           + "filled with pieces of burned things. The well from where the \n"
           + "the villagers used to take their water lies in fragments at \n"
           + "your feet, still spilling small gushes of water into to mud. \n"
           + "The road goes north, east and west from here and a ruined \n"
           + "building, still standing upright, lies south of you. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad2","north",
              "/players/uglymouth/vikings/villroad3","east",
              "/players/uglymouth/vikings/house3","south",
              "/players/uglymouth/vikings/villroad1","west", });
   items=({"mud","A stinking pool of water, ashes, dirt and junk",
           "things","Pieces of wood, burned rags and more unidentifyable junk",
           "junk","Most of the junk is burned so badly you can't make out what it was",
           "well","It has been shattered by a spout of water under great pressure",
           "water","The water immediately gets soaked up in the muddy substance",
           "road","The roads funtion as a drain for the mud on the square",
           "building","A high blackened building towers the remains of the village", });
   smell="The muddy substance gives off the awful smell of decay and smoke. \n";

   replace_program("room/room");
   }
