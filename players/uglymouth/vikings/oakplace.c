/* The location of the holy oak */
inherit "room/room";
int sac;

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   property = "no_teleport";
   short_desc="At the holy oak";
   long_desc="You stand at an open place in the jungle. A thin mist hangs "
           + "in the air and there is absolute silence. In the centre of this "
           + "place stands a large oak. It strongly radiates some mystical "
           + "power. This is obviously a holy place. \n";
   dest_dir=({"/players/uglymouth/vikings/infjungle1","jungle", });
   items=({"mist","Some thin white mist",
           "oak","It must be ages old, almost from the beginning of time", });
   smell="Although in th middle of the jungle the air is quite fresh here. \n";
   }

void init() {
   ::init();
   add_action("sleep","sleep");
   add_action("sacrifice","sacrifice");
   }

int sleep() {
   write("You close your eyes and try to sleep. \n"
       + "When you wake up you find yourself still at the foot the holy oak. \n");
   if(!(present("clan tunic",this_player()) && present ("viking helm",this_player()) &&
      (present("viking axe",this_player()) || present("viking sword",this_player())))) return 1;
   if(sac==0) {
      write("A voice inside you tells you that gods never do a thing for those \n"
          + "who don't show the proper respect by giving a sacrifice. \n");
      return 1;
      }
   ("/players/uglymouth/vikings/oakplace2")->set_slept();
   this_player()->move_player("someplace, dissolving into thin air#players/uglymouth/vikings/oakplace2");
   sac=0;
   return 1;
   }

int sacrifice(string str) {
object meat;
   if(str!="meat" && str!="rabbitmeat") {
      write("Somehow this doesn't feel to be the right sacrifice to bring here. \n");
      return 1;
      }
   if(!present("rabbitmeat",this_player())) {
      write("You don't have any rabbit meat to sacrifice to the gods. \n");
      return 1;
      }
   write("You sacrifice some rabbit meat to the viking gods. \n");
   meat=present("rabbitmeat",this_player());
   destruct(meat);
   sac=1;
   return 1;
   }
