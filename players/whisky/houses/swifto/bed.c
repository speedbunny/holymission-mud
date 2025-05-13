
/* bed */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In the Swifto's bed";
         long_desc = BS(
         "You are in a big confortable bed. It's filled with "+
         "soft pillows. The bed is covered with white linen. "+
         "Above you is a big mirror.");
        
        items =
        ({
         "pillows","Soft red pillows",
         "linen","Soft white, clean linen",
         "mirror","@@query_mirror",
        });

         dest_dir =
         ({
           PATH+"bedroom","out",
         }); 
     }
   }

void init()
{
   ::init();
   write("Ahhh you stretch yourself out in that confortable bed.\n");
}

string query_mirror()
{
  string ret;
  object *inv;
  int sz, i;

  ret = "";
  inv = all_inventory();

   for (sz = sizeof(inv), i = 0; i < sz; i++)
   {
       if (inv[i]->query_name())
           ret = ret + inv[i]->query_name()+"\n";
   }
  return ret; 
}
