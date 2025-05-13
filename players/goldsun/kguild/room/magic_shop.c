inherit "players/whisky/genesis/std/shop";

#include "../guild.h"

int i;
void reset(int arg) 
{
  ::reset(arg);
  short_desc = "In the magic shop";
  long_desc = BS(
  "You have entered a dusty room in the tower. The walls are made "+
  "of shiny stone and the floor is made of spruce wooden lathes. "+ 
  "Near the wall there are stairs leading up and down. This is the "+
  "place where Conjurer Maugis, who is standing behind a desk, trades "+
  "with magic things. There is a sign saying: 'type list' behind "+
  "his desk.");
   set_light(1);
   store = "/players/goldsun/guild/room/magic_store"; 
   type = "trader";
   keeper = "Maugis";
   maxlist=20;
   
  items = ({"walls","The walls are made of shiny stone",
	    "wall","Near the wall there are stairs leading up and down",
	    "stairs","The stairs leading up and down",
            "desk","It's a wooden desk",
            "bottom","It's made of spruce wooden lathes",
            "lathes","They are spruce wooden",
            "maugis","He is standing behind the desk smiling friendly at you",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/goldsun/guild/room/bowery","down",
		"/players/goldsun/workroom","up"});

   
    move_object(clone_object("/players/whisky/obj/pois_potion"),query_store());
    move_object(clone_object("/players/whisky/obj/pois_scroll"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/fbwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/crwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/mrwand"),query_store());
    move_object(clone_object("/players/goldsun/guild/obj/lwand"),query_store());
}

init(){
 ::init();
add_action("d_sell","sell");
add_action("do_up","up");
 }

do_up(){
object golds;

 if (TP->query_real_name()=="goldsun")
  {
     write("Maugis bows to you.\n");
     say("Maugis bows to Master Goldsun.\n");
     return ::move("up");
  }

 if (find_player("goldsun")  )
  {
    golds=find_player("goldsun");
    if (!interactive(golds))
      {
       tell_room(TO, "Maugis bars you the way: Master Goldsun has technical problems.\n");
       return 1;
      }

    if ((TP->query_level() > 24))
     {
       tell_object(golds,"Maugis tells you: "+OPN+" enters your workroom.\n");
       return ::move("up");
     }
    tell_room(TO, "Maugis bars you the way: Master Goldsun is busy for you. "
   			+"Don't disturb him.\n");
    tell_object(golds, "Maugis tells you: "+OPN+" tries to enter your workroom.\n");
    return 1;
  }
 tell_room(TO, "Maugis bars you the way: Master Goldsun isn't here now.\n");
 return 1;
}

query_property(arg) 
{
   return arg=="no_fight";
 }

int get_list(string arg)
 {
  if (::get_list(arg))
   {
    write("\nMaugis says: Do you want to buy something ?\n");
    return 1;
   }
  return 0;
 }

int d_sell(){
 write("Maugis says: I don't buy anything from you.\n");
 return 1;
}
