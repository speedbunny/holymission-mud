/* Middle of the dunerange. Maybe I'll hide here something. */
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
   short_desc="You walk in the middle of the dunes";
   long_desc="You are in the middle of the dunes. As you try to walk, you sink up \n"
           + "to your ankles into the loose dunesand. You stop a moment to catch your \n"
           + "breath as you realize the amount of energy it will cost to climb the \n"
           + "high dunehill south of you. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_n","north",
              "/players/uglymouth/vikings/dunes_e","east",
              "/players/uglymouth/vikings/highdune","south",
              "/players/uglymouth/vikings/dunes_w","west", });
   items=({"dunes","As you are in the middle of the range, they are all around you",
           "dunesand","Fine sand, blown here on the wind",
           "sand","Fine sand, blown here on the wind",
           "dunehill","It's a challenge to climb its sandy steep to the top!", });
   }

void init() {
   ::init();
   add_action("south","south");
   add_action("search","search");
   add_action("search","dig");
   }

int south() {
int i;
   i=random(30);
   if(i>this_player()->query_con()) {
      write("You start full of hope to with the climb to the top. But after a while you \n"
          + "grow so tired that you slip and roll back down to where you started. \n");
      return 1;
      }
   write("Breathing heavily you manage to reach to top.\n");
   this_player()->move_player("up the high hill#players/uglymouth/vikings/highdune");
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
   mlith->set_read("  | \n" + ": |/| \n" + "    | \n");
   transfer(mlith,this_object());
   return 1;
   }
