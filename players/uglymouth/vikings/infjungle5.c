/* well, infinite... not really */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   property = "no_teleport";
   short_desc="Somewhere in the jungle";
   long_desc="You are somewhere in this big, dense jungle, but you don't know "
           + "where exactly. The trees all around you look all the same and so "
           + "do the plants. You get a creepy feeling about this. \n";
   dest_dir=({"/players/uglymouth/vikings/infjungle1","forward",
              "/players/uglymouth/vikings/infjungle2","backward",
              "/players/uglymouth/vikings/infjungle3","left",
              "/players/uglymouth/vikings/infjungle4","right", });
   items=({"trees","Many tall, strange, tropical trees grow here",
           "plants","Many tropical plants in all colours grow here", });
   }


void init() {
   ::init();
   add_action("walk","forward");
   add_action("walk","backward");
   add_action("walk","left");
   add_action("walk","right");
   }

int walk() {
int i;
string *rooms;
object medal;
   medal=present("the village medallion of symria",this_player());
   if(medal && medal->query_worn()) {
      this_player()->move_player("into the jungle#players/uglymouth/vikings/infjungle6");
      return 1;
      }
   rooms=allocate(4);
   i=random(8);
   if(i==0) {
      i=random(4);
      rooms=({"w","n","e","s"});
      this_player()->move_player("into the jungle#players/uglymouth/vikings/jungle_"+rooms[i]);
      return 1;
      }
   if(i==7) {
      this_player()->move_player("into the jungle#players/uglymouth/vikings/snakeroom");
      return 1;
      }
   this_player()->move_player("into the jungle#players/uglymouth/vikings/infjungle"+i);
   return 1;
   }
