/* just for the lookout, to see where the ship lies */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The crow's nest of the drakkar";
   long_desc="This is the crow's nest of the drakkar. It's a small wooden \n"
           + "platform, used to look out over the sea. Look at the view. \n";
   dest_dir=({
      "/players/uglymouth/vikings/shipdeck2","down",
      });
   items=({
      "drakkar","The vikings' ship",
      "platform","There's just enough room for you to stand here",
      "sea","The big blue sea",
      });
   }

void init() {
   ::init();
   add_action("look","look");
   }

int look(string str) {
object ship;
   if(str!="at view") return 0;
   ship=find_object("/players/uglymouth/vikings/ship");
   environment(ship)->long();
   return 1;
   }
