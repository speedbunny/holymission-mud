/* southern part of the borderriver, with hidden waterelemental */
inherit "room/room";
int elpres;

void reset(int arg) {
   elpres=1;
   if(arg) return 0;

   set_light(1);
   short_desc="You walk downstream of a river";
   long_desc="You are downstream of a river, west of the dunes. \n"
           + "The river flows south towards a rocky plateau. You hear a clattering \n"
           + "sound there. The path that runs along the river also branches off \n"
           + "east and southeast. You feel the wild spirit of this place \n"
           + "lingering in the air. \n";
   dest_dir=({"/players/uglymouth/vikings/river_n","north",
              "/players/uglymouth/vikings/dunes_s","east",
              "/players/uglymouth/vikings/bay_nw","southeast",
              "/players/uglymouth/vikings/falltop","south", });
   items=({"river","The river streams unexpectedly fast here",
           "water","Clear and cold. Gurgling much wilder than you'd expect",
           "dunes","East you see a high hill towering up in the middle of the dunerange",
           "plateau","The river flows on the top of a cliff and disappears in the fog",
           "path","Another dirty mudpath, as you've walked many before", });
   }

void init() {
   ::init();
   add_action("swim","swim");
   add_action("swim","enter");
   add_action("swim","dive");
   }

int swim(string str) {
   if(!str || str=="river" || str=="water") {
      if(elpres==0) {
         write("The water is too wild to enter safely. \n");
         say(this_player()->query_name()+" thinks about drowning "+this_player()->query_objective()+"self.\n",this_player());
         return 1;
         }
      write("As soon as you touch the water a large fist of solid water rises \n"
          + "and knocks you back on the shore. Auch!.\n");
      this_player()->hit_player(random(10));
      say("A large fist of solid water rises from the river and attacks "+this_player()->query_name() + ".\n",this_player());
      transfer(clone_object("/players/uglymouth/vikings/monsters/welemental"),this_object());
      elpres=0;
      return 1;
      }
   return 0;
   }
