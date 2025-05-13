/* dunes with entrance to Sil's hut */
inherit "room/room";

void reset(int arg)   {
   if(arg) return;

   set_light(1);
   short_desc="You walk through the dunes";
   long_desc="You walk through the dunes. \n"
           + "A path leads you west past some trees and bushes, towards a more open area. \n"
           + "You get slightly irritated as the dunesand works its way into your boots. \n"
           + "At some distance west you see some rabbits running away as they hear you coming. \n"
           + "To the south you can walk to a higher dunehill. \n";
   dest_dir=({"/players/uglymouth/vikings/shore1","east",
              "/players/uglymouth/vikings/dunes_m","south",
              "/players/uglymouth/vikings/open","west", });
   items=({"dunes","Low sandy hills with bad grass and some trees and bushes",
           "grass","It all dried up in the sun, giving the dunes their light brown colour",
           "bushes","Auch! Watch out, they have small thorns",
           "trees","Some small barks. You notice a hut standing in the shadows behind them",
           "hut","A small wooden hut. It looks like someone lives here",
           "rabbits","You scared them. Now they're gone",
           "dunehill","The highest point in the surroundings. Must have a nice view",
           "hill","The highest point in the surroundings. Must have a nice view", });
}

void init() {
   ::init();
   add_action("enter","enter");
   }

int enter(string str) {
   if(str!="hut") return 0;
   write("You leave into the hut. \n");
   this_player()->move_player("into the shadows#players/uglymouth/vikings/silhut");
   return 1;
   }
