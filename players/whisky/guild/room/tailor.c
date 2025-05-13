
inherit "/room/room";
#include "../guild.h"

mapping what;

void reset(int flag)
{
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In a small chamber, in the monks guild";
        long_desc = BS(
        "You have entered a small chamber in the monks guild "+
        "next to you you see a small desk where 'Tanja' a red "+
        "robed, pretty nun works busily with her needles and pins "+
        "making clothes for the guildmembers. There is a small sign "+
        "fixed to the northern wall.");

        what = ([
                  "headband":20,
                  "robe":200
                ]);
 
        items = ({
        "sign","There is something written on it",
        "wall","The walls are made of red bricks",
        "walls","The walls are made of red bricks",
        "bottom","The bootom is made of brown earth",
         "stairway","A stairway to the grandmasters workroom",
        "ground","The bootom is made of brown earth",
        "desk","It's an oak wooden desk",
        "tanja","She is sitting behind the desk working busily"
        });

        dest_dir =({
          "/players/whisky/guild/room/c10","east",
             "/players/whisky/guild/room/exitroom","up",
         });
      }
  }


void init()
{
   add_action("do_read","read");
   add_action("do_buy","buy");
   ::init();
}


int do_read(string arg)
{
  string *arr;
  int i, sz;

    if (arg!="sign") return 0; 

    arr = m_indices(what);

    write("Buyable items currently:\n\n");

    for (sz = sizeof(arr),i = 0; i < sz; i ++)
         printf("%-10s for %-8s coins\n",arr[i],to_string(what[arr[i]]));
    write("\nHeadbands and robes are autoload and protect a bit.\n"+ 
          "The colour of the headband shows you the guildstatus\n"+
          "of the monk. The colour of the robe shows the sex of the\n"+
          "guildmember. This clothes are only wearable by monks !\n");
    return 1;
}

int do_buy(string arg)
{
   if (member(what,arg)!=1)
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but I don't sell "+arg+".\n");
       return 0;
   }
   else if (this_player()->query_money() < what[arg])
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but you can't effort the "+arg+".\n");
       return 0;
   } 
   else if (present(arg,this_player()))
   {
       notify_fail("Tanja tells you:\n"+
                   "Sorry, but I sell only one "+arg+" to one member.\n");
       return 0;
    }

  /* here to add new */
  switch(arg)
  {
    case "headband":
          move_object(clone_object("/players/whisky/guild/obj/headband"),
          this_player());
    break;
    case "robe":
          move_object(clone_object("/players/whisky/guild/obj/robe"),
          this_player());
    break;
  }
  write("Tanja gives you the "+arg+".\n");
  this_player()->add_money(-what[arg]);
  return 1;
}
          

    
    

