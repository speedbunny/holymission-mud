


#define MON_TEST ({"t20","t16","t8","t4"})

inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

string lava;
object ob;
int desc;

string my_long()
{
   if (lava)
   {
    return(break_string(
    	"The tunnel opens into a small chamber. "+lava+
      " The walls appear to be solid and immovable.\n",65));
   }
// else case 
  return(break_string(
   	"The tunnel opens into a small chamber. "+
      " The walls appear to be solid and immovable.\n",65));
}

void init()
{
   object ro, guard;
   int i, sz;

   add_action("_enter","enter");

   desc = 1;

   for (sz = sizeof(MON_TEST), i = 0; i < sz; i++)
   {
       catch(call_other("/players/tatsuo/ishikawa/caves/"+MON_TEST[i],"???"));
       ro = find_object("/players/tatsuo/ishikawa/caves/"+MON_TEST[i]);
  
      if (ro && (guard = present("statue",ro)) && living(guard))
          desc = 0;
   } 

  if(!desc)
   lava="In the center of the chamber is a bubbling pool of VERY hot lava.";
  else 
   lava="In the center of the room is a large hole that enters into darkness.";

// now I change the long_desc 

  long_desc = my_long();
  ::init();
}

void reset(int flag)
{
    if (flag != 0) return;

       set_light(1);
       long_desc = my_long();
       short_desc = "Cave of the Serpent";
       dest_dir = ({
        "players/tatsuo/ishikawa/caves/t11","south"  });
       items = ({
         "chamber","@@my_long", 
         "wall","The walls are made of granite",
         "walls","The walls are made of granite",
         "pool","@@pool_look",
         "lava","@@pool_look",
         "hole","@@hole_look" 
                         });
}

string pool_look()
{
	if(!desc)
   {
	    return("A pool of lava bubbling up from the heart of the mountain.\n"+
	           "To enter it would mean certain death");
	}
	return("What pool");
}

string hole_look()
{
	if (desc)
   {
	    return("It leads down, if you were brave you might enter it");
	}
	return("What hole");
}

int _enter(string str)
{
   if(!desc)
   {
	  if (str=="pool" || str=="lava")
     {
	      write("THIS IS REALLY AMAZINGLY HOT!! YOU DIE!\n");
              TP->misc_hit(1000,0,0); /* OUCH, hehehe */
	      return 1;
	  }
	  else if(str=="hole")
    {
	    write("NO WAY there is lava in there\n");
	    return 1;
	 }
    return 1;
  }
  if(str=="pool" || str=="lava")
  {
	    notify_fail("There is no lava.\n");
	    return 1;
	}
  else if(str=="hole")
  {
	    write("You climb down into darkness.\n");
	    MOVE("down the hole into darkness#players/tatsuo/ishikawa/caves/t21.c");
	    return 1;
	}
  return 0;
}
