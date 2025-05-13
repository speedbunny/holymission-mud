
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Path";
   long_desc =
     "You are still walking on a path leading to a village.\n"+
     "The woods get lighter here and the roofs of the village\n"+
     "seem to be coming closer, more smoke comes from the chimneys.\n"+
     "The smell of freshly baked bread tortures your nose making you hungry.\n";

   dest_dir = ({
      "players/dice/rooms/e_city","west",
      "players/dice/rooms/path3","east"
      });

   items =({
           "path","A path leading east-west",
           "roofs","The roofs of the houses",
           "woods","The woods surrounding you",
           "wood","The wood surrounding you",
           "chimney","It's on top of the house",
           "chimneys","They are on the top of the houses",
           "roof","The roof of the house",
           "smoke","Smoke coming from the chimneys"
           });


   smell = "You smell the fresh bread coming from the houses. \n"+
           "This smell makes your stomach grumble.\n";
}
