
inherit "/room/room";
#include "defs.h"

int found;

void reset(int flag)
{
    ::reset(flag);
    found = 0;
    if (flag == 0)
    {
      dest_dir =
      ({
        PATH+"kitiaras_innerhall","east",
      });
   
       short_desc = "A tidy sleepingroom";
       long_desc = BS(
       "A tidy sleepingroom, it has a feminine look and a large pink bed.");
       items = 
       ({
          "bed","The bed is covered with clean silken sheets,\n"+
                "it smells of roses (maybe you should search the bed)",
          "bottom","The bootom is made of wood",
          "ceiling","The ceiling is made of red bricks",
          "walls","The walls are made of red bricks",
       });
    }
}

void init()
{
   ::init();
    add_action("search_bed","search"); 
}

int search_bed(string arg) 
{
    if (arg!="bed")
        return 0;

    if (found == 0)  
    {
       found = 1;
       move_object(clone_object("/players/whisky/obj/heal_potion"),
                   this_object());
       write("You found a small vial.\n");
       return 1;
    }
    else 
   {
       write("You found nothing.\n");
       return 1;
   }
   return 0;
}
