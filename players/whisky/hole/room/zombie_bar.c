
/* zombie bar */

inherit "/obj/std_pub";
#include "../hole.h"

void reset(int arg) 
{
    ::reset(arg);
    if (!arg)
    {
        set_light( 1);
        short_desc = "In the Zombie bar";
        long_desc = BS(
        "You have entered the Zombie bar of the black hole. A friendly "+
        "Zombie is waiting behind the counter waiting for you to order "+
        "drinks or snacks. There is a sign hanging on the wall.");
        
        dest_dir = 
        ({
            PATH + "h16","west",
        });
        set_waiter("A horny Zombie");
        set_header("            THE  ZOMBIE  BAR           \n");
        add_drink("drake blood",500,20,"alc",150);
        add_drink("bloody mary",250,12,"alc",90);
        add_drink("horny zombie",25,4,"alc",20);
        add_drink("headsmasher",100,50,"alc",90);
     }
}
 
