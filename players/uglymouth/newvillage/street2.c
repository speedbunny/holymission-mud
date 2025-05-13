/*
 * Author : Uglymouth
 * Date   : 4-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Behind the gate";
  long_desc="You stand just behind the gate in the village proper.\n"
        + "A guard house stands north, and the centre of the village lies west.\n"
        + "You notice that this village is built around the local church.\n";
  dest_dir = ({ PATH+"guardhouse","north",
        PATH+"street1","east",
        PATH+"street3","west" });
  items=({
        "gate","A gate in the stockade, leading out of the village",
        "stockade","A wooden stockade extends north and south to protect the village", 
        "village","A simple woodsmen's village",
        "house","A wooden house, that accomodates the city guard",
        "centre","Most buildings are built around the church square",
        "buildings","Mostly wooden buildings",
        "church","A nicely crafted wooden church stands in the centre of the squeare",
        "square","A cobblestone square is forms the centre of the village", });
}

void init() {
  ::init();
  add_action("east","east");
}

east() {
   write("You leave the village through the gate. \n"
      + "Clack! The gate closes again behind your back. \n");
   return 0;
   }
