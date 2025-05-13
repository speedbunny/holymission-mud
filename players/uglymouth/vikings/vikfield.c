/* the field before the big hall where the quest will finish */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="A field of snow before a big house";
   long_desc="You stand on a field that is covered with snow. To the east a pier reaches into the "
           + "sea. A big house stands in front of you, the only coloured thing in an otherwise "
           + "grey landscape. \n";
   dest_dir=({"/players/uglymouth/vikings/feasthall","south",
              "/players/uglymouth/vikings/vikpier","east", });
   items=({"field","A small square field lies before the house, but extends into the surroundings",
           "snow","White snow, but not sticky enough to make snowballs",
           "pier","A wooden pier where ships can be moared",
           "house","The only building as far as you can see. And it looks quite important",
           "sea","The sea looks dark and cold",
           "landscape","The white field changes into forest at the horizon",
           "forest","A dark forbidding forest", });

   replace_program("room/room");
   }
