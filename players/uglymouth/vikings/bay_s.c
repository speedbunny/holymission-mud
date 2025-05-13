/* border bay - jungle */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The southern part of the bay";
   long_desc="Southeast of you lies the end of the beach. \n"
           + "Above it hangs a huge, dark cloud of smoke. You stand at the \n"
           + "northern border of a dense jungle, from which you hear many \n"
           + "strange sounds coming... \n";
   dest_dir=({"/players/uglymouth/vikings/bay_m","north",
              "/players/uglymouth/vikings/bay_se","southeast",
              "/players/uglymouth/vikings/jungle_n","south",
              "/players/uglymouth/vikings/bay_sw","west", });
   items=({"beach","A tropical beach, overshadowed by a dark cloud",
           "cloud","A cloud of smoke drifts from the nearby village",
           "smoke","It looks like it must have been caused be a huge fire",
           "village","It's hidden behind trees",
           "fire","You don't see the fire, but you see the air shimmering with heat",
           "trees","Large palms and mangroves",
           "jungle","It looks like you could easily get lost there", });

   replace_program("room/room");
   }
