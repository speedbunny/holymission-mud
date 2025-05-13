/* the end of the beach, right before the village */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="You are at the south end of the beach";
   long_desc="You are at the south end of the beach. \n"
           + "Through the air, which shimmers with heat, a village can be seen. The air is \n"
           + "filled with unhealthy smoke. Just south of you begins a large jungle. \n";
   dest_dir=({"/players/uglymouth/vikings/fireroad1","southeast",
             "/players/uglymouth/vikings/jungle_e","south",
             "/players/uglymouth/vikings/jungle_n","west",
             "/players/uglymouth/vikings/bay_s","northwest", });
   items=({
           "beach","A somewhat smokey beach, surrounding the bay",
           "bay","You clearly see a viking ship at the entrance of the bay to the open sea",
           "sea","The heavenly blue sea looks somewhat out of context, given the situation",
           "ship","A big longship, shaped like a dragon",
           "air","It shimmers with heat and is dark of smoke",
           "smoke","The dirty black smoke of an enormous fire",
           });
   }

void init() {
   ::init();
   add_action("look","look");
   add_action("look","l");
   add_action("look","examine");
   add_action("enter","southeast");
   }

int look(string str) {
   if(str!="village" && str!="at village") return 0;
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      write("The village is burning fiercely. Already here you feel the heat \n"
          + "scorching a bit of your hair. You feel it's not safe to go there. \n");
      return 1;
      }
   write("You look at the ruins of what once was a thriving coastal village. \n"
       + "Some parts are still glowing, but it seems safe to enter it. \n");
   return 1;
   }

int enter() {
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      write("The flames burn you badly as you enter the village. \n");
      this_player()->hit_player(random(5)+1);
      this_player()->move_player("southeast#players/uglymouth/vikings/fireroad1");
      return 1;
      }
   this_player()->move_player("southeast#players/uglymouth/vikings/villroad1");
   return 1;
   }

void vikings_leave() {
   items=({
           "beach","A somewhat smokey beach, surrounding the bay",
           "bay","A calm part of the sea, for the biggest part closed in by land",
           "sea","The heavenly blue sea looks somewhat out of context, given the situation",
           "air","It shimmers with heat and is dark of smoke",
           "smoke","The dirty black smoke of an enormous fire",
           });
   }

void vikings_arrive() {
   items=({
           "beach","A somewhat smokey beach, surrounding the bay",
           "bay","You clearly see a viking ship at the entrance of the bay to the open sea",
           "sea","The heavenly blue sea looks somewhat out of context, given the situation",
           "ship","A big longship, shaped like a dragon",
           "air","It shimmers with heat and is dark of smoke",
           "smoke","The dirty black smoke of an enormous fire",
           });
   }
