/* Here I go: danger bay - part 1 (not so dangerous yet) */
inherit "room/room";
int i;

void reset(int arg)   {
   i = 5;
   if(arg) return;

   set_light(1);
   short_desc="The north side of the bay";
   long_desc="You've come to the northern side of a bay. \n"
           + "The beach is covered with white sand and small shells. \n"
           + "North behind a low dune lies a piece of shore, while a dunerange lies west. \n"
           + "The bay continues southwest. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_e","north",
              "/players/uglymouth/vikings/shallow","northeast",
              "/players/uglymouth/vikings/bay_n","southwest",
              "/players/uglymouth/vikings/highdune","west", });
   items=({"sand","fine white sand, warmed by the sun",
           "shells","All kinds of small shells brought here by the tide", });
   }

void init() {
   ::init();
   add_action("search","search");
   }

int search(string str) {
   if(str!="shells") return 0;
   if(i < 1 || random(10) < 7) {
      write("You find nothing special. \n");
      return 1;
      }
   write("You find a shell that might be worth something. \n");
   say(this_player()->query_name()+" searches among the shells and picks one up. \n",this_player());
   transfer(clone_object("/players/uglymouth/vikings/items/oyster"),this_player());
   i--;
   return 1;
   }
