/* the sea at the home land of the vikings */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="A cold part of the sea below a pier";
   long_desc="You are in a very cold part of the sea. Above you rises a pier which "
           + "is connected to the land. On the beams of the pier is a thin layer of ice. \n";
   dest_dir=({"/players/uglymouth/vikings/vikfield","west", });
   items=({"sea","A cold blue sea",
            "pier","A pier where ships can be moared. You can climb it",
            "beams","Solid wooden beams, slightly worn by the water",
            "ice","The ice is salty too... brrr it's really cold here", });
   }

void init() {
   ::init();
   add_action("climb","climb");
   }

int climb(string str) {
   if(str!="pier") return 0;
   write("You climb the pier with much effort. You're half frozen when you're on top of it. \n");
   this_player()->move_player("up the pier#players/uglymouth/vikings/vikpier");
   return 1;
   }
