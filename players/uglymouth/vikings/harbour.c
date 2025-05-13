/* Not any longer harbour since the vikings landed here */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The former harbour of the village";
   long_desc="You are at a small stroke of beach, that served as a harbour. But that was \n"
           + "in the good old days before the vikings came. Now only the burned wrecks \n"
           + "of two rowing boats remain. Although you have a nice view over the bay, \n"
           + "the dark sand and water make you realize the misery of the situation. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad3","south", });
   items=({
           "beach","A stroke of black sand",
            "harbour","well, harbour... It's the place where the villagers pull their boats ashore",
            "wrecks","Thoroughly demolished and burned by the vikings",
            "boats","You doubt if you could even qualify them as wrecks",
            "view","This place could have been paradise, but the viking ship reminds you otherwise",
            "sand","It's dark from smoke and ashes",
            "viking ship","There are still people aboard of that bringer of destruction",
            "ship","There are still people aboard of that bringer of destruction",
            "bay","Right here, the water is coloured black with ashes. Further on it becomes blue",
            });
   smell="Your hope for fresh air get drowned as you smell the stench of the burning village. \n";
   }

void init() {
   ::init();
   add_action("south","south");
   add_action("swim","swim");
   add_action("swim","enter");
   }

int south() {
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      write("You make your way back into the living hell this village has become. \n");
      this_player()->hit_player(random(5)+1);
      this_player()->move_player("into the flames south#players/uglymouth/vikings/fireroad3");
      return 1;
      }
   this_player()->move_player("south#players/uglymouth/vikings/villroad3");
   return 1;
   }

int swim(string str) {
   if(str && str!="water") return 0;
   write("The water is too filled with ashes and wreckages to allow swimming. \n");
   say(this_player()->query_name()+" wades into the water and comes back with black legs.",this_player());
   return 1;
   }

void vikings_leave() {
   items=({
           "beach","A stroke of black sand",
            "harbour","well, harbour... It's the place where the villagers pull their boats ashore",
            "wrecks","Thoroughly demolished and burned by the vikings",
            "boats","You doubt if you could even qualify them as wrecks",
            "view","This place could have been paradise, if not for the burned village behind you",
            "sand","It's dark from smoke and ashes",
            "bay","Right here, the water is coloured black with ashes. Further on it becomes blue",
      });
   return;
   }

void vikings_arrive() {
   items=({
           "beach","A stroke of black sand",
            "harbour","well, harbour... It's the place where the villagers pull their boats ashore",
            "wrecks","Thoroughly demolished and burned by the vikings",
            "boats","You doubt if you could even qualify them as wrecks",
            "view","This place could have been paradise, but the viking ship reminds you otherwise",
            "sand","It's dark from smoke and ashes",
            "viking ship","There are still people aboard of that bringer of destruction",
            "ship","There are still people aboard of that bringer of destruction",
            "bay","Right here, the water is coloured black with ashes. Further on it becomes blue",
      });
   return;
   }
