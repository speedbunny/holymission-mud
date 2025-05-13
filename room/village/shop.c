/*
 * Author : Uglymouth
 * Date   : 8-AUG-1993
 */
#include "path.h"
inherit "room/shop";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc = "The 'Tools & Things' shop";
  long_desc = "You are in the 'Tools & Things' shop. It's a small wooden building, with\n" 
         + "a carved wooden counter in the centre. To the walls hang lists with the\n"
         + "items the shop supplies. To see just what that is, type 'list', 'list all',\n"
         + "'list weapons' or 'list armours'. Behind the counter stands a salesman, who\n"
         + "you can order if you want to 'value <item>, 'buy <item>', 'sell <item>' or\n"
         + "'sell all'. He'll be happy to help you.\n";
  dest_dir = ({ PATH+"street9","south" });
  hidden_dir = ({ PATH+"store","north" });
  items = ({ "shop","This is the shop that serves this village",
          "building","Like most buildings, this is made of logs",
          "walls","Walls of sturdy logs",
          "logs","Smoothed logs, cut from the forest right out of the village",
          "lists","Sheets of paper, yellowed by the sunlight",
          "counter","It has nice carvings in it",
          "carvings","Scenes of people working in the woods. It's real elven craftmanship",
          "salesman","A rather young man with a dark brown beard is waiting to help you" });
  set_store_room( PATH+"store" );
  set_store_exit("north");
  property = ({ "no_steal" });
  }
