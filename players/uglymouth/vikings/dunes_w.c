/* west part of dunes. looks nice, nothing special. */
inherit "room/room";

void reset(int arg) {
object ob;

   ob=present("megalith");
   if(ob) {
      tell_room(this_object(),"Suddenly you are caught in a small sand storm. \n");
      destruct(ob);
      }

   if(arg) return;

   set_light(1);
   short_desc="You're at the western part of the dunerange";
   long_desc="You walk in the sand of the western part of the dunerange. \n"
           + "Because of the river you hear babbling to the west, the vegetation is rather \n"
           + "green here, and getting even greener towards an open plain to the north. \n"
           + "Southeast you see a very high dunehill. \n";
   dest_dir=({"/players/uglymouth/vikings/open","north",
              "/players/uglymouth/vikings/dunes_m","east",
              "/players/uglymouth/vikings/dunes_s","south",
              "/players/uglymouth/vikings/river_n","northwest", });
   items=({"river","A river flows west of you, a path leading northwest to it",
           "path","Just a normal dirt path",
           "sand","Loose dune sand, blown here to form a small hill",
           "vegetation","Here grows grass that's less brown, and also some small bushes and trees",
           "bushes","Some small rhodondendrons, trying not to dry out",
           "trees","some small berches, too small to climb",
           "dunehill","That is the highest point in the area. Must have a nice view", });
   smell="You smell the fresh but humid air coming from the river. \n";
   }

void init() {
   ::init();
   add_action("search","search");
   add_action("search","dig");
   add_action("enter","enter");
   }

int search(string str) {
object mlith;
   if(str!="sand" && str!="hill" && str!="megalith" && str!="stone") return 0;
   if(str=="megalith" || str=="stone") {
      if(!present("megalith")) {
         write("What would you want to search?");
         return 1;
         }
      write("You find a small opening on the base of the stone. \n"
          + "It's big enough to let you in. \n");
      return 1;
      }
   if(present("megalith")) {
      write("You find nothing unusual in the sand. \n");
      return 1;
      }
   write("You scratch your hand on a big black stone. You dig it up completely. \n");
   say(this_player()->query_name()+" digs up a big stone from the sand. \n",this_player());
   mlith=clone_object("/players/uglymouth/vikings/items/megalith");
   mlith->set_short("A broken megalith");
   mlith->set_long("This must once have been a tall rectangular stone, black in colour. \n"
                 + "However, its upper part is missing. \n");
   transfer(mlith,this_object());
   return 1;
   }

int enter(string str) {
   if(str!="opening") return 0;
   if(!present("megalith")) {
      write("There is no opening here. \n");
      return 1;
      }
   write("You climb through the opening into a small tunnel. \n"
       + "After a short distance it ends in a larger space. \n");
   this_player()->move_player("into the sand#players/uglymouth/vikings/grave");
   return 1;
   }
