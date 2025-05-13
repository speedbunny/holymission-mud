
/* Gorlin, 4.4.1996 */

inherit "room/room";

void reset (int arg)
{
   clone_list=({
      1, 1, "gargoyle", "/players/gorlin/castles/syrah/gargoyle", 0
      });

   ::reset (arg);
   if (arg) return;

   set_light(1);
   short_desc="A small valley";
   long_desc="You have entered a small, sheltered valley. "+
             "In front of you you can see a slender grey "+
             "tower rising up into the sky. You can see a "+
             "doorway leading in.\n";
   dest_dir=({
      "out","south",
      "/players/gorlin/castles/syrah/tower1","enter"
      });

   items=({
      "tower","A slender, tall tower. A doorway leads inside", 
      "pedestal","A small pedestal made of grey stone", 
      });
   smell="The mountain air smells very fresh.";
}

void init()
{
   ::init();
   add_action("go_enter","enter");
}

int go_enter()
{
   if (!present("gargoyle")) return 0;
   if (this_player()->query_real_name() == "syrah" ) return 0;
   write ("The statue growls: I cannot let you pass, \n"+
          "and bars your way.\n");
   return 1;
}

