/* the captain's place */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The tent on the ship's deck";
   long_desc="You are in the tent on the ship's deck. Here too are benches and oars for "
           + "rowers. In the centre stands a big table, used for both navigation and feasting. "
           + "Bowward the mast rises into the air. Some barrels stand next to the table. \n";
   dest_dir=({
      "/players/uglymouth/vikings/shipdeck2","front",
      "/players/uglymouth/vikings/shipdeck4","stern",
      });
   items=({"tent","A tent made of sturdy red and white coloured canvas",
           "benches","Wooden benches for rowers to sit on",
           "oars","Wooden oars to row with if there is no wind or adverse wind",
           "table","A long wooden table. Some papers lie on it",
           "papers","There's something written on them",
           "mast","A long wooden pole carrying the sail",
           "barrels","Two barrels containing mead", });
   }

void init() {
   ::init();
   add_action("read","read");
   }

int read(string str) {
   if(str!="papers") return 0;
   write("It's written in a language you don't understand. \n");
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
