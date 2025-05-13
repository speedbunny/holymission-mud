/* the attic from which you can get into the vikings' camp */
inherit "room/room";
int wopen;

void reset(int arg) {
   wopen=0;
   if(arg) return;

   set_light(0);
   short_desc="The burned out attic of the warehouse";
   long_desc="You are in the attic of the warehouse. \n"
           + "The solid walls kept this place alive, but everything that "
           + "once was stored here has been utterly destroyed by the fire. "
           + "In the south wall is a window, still intact. \n";
   dest_dir=({"/players/uglymouth/vikings/house3","down", });
   items=({"walls","They don't look so solid anymore",
           "window","It's covered with a thick layer of ashes",
           "ashes","Fine, grey/black powder suffocating the air", });
   smell="You have to cover your mouth and nose from the ashes, so you don't smell anything. \n";
   }

void init() {
   ::init();
   add_action("clean","clean");
   add_action("open","open");
   add_action("shatter","shatter");
   add_action("shatter","break");
   add_action("climb","climb");
   add_action("climb","enter");
   add_action("look","look");
   }

int clean(string str) {
   if(str!="window") return 0;
   write("As you wipe the ashes off the window, you notice some tents and \n"
       + "campfires, south of the town. \n");
   say("Daylight enters the room as "+this_player()->query_name()+" cleans the window. \n",this_player());
   set_light(1);
   return 1;
   }

int open(string str) {
   if(str!="window") return 0;
   write("It's stuck! \n");
   return 1;
   }

int shatter(string str) {
   if(str!="window") return 0;
   write("With a loud CLANG you shatter the window. Fresh air flows in. \n");
   say(this_player()->query_name()+" breaks the window to get some fresh air. \n",this_player());
   set_light(1);
   wopen=1;
   return 1;
   }

int climb(string str) {
   if(str!="window") return 0;
   if(wopen!=1) {
      write("You hit your head against the closed window. \n");
      return 1;
      }
   write("You climb out of the window. \n");
   this_player()->move_player("through the window#players/uglymouth/vikings/camp1");
   return 1;
   }

int look(string str) {
   if(!str || (str && str!="at window")) return 0;
   if(wopen==0) return 0;
   write("The window is broken, letting in some fresh air. \n");
   return 1;
   }
