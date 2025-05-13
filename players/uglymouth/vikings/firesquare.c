/* the main square of the village on fire */
inherit "room/room";

void reset(int arg) {
object man;

   if(!(man=present("man")) || !living(man)) {
      transfer(clone_object("/players/uglymouth/vikings/monsters/burned"),this_object()); }

   if(arg) return;

   set_light(1);
   short_desc="The burning quare of the village";
   long_desc="You're at the village square. \n"
           + "Because this is a quite large space the flames don't come so close \n"
           + "at you. Still you are surrounded by fire. In the middle of the square \n"
           + "stands the well from which the villagers used to take their water. \n"
           + "From here the road goes north, east and west, but all the ways are full \n"
           + "of fire. South of you is a large building, still standing but burning as hell. \n";
   dest_dir=({"/players/uglymouth/vikings/fireroad2","north",
              "/players/uglymouth/vikings/fireroad3","east",
              "/players/uglymouth/vikings/firehouse","south",
              "/players/uglymouth/vikings/fireroad1","west", });
   items=({"square","All over the square are the burning remains of fishstalls and sailormaterials",
           "fire","The fire is all around you, making all exits dangerous",
           "flames","Bright yellow and blue flames eat away everything that can burn",
           "road","In every direction the road is littered with burning obstacles",
           "building","The highest building here, probably some kind of storage, but not much will be left",
           "well","Its rope and bucket have burned away. It looks very deep...eep...ep...p..", });
   property=({ "has_fire" });
   smell="The air smells of burned wood, burned fish and melted tar. You almost throw up. \n";
   }

void init() {
   ::init();
   add_action("north","north");
   add_action("east","east");
   add_action("south","south");
   add_action("west","west");
   }

int north() {
   write("The flames burn your skin at several places as you move through the fire. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("through the flames north#players/uglymouth/vikings/fireroad2");
   return 1;
   }

int east() {
   write("Sweat breaks out as you pass through the flames. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("through the flames east#players/uglymouth/vikings/fireroad3");
   return 1;
   }

int west() {
   write("You make a daring leap through the flames of a burning wagon that blocks the road. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("through the flames west#players/uglymouth/vikings/fireroad1");
   return 1;
   }

int south() {
   write("A sudden change of wind almost blows the flames into your eyes as you go in. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("into the burning building!!#players/uglymouth/vikings/firehouse");
   return 1;
   }
