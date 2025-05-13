/* eastern part of dunes. low and boring. */
inherit "room/room";

void reset(int arg) {
object ob;

   ob=present("megalith");
   if(ob) {
      tell_room(this_object(),"Suddenly you are caught in a small sandstorm. \n");
      destruct(ob);
      }

   if(arg) return;

   set_light(1);
   short_desc="A low dune at the eastern part of the range";
   long_desc="You are at a lower dunehill, at the eastern end of the dunerange. \n"
           + "In the sand a path is formed that connects the shore north of here \n"
           + "with the bay to the south. \n";
   dest_dir=({"/players/uglymouth/vikings/shore1","north",
              "/players/uglymouth/vikings/bay_ne","south",
              "/players/uglymouth/vikings/dunes_m","west", });
   items=({"shore","To the north, back to the village and to safety...",
           "dunehill","A sandy hill",
           "dunerange","There are more dunes west of here",
           "sand","Very loose dunesand",
           "path","A path in the sand",
           "bay","A tropical bay, looking invitingly", });
   }

void init() {
   ::init();
   add_action("search","search");
   add_action("search","dig");
   }

int search(string str) {
object mlith;
   if(str!="sand" && str!="hill") return 0;
   if(present("megalith")) {
      write("You find nothing unusual in the sand. \n");
      return 1;
      }
   write("You scratch your hand on a big black stone. You dig it up completely. \n");
   say(this_player()->query_name()+" digs up a big stone from the sand. \n",this_player());
   mlith=clone_object("/players/uglymouth/vikings/items/megalith");
   mlith->set_read("/ \n" + "O \n" + "/ \n");
   transfer(mlith,this_object());
   return 1;
   }
