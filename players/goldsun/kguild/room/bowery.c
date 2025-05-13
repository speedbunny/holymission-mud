inherit "players/whisky/genesis/std/shop";

#include "../guild.h"

int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "The Carmaalot bowery";
  long_desc = BS(
  "You have entered a dusty room in the tower. The walls are made "+
  "of shiny stone and the floor is made of spruce wooden lathes. "+ 
  "Near the wall there are stairs leading up and down. This is the "+
  "place where Erwin the elf, who is standing behind a desk, trades "+
  "with bows and arrows. There is a sign saying: 'type list' behind "+
  "his desk.");
   set_light(1);
   store = "/players/goldsun/guild/room/bowery_store"; 
   type = "trader";
   keeper = "Erwin";
   maxlist=20;
   
  items = ({"walls","The walls are made of shiny stone",
	    "wall","Near the wall there are stairs leading up and down",
	    "stairs","The stairs leading up and down",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "erwin","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/guild/room/magic","down",
		"/players/goldsun/guild/room/magic_shop","up"});

/*   
    move_object(clone_object("/players/goldsun/guild/obj/fbwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/crwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/mrwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/lwand"),query_store());
 */
}


query_property(arg) 
{
   return arg=="no_fight";
 }

int get_list(string arg)
 {
  if (::get_list(arg))
   {
    write("\nErwin says: Do you want to buy something ?\n");
    return 1;
   }
  return 0;
 }

int sell_fcn(object sob,object player,int i){
 if (sob->id("bow")) check_transfer(sob,player);
  else  write("Erwin says: I don't buy this thing from you.\n");
 return 1;
}
