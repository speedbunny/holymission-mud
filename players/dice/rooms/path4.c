
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village entry";
   long_desc =
     "You are entering the village.\n"+
     "The woods are entirely gone here, the first houses appear\n"+
      "though you can not enter them yet.\n"+
     "The smell of freshly baked bread is VERY strong, \n"+
     "and it comes from a small house north of you.\n";

   dest_dir = ({
      "players/dice/rooms/path3","west",
      "players/dice/rooms/vill1","east",
      "players/dice/rooms/bak","north"
       });

   items =({
            "small house","A small coalminers house",
            "house","A small coalminers house",
            "houses","Small coalminers houses",

            });


   smell = "The smell of fresh bread makes you stomach grumble \n"+
           "Now you really feel hungry.\n";
}
