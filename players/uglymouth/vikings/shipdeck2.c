/* place for the mast and exit from the ship */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The middle of the longship";
   long_desc="You're at the middle of the ship's deck, at the foot of the mast. Both at "
           + "port-side and starboard-side are a bench and an oar. On the sides hang big round "
           + "shields, but there's been left space for a rope ladder to leave the ship. Sternward "
           + "a big tent is built on the deck. \n";
   dest_dir=({
      "/players/uglymouth/vikings/shipdeck1","front",
      "/players/uglymouth/vikings/shipdeck3","stern",
      });
   items=({"deck","The wooden deck of the longship",
           "longship","The viking's longship",
           "ship","The vikings' longship",
           "mast","A large pole carrying the sail and the crow's nest",
           "sail","The sail is reefed at the moment",
           "crow's nest","The place for the watch. Climb the mast to go there",
           "bench","A wooden bench for a rower to sit on",
           "oar","A wooden oar to row with if there's no wind or adverse wind",
	   "shields","Big, round, wooden shields for recognition and protection of the rowers",
           "ladder","A rope ladder leads off the ship",
           "tent","A big red and white tent. Obviously the captain has his seat there", });
   }

void init() {
   ::init();
   add_action("climb","climb");
   add_action("dive","dive");
   add_action("dive","swim");
   }

int climb(string str) {
   if(str && str!="mast" && str!="ladder" && str!="rope ladder") return 0;
   if(str=="mast") {
      write("You climb the mast to the crow's nest. \n");
      this_player()->move_player("up#players/uglymouth/vikings/crowsnest");
      return 1;
      }
   if(("/players/uglymouth/vikings/ship")->query_location()==1) {
      write("You climb down the rope ladder. \n");
      this_player()->move_player("down#players/uglymouth/vikings/vikpier");
      return 1;
      }
   if(("/players/uglymouth/vikings/rowboat")->query_location()!=1) {
      write("The rowboat is not there. But the shore is not so far away, maybe you can swim. \n");
      return 1;
      }
   write("You climb down the rope ladder. \n");
   this_player()->move_player("down#players/uglymouth/vikings/rowboat");
   return 1;
   }

int dive() {
object env;
   say(this_player()->query_name()+" dives into the sea",this_player());
   write("You dive into the sea. \n");
   if(("/players/uglymouth/vikings/ship")->query_location()==0) {
      this_player()->move_player("into the sea#players/uglymouth/vikings/shipsea");
      return 1;
      }
   this_player()->move_player("into the sea#players/uglymouth/vikings/viksea");
   return 1;
   }

void vikings_leave() {
object ob;
   ob = first_inventory(this_object());
   while(ob) {
      if(ob->query_player() && !present("the village medallion of symria",ob)) {
         tell_object(ob,"The Vikings have orders to leave and put you ashore.\n");
         ob->move_player("for the shore#players/uglymouth/vikings/campbeach");
         }
      ob = next_inventory(this_object());
      }
   }
