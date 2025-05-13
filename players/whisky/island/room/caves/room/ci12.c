
/* ci12 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
     {
        CM("warrior");
        CM("warrior");
        CM("warrior");
     }
     if (!present("orc chieftrain",this_object()))
        CM("chieftrain");
     if (flag == 0)
     {
        set_light(0);
        short_desc = "The Chieftrains chamber";
        long_desc = BS(
        "You have entered the big sleeping chamber of the orc "+
        "Chieftrain. Where the chieftrain preferes to sleep "+
        "with his harem of warrior ladies. In the middle of "+
        "this place is a big curtain and some leather instruments "+
        "are fixed to the walls. There is a campfire to the north and "+
        "a big boulder to the east."); 

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "curtains","The curtains are made of wool",
         "boulder","A big round boulder, heavy but maybe to push aside",
         "campfire","Just a campfire to have it warm during winternights",
        });
        dest_dir = 
       ({
          PATH+"ci8","south",
       });
    }
}


void init()
{
     add_action("do_push","push");
     add_action("do_push","move");
     ::init();
}

int boulder_moved()
{
     return (sizeof(dest_dir) > 2);
}

void add_dest_dir(string *dir)
{
    dest_dir = dest_dir + dir;
}

int do_push(string arg)
{
    call_other(PATH+"ci13","???");

    if (arg!="boulder")
        return 0;
    else if (boulder_moved())
    {
        write("Ughh, nothing happens, the boulder was already moved.\n");
        return 1;
    }
    write("You push the boulder and reveal a hidden exit to the west.\n");
    say(this_player()->query_name()+" pushes the boulder aside.\n");
    add_dest_dir(({PATH+"ci13","west"}));
    init();
    return 1;
}

