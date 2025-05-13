/* the northern road through the village after the fire is put out */
inherit "room/room";

void reset(int arg) {
   if(arg) return 0;

   set_light(1);
   short_desc="You walk through the ravages on the northern road of the village";
   long_desc="You walk through the ravages on the road. \n"
           + "To the north the desacreted chapel offers a sad view. The building to \n"
           + "the west has collapsed under the fire, the building on the east however \n"
           + "is still standing. The muddy substance from the square slowly flows in. \n";
   dest_dir=({"/players/uglymouth/vikings/chapel","north",
              "/players/uglymouth/vikings/house7","east",
              "/players/uglymouth/vikings/villsquare","south",
              "/players/uglymouth/vikings/house6","west", });
   items=({"road","The heat has made cracks in the road at many places",
           "chapel","It has thoroughly been desecrated, plundered and set on fire",
           "building","The eastern or the western building?",
           "eastern building","It seems to have been the local shipwright's workplace",
           "western building","This is no mare than a dark ruin",
           "substance","A disgusting mixture of water, ashes and burned materials",
           "materials","Do you really want to analyse this sickening soup?", });
   smell="The fresh air blowing in from the sea only stresses the disaster that happened here. \n";
   }

void init() {
   ::init();
   add_action("west","west");
   }

int west() {
   write("The ashes are still glowing too hot for you to go in safely. \n");
   return 1;
   }
