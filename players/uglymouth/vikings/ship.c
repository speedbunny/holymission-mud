/* the virtual 'hull' of the ship */
#define PATH "players/uglymouth/vikings/"

inherit "obj/thing";
int loc;       /* loc=0 at bay, loc=1 at vikinglands */

void move_back() {
string *camprms;
int i;
   tell_room(environment(this_object()),"The drakkar leaves for new adventures! \n");
   transfer(this_object(),"/players/uglymouth/vikings/shipsea");
   tell_room(environment(this_object()),"A drakkar arrives. \n");
   camprms=allocate(13);
   camprms=({
      PATH+"campbeach",PATH+"rowboat",PATH+"camp2",PATH+"camp1",
      PATH+"camp3",PATH+"tent1",PATH+"tent2",PATH+"tent3",
      PATH+"bay_n",PATH+"bay_se",PATH+"harbour",PATH+"highdune",
      PATH+"rock",
      });
   for(i=0;i<sizeof(camprms);i++) {
      camprms[i]->vikings_arrive();
      }
   loc=0;
   ("/players/uglymouth/vikings/geiser")->burn_village();
   return 0;
   }

void reset(int arg) {

   if(loc==1) {
      move_back();
      }

   ::reset(arg);
   if(!arg) {

   set_name("longship");
   set_alias("ship");
   set_short("The longship of the vikings");
   set_long("The longship of the vikings. It's quite a large ship, suited for both \n"
          + "sailing and rowing. Its dragonlike shape makes it look very impressive. \n"
           + "A rope ladder hangs down from its side. \n"
           + "Many of the shields that hang on the sides are painted with \n"
           + "red and white patterns. \n");
   set_can_get(0);
   transfer(this_object(),"/players/uglymouth/vikings/shipsea");
   loc=0;
   }
}

void init() {
   ::init();
   add_action("climb","climb");
   }

int climb(string str) {
   if(str!="ladder" && str!="rope ladder") return 0;
   if(loc==0) {
      write("The ladder hangs too high to reach from the water. \n");
      return 1;
      }
   write("You climb up the rope ladder to the deck of the ship. \n");
   this_player()->move_player("up on the rope ladder#players/uglymouth/vikings/shipdeck2");
   return 1;
   }

status query_location() {
   return loc;
   }

void sail_away() {
int i;
string *camprms;
   /* remove the camp */
   camprms=allocate(17);
   camprms=({
      PATH+"tent1",PATH+"tent2",PATH+"tent3",PATH+"camp3",
      PATH+"camp1",PATH+"camp2",PATH+"campbeach",PATH+"rowboat",
      PATH+"bay_n",PATH+"bay_se",PATH+"harbour",PATH+"highdune",
      PATH+"rock",PATH+"shipdeck1",PATH+"shipdeck2",
      PATH+"shipdeck3",PATH+"shipdeck4",
      });
   for(i=0;i<sizeof(camprms);i++) {
      camprms[i]->vikings_leave();
      }
   tell_room(environment(this_object()),"The drakkar leaves for new adventures! \n");
   transfer(this_object(),"/players/uglymouth/vikings/vikpier");
   loc=1;
   return 0;
   }
