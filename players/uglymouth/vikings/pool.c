/* The pool gives entrance to the geiser system to extinguish the fire */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The bottom of the pool";
   long_desc="You're at the bottom of the pool. Some sunlight filters through, \n"
           + "but your vision is badly impaired by the turbulence of the \n"
           + "water falling into the pool. The ground is scattered with rocks. \n";
   dest_dir=({"/players/uglymouth/vikings/bay_mw","up", });
   items=({"water","Cool water, although it looks like it's boiling",
           "ground","A rock floor",
           "rocks","Rocks coloured green and grey with algae",
           "algae","Green and grey water plants", });
   }

void init() {
   ::init();
   add_action("lift","lift");
   }

int lift(string str) {
   if(str=="the second green rock" || str=="second green rock") {
      if(("/players/uglymouth/vikings/geiser")->cave_in()==1) {
         write("The entrance is collapsed, you cannot go further. \n");
         return 1;
         }
      write("You find a hole through which the water flows into a cave beyond it. \n"
          + "Suddenly the current catches you and sweeps you through the hole. \n");
      this_player()->move_player("with the current#players/uglymouth/vikings/geiser");
      return 1;
      }
   write("You can't get a good grip on it. \n");
   return 1;
   }
