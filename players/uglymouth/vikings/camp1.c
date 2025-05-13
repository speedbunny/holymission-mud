/* the camp of the dreaded vikings */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The vikings' camp";
   long_desc="You've arrived at the centre of the viking's camp. A large campfire \n"
           + "is burning here. East some vikings are gambling with dice. West stand bushes. \n"
           + "South of here some tents are built up. North of you a building, blackened \n"
           + "by a recent fire, is still standing. \n";
   dest_dir=({
      "/players/uglymouth/vikings/camp2","east",
      "/players/uglymouth/vikings/camp3","south",
      });
   items=({"vikings","Tough fighters wearing horned helmets who love drinking, gambling and fighting",
           "tents","There are two small dirty white tents and one big red and white striped tent",
           "fire","The vikings are also capable of making decent campfires",
           "bushes","Just some undergrowth, blackened by the fire",
           "building","The burned warehouse of the village. You can enter it through a window", });
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("enter","enter");
   add_action("enter","climb");
   add_action("search","search");
   }

int enter(string str) {
   if(str!="window" && str!="building" && str!="warehouse") return 0;
   write("You climb through the window into the building.\n");
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      this_player()->move_player("into the building#players/uglymouth/vikings/fireattic");
      return 1;
      }
   this_player()->move_player("into the building#players/uglymouth/vikings/house3a");
   return 1;
   }

int search(string str) {
   if(str!="bushes") return 0;
   write("You've found a passage into the woods. \n");
   this_player()->move_player("suddenly#players/uglymouth/vikings/jungle_s");
   return 1;
   }

void vikings_leave() {
object vik,*inv;
int i;
   tell_room(this_object(),"The vikings pack their things and leave for their ship. \n");
   long_desc="You've arrived at a bare stroke of sand. It continues to the east \n"
           + "and to the south. To the north a building, blackened by a recent fire, is \n"
           + "still standing. The ashes of a big campfire are scattered over the earth. \n";
   items=({
      "sand","It's ordinary earth",
      "building","It's a burned out warehouse. You can climb in through a window",
      "ashes","The ashes twirl up into your nose. You start sneezing",
      });
   property=0;
   vik=present("viking");
   while(vik) {
      inv=all_inventory(vik);
      for(i=0;i<sizeof(inv);i++) {
         destruct(inv[i]);
         }
      destruct(vik);
      vik=present("viking");
      }
   }

void vikings_arrive() {
   tell_room(this_object(),"The vikings arrive, having trashed the village, and make camp here. \n");
   long_desc="You've arrived at the centre of the viking's camp. A large campfire \n"
           + "is burning here. To the west you can see some vikings gambling with dice. \n"
           + "South of here some tents are built up. North of you a building, blackened \n"
           + "by a recent fire, is still standing. \n";
   items=({"vikings","Tough fighters wearing horned helmets who love drinking, gambling and fighting",
           "tents","There are to small dirty white tents and one big red and white striped tent",
           "fire","The vikings are also capable of making decent campfires",
           "building","The burned warehouse of the village. You can enter it through a window", });
   property=({ "has_fire" });
   }
