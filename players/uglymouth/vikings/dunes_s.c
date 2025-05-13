/* southern dunes. */
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
   short_desc="The southern part of dunerange";
   long_desc="You stand in soft sand at the low south end of the dunes. \n"
           + "To the east towers a huge dunehill. A small path leads west towards \n"
           + "a river. South of you the dunes slope down into the bay. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_w","north",
              "/players/uglymouth/vikings/bay_nw","south",
              "/players/uglymouth/vikings/river_s","west", });
   items=({"dunehill","On this side it's covered thickly with thornbushes. It's very high",
           "path","A small dirt path",
           "river","Follow the path to go there and see it", 
           "sand","Sand, blown here on the wind has formed the hill you're standing on",
           "bay","It looks like a nice tropical bay", });
   }

void init() {
   ::init();
   add_action("climb","climb");
   add_action("destroy","destroy");
   add_action("destroy","cut");
   add_action("search","search");
   add_action("search","dig");
   }

int climb(string str) {
   if(str!="dunehill" && str!="hill") return 0;
   write("You'd wound yourself badly if you tried to climb this steep hill through \n"
       + "all these thorny bushes. \n");
   say(this_player()->query_name()+" thinks about turning "+this_player()->query_objective()+"self into a hedgehog, climbing the hill. \n",this_player());
   return 1;
   }

int destroy(string str) {
   if(str!="bushes") return 0;
   write("You could keep yourself busy with that for some days. Use your time wiser!! \n");
   return 1;
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
   mlith->set_read("| > \n" + "|< \n" + "| > \n");
   transfer(mlith,this_object());
   return 1;
   }
