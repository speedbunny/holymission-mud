/* the bow of the ship */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The bow of the longship";
   long_desc="This is the bow of the longship. A big dragon's head towers above you, coloured red. "
           + "Both on port-side and starboard-side are a wooden bench and an oar. Big shields "
           + "cover the side of the ship. Sternward you see the mast and a big red and white tent "
           + "that is built over the ship. \n";
   dest_dir=({
      "/players/uglymouth/vikings/shipdeck2","stern",
      });
   items=({"bow","The front of the ship",
           "longship","The vikings' longship",
           "head","A big, red dragon's head carved of wood looks threatening over the sea",
           "bench","A wooden bench for a rower to sit on",
           "oar","A wooden oar to row with if there's no wind or adverse wind",
           "shields","Big round shields for recognition, decoration and protection of the rowers",
           "mast","A tall wooden pole that carries the sail",
           "sail","It's reeved for the moment",
           "tent","A shelter for the captain and also feasting area", });

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
