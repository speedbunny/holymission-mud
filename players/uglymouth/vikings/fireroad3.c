/* the eastern road through the village */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="You are at the eastern side of the burning village";
   long_desc="You are on the eastern road of the burning village. \n"
           + "The first thing you notice is an exit from this hell to a small stroke \n"
           + "of beach the villagers used to moor their boats. Flames leak from the \n"
           + "buildings east and south. The road looks like a black and red carpet \n"
           + "of ashes and glowing charred logs of wood. \n";
   dest_dir=({"/players/uglymouth/vikings/harbour","north",
              "/players/uglymouth/vikings/house5","east",
              "/players/uglymouth/vikings/house4","south",
              "/players/uglymouth/vikings/firesquare","west", });
   items=({"beach","Although it has been coloured grey by the ashes, it's a safe place to be",
           "boats","You see some wrecks of rowingboats through the smoke",
           "flames","Purple and orange flames are shooting out of the southern building",
           "fire","This must really be the largest and most disastrous fire you've ever seen",
           "buildings","The eastern or the southern building?",
           "eastern building","This large house must be the chief's. It's still quite intact",
           "southern building","From it leak purple and orange flames. You wonder what's inside...",
           "road","You think this road will be black forever after", });
   smell="The smell of the burning of bad materials fills your nose and almost makes you faint. \n";
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("south","south");
   add_action("west","west");
   add_action("east","east");
   }

int south() {
   write("The small explosions you hear in the house make you decide \n"
       + "it's better not to go in there. \n");
   return 1;
   }

int west() {
   write("A glowing piece of wood hits your head as another part of a building collapses. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("through the flames west#players/uglymouth/vikings/firesquare");
   return 1;
   }

int east() {
   write("You can't go in because the the door and the part of the wall \n"
       + "that contains it are burning fiercely. \n");
   return 1;
   }
