/* the watery part */
inherit "room/room";

void reset(int arg)   {
   if(arg) return 0;
   set_light(1);
   short_desc="A shallow sea";
   long_desc="You're walking knee deep in the sea, wading through the waves \n"
           + "that are rolling on the beach. The water feels nicely warm. \n"
           + "You can wade southwest around a large rock to get into the bay beyond. \n"
           + "The sea gets deeper very fast, so you decide not to go in any further \n"
           + "You get the idea that there are larger dunes behind the first ones west. \n"
           + "From time to time a commuter, which brings adventurers to the island of\n"
           + "death, anchors in this part of the sea.\n";
   dest_dir=({"/players/uglymouth/vikings/shore1","west",
              "/players/uglymouth/vikings/bay_ne","southwest", });
   items=({"water","It's nice and warm. Small groups of tiny fish swim around your ankles",
           "rock","If you go up there, you probably will have a nice view over the bay",
           "waves","Small waves roll onto the white sand of the beach", 
           "fish","They are real tiny fish. You have to concentrate to see them clearly",
           "sea","A big blue sea, at the horizon melting with the sky",
           "dunes","A range of dunes runs along the coastline", });
   }

void init() {
   ::init();
   add_action("climb","climb");
   }

int climb(string str) {
   if(str!="rock" && str!="up") return 0;
   write("With some effort you manage to climb the slippery surface. \n");
   this_player()->move_player("up the rock#players/uglymouth/vikings/rock");
   return 1;
   }

