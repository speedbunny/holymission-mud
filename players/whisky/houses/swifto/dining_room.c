
/* entrance */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         set_light(1);
         short_desc = "In the dining room of Swifto's house";
         long_desc = BS(
         "You have entered a medium sized room. In the middle of the "+
         "room is a medium-sized table with two candles in holders on "+
         "each side. The northern wall of the room is made of glass "+
         "where you can have a look at the pictureque lake. There are "+
         "four candle holders fixed on each side of the wall and in "+
         "the middle of the table is a bell and a vase with a single rose. "+
         "in it. Next to the table is a soft sofa with pillow on each side. "); 

        items =
        ({
         "walls","The walls are painted in white",
         "northern wall",
         "You can see the beautiful lake through the glass",
         "floor","The floor is hardwood",
         "ceiling","The ceiling is made of spruce wooden lathes",
         "candles","The candles are to light the room",
         "holders","Te holders are golden",
         "bell","A little silver bell, you can ring it",
         "chadelier","The large golden chadelier lits the room",
         "table","It's a pretty, big wooden table",
         "vase","There is a single red rose in the vase",
         "pillows","Soft blue pillows",
         "pillow","Soft blue pillows",
         "sofa","A soft white sofa", 
        });

         dest_dir =
         ({
           PATH+"entrance","up",
         }); 
     }
   }

void init()
{
     ::init();
     add_action("do_ring","ring");
}

int do_ring(string arg)
{
    if (arg!="bell") return 0;
    tell_room(this_object(),
    "A handsome servant arrives and bows to you.\n");
    call_out("bring_dinner",1);
    return 1;
}

int bring_dinner()
{
    object ch;
    object cv;
    int i;
    
    tell_room(this_object(),
    "The handsome servant puts champagne and caviar on the table.\n");

  for(i =  0; i < 2; i++)
  {
    cv = clone_object("/obj/food");
    cv->set_name("some caviar");
    cv->set_alias("caviar");
    cv->set_eating_mess(" eats some caviar");
    cv->set_long("Tasty caviar.\n");
    cv->set_amount(1);
    cv->set_value(1);
    move_object(cv,this_object());

    ch = clone_object("/obj/alco_drink");
    ch->set_name("champagne");
    ch->set_drinking_mess(" drinks some champagne");
    ch->set_alias("bottle");
    ch->set_long("A bottle of best, french champagne.\n");
    ch->set_strength(1);
    ch->set_value(1);
    move_object(ch,this_object());
  }
  call_out("leave_servant",1);
  return 1;
}


void leave_servant()
{
    tell_room(this_object(),
    "The handsome servant leaves up again.\n");
}



    

