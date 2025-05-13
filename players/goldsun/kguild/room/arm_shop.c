inherit "players/whisky/genesis/std/shop";

#include "../guild.h"

int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the armoury";
  long_desc = BS(
  "You have entered a dusty room in the tower. The walls are made "+
  "of shiny stone and the floor is made of spruce wooden lathes. "+ 
  "Near the wall there are stairs leading up and down. This is the "+
  "place where Reginus the armourer, who is standing behind a desk, trades "+
  "with all kinds of armours. There is a sign saying: 'type list' behind "+
  "his desk.");
   set_light(1);
   store = "/players/goldsun/guild/room/arm_store";
   type = "armourer";
   keeper = "Reginus";
   maxlist=40;
   
  items = ({"walls","The walls are made of shiny stone",
	    "wall","Near the wall there are stairs leading up and down",
	    "stairs","The stairs leads up and down",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
	    "armours","There are so many armours, that you better should"
			+" look at sign",
	    "armour","There are so many armours, that you better should"
			+" look at sign",
            "reginus","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/guild/room/other_shop","down",
	        "/players/goldsun/guild/room/weap_shop","up" });

   
   move_object(clone_object("/players/goldsun/guild/obj/wooden_shield"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/lather_gloves"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/lather_boots"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/helmet"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/chainmail"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/lather_jacket"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/r_cloak"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/w_cloak"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/p_ring"),query_store());
   move_object(clone_object("/players/goldsun/guild/obj/bone_amulet"),query_store());

  if (!present("trashcan",this_object()))
     move_object(
          clone_object("players/whisky/shops/trashcan"),this_object());
}

query_property(arg) 
{
   return arg=="no_fight";
 }

int get_list(string arg)
 {
  if (::get_list(arg))
   {
    write("\nReginus said: If there is nothing in my list, You can \n"
         +"wait for a moment. New armours can being brought.\n");
    return 1;
   }
  return 0;
 }

