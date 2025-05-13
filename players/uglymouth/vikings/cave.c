/* A dark cave, looking interesting but it's a fake */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(0);
   short_desc="A cave behind the waterfall";
   long_desc="This is a very damp cave of smooth rock. \n"
           + "It is probably made by the waterfall over the ages. \n"
           + "It's empty. \n";
   dest_dir=({
      "/players/uglymouth/vikings/bay_mw","east",
      });
   items=({"rock","Solid rock, smoothed through erosion",
           "crack","Just a crack in the rock wall",
           "waterfall","It looks quite impressive from this side", });
   }

void init() {
   ::init();
   add_action("search","search");
   }

int search(string str) {
   if(str=="cave" || str=="rock" || str=="room") {
      write("You notice a small crack in the back wall of the cave. \n");
      return 1;
      }
   if(str=="crack") {
      write("The crack is small, but very deep.\n");
      return 1;
      }
   return 0;
   }
