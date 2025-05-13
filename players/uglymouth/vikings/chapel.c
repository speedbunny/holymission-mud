/* the ruins of a chapel, includes a hint */
inherit "room/room";
int body_found;

void reset(int arg) {

   body_found=0;
   if(arg) return;

   set_light(1);
   short_desc="The ruins of the village chapel";
   long_desc="You stand among the scrap that once was a sacred place. "
           + "It has been thoroughly ransacked, leaving no beam upright. "
           + "In the northwest corner you see a hole formed by some wood that "
           + "has not been burned totally. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad2","south", });
   items=({"beam","Everything is broken and burned",
           "corner","A small part of the corner has been spared by the fire",
           "wood","Although not burned, it's broken. It seems to cover something",
           "hole","A dark hole between broken wood", });
   }

void init() {
   ::init();
   add_action("south","south");
   add_action("search","search");
   }

int south() {
   if(("/players/uglymouth/vikings/geiser")->onfire()==1) {
      this_player()->move_player("south#players/uglymouth/vikings/fireroad2");
      return 1;
      }
   this_player()->move_player("south#players/uglymouth/vikings/villroad2");
   return 1;
   }

int search(string str) {
object body;
   if(str!="corner" && str!="hole") return 0;
   if(body_found==1) {
      write("You feel inside the hole, but find nothing. \n");
      return 1;
      }
   write("You feel inside the hole and drag out the corpse of a man. \n");
   body=clone_object("/players/uglymouth/vikings/items/body");
   transfer(body,this_object());
   body_found=1;
   return 1;
   }
