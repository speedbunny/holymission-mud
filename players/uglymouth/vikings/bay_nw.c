/* just a link between the river, the dunes and the bay */
inherit "room/room";
int stone;

void reset(int arg) {
object ob;

   ob=present("megalith");
   if(ob) {
      tell_room(this_object(),"Suddenly you are caught in a small sandstorm. \n");
      destruct(ob);
      }

   if(arg) return;

   set_light(1);
   short_desc="A hillside sloping down south and east into the bay";
   long_desc="You walk on a sandy hillside that slopes down south and east \n"
           + "into the bay. West of you rises the rock wall of a cliff \n"
           + "and the only way up seems to be a small path northwest. \n"
           + "South the thunder of a waterfall attracts your attention. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_s","north",
              "/players/uglymouth/vikings/highdune","northeast",
              "/players/uglymouth/vikings/bay_n","east",
              "/players/uglymouth/vikings/bay_mw","south",
              "/players/uglymouth/vikings/river_s","northwest", });
   items=({"bay","A sunny bay lies to the east",
           "cliff","A cliff towers up west. The river must flow up there",
           "wall","A natural wall of solid rock",
           "path","Just another dirt path",
           "waterfall","The water falls violently over the edge of a cliff", });
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
   mlith->set_read("| \n" + "|> \n" + "| \n");
   transfer(mlith,this_object());
   return 1;
   }
