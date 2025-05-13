/* the road through the village after the fire has been put out */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The main road through the burned village";
   long_desc="You are on the main road through the village. \n"
           + "Or what is left of it... The damage is gigantic, and it will take \n"
           + "years before everything is rebuild. The black ruins of the buildings \n"
           + "north and south form a sad scene. The village square to the east looks \n"
           + "like a marsh of dark stinking mud. The beach northwest is the only place \n"
           + "that seems to have some lively colours in it. \n";
   dest_dir=({
              "/players/uglymouth/vikings/villsquare","east",
              "/players/uglymouth/vikings/bay_se","northwest", });
   items=({"road","The road is dark with ashes and scattered with logs of burned wood",
           "logs","It breaks into small black pieces as you touch it",
           "buildings","the northern or the southern building?",
           "northen building","On the ashes of a board you make out the words 'Pink Salmon Inn'",
           "southern building","It looks like the ruins of a place where people used to live",
           "square","This must once have been the most important place of the village",
           "beach","If only everything would be as lovely as that sunny beach...", });

   replace_program("room/room");
   }
