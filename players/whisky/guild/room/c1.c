
inherit "room/room";
#include "../guild.h"

int count;

void reset(int arg) 
{
  count = 0;

  if (filter_live(this_object()) < 4)
  {
    CM("omonk");
    CM("omonk");
    CM("omonk");
    CM("omonk");
  }

    if (!present("torch",this_object()))
    {
        move_object(clone_object("/obj/torch"),this_object());
        move_object(clone_object("/players/cashimor/objects/match"),
                    this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc =  BS(
          "You are standing on the western corner of the monk "+
          "chapel. To the east is the entrance and to the north "+
          "the corridor leads further. There is a big 'iron wheel' "+
          "lying on the bottom and covering most parts of it.");
    items = ({ 
            "walls","White stone walls",
            "bottom","An earthy bottom with abig hole in the middle",
            "wheel","A big iron wheel, but probably you can push it a bit",
            "hole","@@query_hole",
             });
    dest_dir = 
        ({
     PATH+"c4","north",
     PATH+"c2","east"
        });
        
 }

void init()
{
     ::init();
     add_action("do_enter","enter");
     add_action("do_push","push");
     add_action("do_push","roll");
     add_action("do_push","move");
}

int do_push(string arg)
{
    if (arg!="wheel" && arg!="iron wheel") 
        return 0;

    say(this_player()->query_name()+" rolls the wheel aside.\n");

    if (!count)
    {
        write("You roll the wheel, and recover a big hole in the ground.\n");
        count = 1;
        return 1;
    }
    write("You roll the wheel, and cover the big hole in the ground.\n");
    count = 0;
  return 1;
}
    
int do_enter(string arg)
{
     if (arg!="hole")
     {
         notify_fail("Enter what ?\n");
         return 0;
     }
     else if (!count)
     {
         notify_fail("Ughh, a hole where ?\n");
         return 0;
     }
     write("You squeeze yourself down the hole in the bottom.\n");
     this_player()->move_player(
     "climbing into the hole in the bottom#players/whisky/guild/room/uc1");
  return 1;
}

string query_hole()
{
   if (count)
       return "There is a big dark hole in the ground, big enough to enter";
   return "You see nothing of interest";
}
     
