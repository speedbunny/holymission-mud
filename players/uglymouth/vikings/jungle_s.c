/* the beginning, go back while you can */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="Deep in the jungle";
   long_desc="You are somewhere deep in the jungle. To every direction the "
           + "jungle continues forever, like it seems. All kinds of trees "
           + "and plants hinder you in your way around. "
           + "Odd sounds seem to come from everywhere. \n";
   dest_dir=({"/players/uglymouth/vikings/jungle_e","north",
              "/players/uglymouth/vikings/camp1","east",
              "/players/uglymouth/vikings/infjungle1","south",
              "/players/uglymouth/vikings/infjungle2","west", });
   items=({"jungle","A dense, humid, tropical jungle",
           "trees","Big and tall tropical trees. Huge roots burrow into the ground",
           "roots","Big roots of big trees. Some seem quite rotten",
           "plants","Many diffrent green and coloured plants grow here", });
   smell="You smell all kinds of plants and flowers. \n";
   }

void init() {
   ::init();
   add_action("lost","south");
   add_action("lost","west");
   add_action("east","east");
   add_action("search","search");
   }

int lost() {
int i;
   i=random(6)+1;
   this_player()->move_player("into the jungle#players/uglymouth/vikings/infjungle"+i);
   return 1;
   }

int east() {
int i;
   if(!(this_player()->query_quests("viking"))) {
      write("You've lost sense of where you're going. \n");
      i=random(6)+1;
      this_player()->move_player("into the jungle#players/uglymouth/vikings/infjungle"+i);
      return 1;
      }
   write("The viking in you finds a way to the viking camp. \n");
   this_player()->move_player("into the jungle#players/uglymouth/vikings/camp1.c");
   return 1;
   }

int search(string str) {
   if(str!="roots") return 0;
   write("You've found a secret tunnel that leads to the viking camp. \n");
   this_player()->move_player("between the bushes#players/uglymouth/vikings/camp1");
   return 1;
   }
