/* the beginning, go back while you can */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The edge of the jungle";
   long_desc = "You are walking in a dense jungle. To the north and east you can still \n"
      + "see the bay, but just barely. The jungle continues on beyond \n"
      + "your sight. Green trees and plants make an easy passage impossible.\n"
      + "Odd sounds seem to come from everywhere.\n";
   dest_dir=({"/players/uglymouth/vikings/bay_s","north",
              "/players/uglymouth/vikings/bay_se","east",
              "/players/uglymouth/vikings/infjungle1","south",
             "/players/uglymouth/vikings/jungle_w","west", });
   items=({"bay","You see more light to the north and east, but that's about all",
           "trees","Big and tall tropical trees from which you don't know the names",
           "plants","Many different green and coloured plants grow here", });
   smell="You smell all kinds of plants and flowers. \n";
   }

void init() {
   ::init();
   add_action("lost","south");
   }

int lost() {
int i;
   i=random(6)+1;
   this_player()->move_player("into the jungle#players/uglymouth/vikings/infjungle"+i);
   return 1;
   }
