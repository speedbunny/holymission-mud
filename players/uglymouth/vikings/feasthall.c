/* the place to finish the quest: a reason for a feast */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The great hall of Viking Lord Hagar the Conqueror";
   long_desc="You step into a large hall. Tables are placed in a square and around them are many "
           + "viking chieftains and their clans making a great feast. At the far end stands a high "
           + "chair. On it sits a man of legend: Viking Lord Hagar the Conqueror. "
           + "On the walls hang all the shields of the clans that live under Hagar's reign. "
           + "The hall is very well lit by many torches. Servants and slaves run around with "
           + "food and drinks. \n";
   dest_dir=({"/players/uglymouth/vikings/vikfield","north", });
   items=({"hall","The great hall of the dreaded Viking Lord Hagar the Conqueror",
           "tables","long tables for many men, filled with all kinds of food and drinks",
           "vikings","Brute but brave fighting men, even when drunk",
           "chieftains","The chieftains are sitting closest to Viking Lord Hagar",
           "clans","At least six clans are gathered here for the feast",
           "chair","A very crude version of a throne",
           "shields","They are like the shields on the side of the ship, but in diffrent colours",
           "torches","They are fixed to the wall. Burned ones are immediately replaced by a servant",
           "servants","Mostly young girls from Hagar's clan, running skillfully around with many dishes",
           "slaves","Mostly people that were captured on one of their raids",
           "food","Roasted porc meat and beef, thick soup and bread",
           "drinks","Mugs filled to the rim with very good mead. Take one",
           });

   property=({ "no_fight" });

   transfer(clone_object("/players/uglymouth/vikings/questdir/hagar"),this_object());
   }

void init() {
   ::init();
   add_action("get_it","get");
   add_action("get_it","take");
   }

int get_it(string str) {
object mead,ob;
   if(str!="mead" && str!="mug of mead" && str!="mug") return 0;
   if(ob = present("the village medallion of symria") && ob->query_parts_done()==2) {
      write("A viking says: You are not a Viking, so hands off of our mead! \n");
      return 1;
      }
   if(present("supermead",this_player())) {
      write("You already have a mug of mead. Don't be greedy. \n");
      return 1;
      }
   mead=clone_object("/players/uglymouth/vikings/items/supermead");
   write("You take a mug of mead of the table. \n");
   transfer(mead,this_player());
   return 1;
   }
