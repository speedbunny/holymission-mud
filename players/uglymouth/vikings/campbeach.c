/* the entrance to the ship */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="At a small stroke of beach";
   long_desc="You are at a small stroke of beach. This is the place where the vikings \n"
           + "moor their rowing boat and keep contact with the ship by means of a \n"
           + "signalling fire. The camp lies to the west. \n";
   dest_dir=({"/players/uglymouth/vikings/camp2","west", });
   items=({
      "beach","A sunny, white beach",
      "bay","A calm piece of the sea",
      "sea","A heavenly blue sea, reflecting the sun on the surface",
      "fire","A small fire build on a heap of stones",
      "stones","Just ordinary stones",
      "camp","In the camp the vikings celebrate their conquest by gambling and feasting",
      "ship","A large drakar rides at anchor at the entrance of the bay",
      "drakar","The viking's longship",
      });
   smell="It's good to smell the cool and salty air of the sea again. \n";

   ("/players/uglymouth/vikings/rowboat")->dummy();
   }

void init() {
   ::init();
   add_action("swim","swim");
   }

int swim(string str) {
   if(!str || str=="sea" || str=="water") {
      write("You swim in the sea. \n");
      this_player()->move_player("into the warm water of the sea#players/uglymouth/vikings/shipsea");
      return 1;
      }
   return 0;
   }

void vikings_leave() {
object vik,*inv;
int i;
   long_desc="You're standing at a small stroke of beach. This place has a nice view \n"
           + "over the bay. A signalling fire has been built up here. To the west \n"
           + "some muddy ground can be seen. \n";
   items=({
      "beach","A sunny, white beach",
      "bay","A calm piece of the sea",
      "sea","A heavenly blue sea, reflecting the sun on the surface",
      "fire","A small fire build on a heap of stones",
      "stones","Just ordinary stones",
      "ground","Just a stroke of dirty mud",
      "view","At the horizon the light blue sky emerges with the sea in a shimmering haze",
      });
   vik=present("viking");
   while(vik) {
      inv=all_inventory(vik);
      for(i=0;i<sizeof(inv);i++) {
         destruct(inv[i]);
         }
      destruct(vik);
      vik=present("viking");
      }
   tell_room(this_object(),"The vikings arrive and put all their things into the rowing boat and leave. \n");
   return;
   }

void vikings_arrive() {
   long_desc="You are at a small stroke of beach. This is the place where the vikings \n"
           + "moor their rowing boat and keep contact with the ship by means of a \n"
           + "signalling fire. The camp lies to the west. \n";
   items=({
      "beach","A sunny, white beach",
      "bay","A calm piece of the sea",
      "sea","A heavenly blue sea, reflecting the sun on the surface",
      "fire","A small fire build on a heap of stones",
      "stones","Just ordinary stones",
      "camp","In the camp the vikings celebrate their conquest by gambling and feasting",
      "ship","A large drakar rides at anchor at the entrance of the bay",
      "drakar","The viking's longship",
      });
   tell_room(this_object(),"A rowing boat full with furious vikings arrives. They disembark, ransack \n"
      + "the nearby village and burn it down. Then they build up camp west of here. \n");
   return;
   }
