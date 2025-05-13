/* An old viking burrow. Contains hints. */
inherit "room/room";
object obj;
int ghost_killed;

void reset(int arg) {

   if(!present("earthen jug")) {
      obj=clone_object("/players/uglymouth/vikings/items/jug");
      transfer(obj,this_object());
      }
/*
   if(!present("leather scroll")) {
      obj=clone_object("/players/uglymouth/vikings/items/scroll");
      transfer(obj,this_object());
      }
*/
   if(!present("viking sword")) {
      obj=clone_object("/players/uglymouth/vikings/items/viksword");
      transfer(obj,this_object());
      }
   ghost_killed=0;

   if(arg) return;

   set_light(0);
   short_desc="A viking's burrow";
   long_desc="This is a small cave in the sand. In the middle you can see the remnants of "
           + "a small boat. A skeleton and some items in the boat indicate that this "
           + "must be an old burrow of the vikings. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_w.c","out", });
   items=({"sand","The sand is quite hard here",
           "boat","The boat has decayed for the best part over the years",
           "skeleton","A human skeleton. It's dead and will be so forever",
           "burrow","The burial mound for the deceased", });
   }

void init() {
   ::init();
   add_action("grab_it","get");
   add_action("grab_it","take");
   }

int grab_it(string str) {
   if(str!="sword" && str!="viking sword") return 0;
   if(present("ghost of viking")) {
      write("The ghost won't let you take it. \n");
      return 1;
      }
   if(ghost_killed!=1) {
      write("As you touch the scroll, a moaning sound rises from the earth. \n"
          + "A vaguely white shade appears. \n");
      transfer(clone_object("/players/uglymouth/vikings/monsters/shade"),this_object());
      ghost_killed=1;
      return 1;
      }
   return 0;
   }
