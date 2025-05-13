/*
 * Author : Uglymouth
 * Date   : 8-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc = "The north - south part of Main Street";
   long_desc = "Main Street takes a north - south course here. To the north the road\n"
         + "curves east. To the south it heads west again. To the west from you can\n"
         + "enter Candy's Confectioner's Shop. East rises the church wall.\n";
   dest_dir = ({ PATH+"street5","north",
         PATH+"street7","south", 
         "/players/uglymouth/cakeshop/cakeshop","west" });
   items = ({ "main street","The major road through the village",
         "road","Main Street is a well maintained dirt raod", 
         "wall","The wooden wall of the church holds beautiful windows",
         "windows","You should look at them from inside the church to see them well" });

  replace_program("room/room");
   }

