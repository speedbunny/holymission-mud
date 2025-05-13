/* one of the gods' mugs */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="In a mug of bad ale";
   long_desc="You're swimming in a huge mug filled with bad ale. \n"
           + "High above you you see the grinning face of Loki. \n";
   items=({"mug","An oakwooden mug of about 2 meters diameter",
           "face","Loki's grinning face takes away most of the light",
           "ale","Strong ale, brewed for the gods' stomachs. It has gone bad", });
   property= ({ "no_teleport" });
   }

void init() {
   ::init();
   add_action("swim","swim");
   add_action("dive","dive");
   add_action("break_mug","break");
   add_action("drink","drink");
   }

int swim() {
   write("Well, there isn't much other choice, is there? \n");
   return 1;
   }

dive() {
   write("You dive into the ale. \n");
   if(random(10)<3) {
      write("along the wall you find a piece of wood that has almost rotten through. \n"
          + "Maybe you can break it, creating a way out. \n");
      return 1;
      }
   write("The mug seems to be made of solid oakwood. \n");
   return 1;
   }

int break_mug(string str) {
   if(str!="mug" && str!="wood") return 0;
   write("You break the rotten wood. immediately the ale flows out, \n"
       + "taking you in its current. You hear Loki groan displeasedly. \n");
   this_player()->move_player("X#players/uglymouth/vikings/walhalla");
   ("/players/uglymouth/vikings/walhalla")->set_busy(0);
   return 1;
   }

int drink(string str) {
   if(str!="ale") return 0;
   write("The ale has gone bad. Bweehh!! \n");
   return 1;
   }
