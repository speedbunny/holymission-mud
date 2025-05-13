
/* lair.c */

inherit "/room/south/island";
#include "_defs.h"
#include "/players/patience/GenObj/move_blocked.h"


string add_long()
{
    return (
    "You are standing at the bottom of the well, about thirty feet below\n" +
	 "the surface. Bones lie strewn about in a random fashion, many of them\n" +
	 "or shattered. The only way out is the way in, back up the ladder.\n");
}

string *add_item()
{
    return ({
    "well","You are just standing on the bottom of the well",
    "bones","Ohh, dont worry they are just humanoid bones",
    "ladder","The ladder is going up, maybe someone is waiting for you !\n",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd17","up",
    });
}
 
void get_objects()
{
  object dragon, m, s, p, g, sg;   

     if (!present("dragon",this_object()))
  	 {
	     dragon = clone_object("/players/whisky/obj/std_dragon");
        dragon->set_no_follow();
        dragon->set_age(12);
        dragon->set_colour("silver");
        move_object(dragon,this_object());

        move_blocked(m = clone_object("/obj/money"),this_object(),dragon);
        m->set_money(8000+random(8000));
        move_blocked(s = clone_object("/players/whisky/obj/stone_scroll"),
                     this_object(),dragon);
        move_blocked(p = clone_object("/players/whisky/obj/hearo_potion"),
                     this_object(),dragon);
        move_blocked(g = clone_object("/obj/treasure"),this_object(),dragon);
        g->set_name("gem of arcanarton");
        g->set_alt_name("diamond");
        g->set_short("huge diamond");
        g->set_long("A big valuable diamond.\n");
        g->set_value(1500);
        g->set_weight(1);
      }

}

