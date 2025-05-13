/* the house of the shipwright */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The ruins of the shipwright's house";
   long_desc="The shipwright's house has burned down almost completely. "
          + "Only the corner beams are still standing. Ashes are everywhere. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad2","west", });
   items=({
      "ashes","Dark grey ashes give it all a sad look",
      "beams","Strong wooden poles that used to carry the structure",
      });
   }

void init() {
   ::init();
   add_action("west","west");
   add_action("search","search");
   }

int west() {
   if(("/players/uglymouth/vikings/geiser")->onfire()==2) {
      this_player()->move_player("west#players/uglymouth/vikings/villroad2");
      return 1;
      }
   this_player()->move_player("west#players/uglymouth/vikings/fireroad2");
   return 1;
   }

int search(string str) {
   if(str!="ashes") return 0;
   write("You find nothing special. \n");
   return 1;
   }
