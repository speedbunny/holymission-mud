/* the northern road through the burning village */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="You walk amidst the flames on the northern road through the village";
   long_desc="You walk among the flames that fill this part of the road. \n"
           + "North of you lies the desecrated chapel of the village, almost burned \n"
           + "to the ground. The buildings to the east and west are also for the \n"
           + "greater part destroyed by the fire. The village square is south of you. \n";
   dest_dir=({"/players/uglymouth/vikings/chapel","north",
              "/players/uglymouth/vikings/house7","east",
              "/players/uglymouth/vikings/firesquare","south",
              "/players/uglymouth/vikings/house6","west", });
   items=({"road","The eathen road is cracked everywhere because of the heat and covered with ashes",
           "flames","The flames cause a heavy smoke that makes it hard to breathe",
           "fire","It's all around you and makes you wonder why you're still alive",
           "chapel","The vikings plundered it, smashed it and set it on fire. It's a sad sight",
           "buildings","The eastern or the western building?",
           "eastern building","By the look of the burned items this must have been the shipwrights workplace",
           "items","The ashes of curved planks, sailcloth, ropes, and more unrecognizable things",
           "western building","The fire has destroyed it so much that you can't make out what it used to be",
           "square","A wider space that might be just a few degrees cooler than this place", });
   smell="The smoke burns in your lungs as you foolishly try to find out what is smells like. \n";
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("house","east");
   add_action("house","west");
   add_action("south","south");
   }

int house() {
   write("The building is not much more than a thick layer of redhot burning coals. \n"
       + "It would be a shame to die trying to walk on fire. \n");
   say(this_player()->query_name()+"'s hair burns away, getting to close to the burning buildings.\n",this_player());
   return 1;
   }

int south() {
   write("Crossing your arms before your head you run through a cloud of flames. \n");
   this_player()->hit_player(random(5)+1);
   this_player()->move_player("through the fire south#players/uglymouth/vikings/firesquare");
   return 1;
   }
