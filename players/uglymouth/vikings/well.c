/* this is a mystical (holy?) place. to be used later in the quest */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="The river's well";
   long_desc="You climb the rocks to the place where the river comes \n"
           + "aboveground. The well itself is no more than a small hole \n"
           + "between the rocks, the water rushing out with great force. \n"
           + "Except for the stream this is a desolate place. \n";
   dest_dir=({"/players/uglymouth/vikings/river_n","southwest", });
   items=({"rocks","Solid granite rocks",
           "river","From here the river streams southwest fast",
           "well","It spits out its water with great force",
           "hole","A hole in between the rocks, about 1 meter in size", });
   }

void init() {
   ::init();
   add_action("enter","enter");
   }

int enter(string str) {
   if(str!="hole") return 0;
   write("You can't climb in against such a strong current. \n");
   return 1;
   }
