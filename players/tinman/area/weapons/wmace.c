
/* coded by Tinman */

inherit "/obj/weapon";
#include "/players/tinman/area/break_string.h"

#define BS(x) break_string(x+"\n",65)

int charges;

void reset(int flag)
{
    if (flag == 0)
    {
     charges = 2; /* 2 earthquakes per reset */
	  set_name("weight of war");
	  set_alias("mace");
          set_type(1);
	set_class(15);
	  set_long(
	    "A two ton steel ball attached to a three feet handle.  It must be\n "+
	    "wield by a very strong person.\n");
	  set_weight(15);
	set_value(200000);
     set_hit_func(this_object());
   }
}

string short()
{
    if (query_wielded())
	     return "Weight of War [armed]";
    return "Weight of War";
}

int weapon_hit(object ob)
{
    int hit;

    hit =  1 + this_player()->query_str()/3;

    /* critical */
    if (random(200) <= this_player()->query_str())
    {
	write(BS(
	    "Smash, You smash your Weight of War against "+
       ob->query_name()+" !"));
	say(BS(
	  "Crack, "+this_player()->query_name()+" recklessly smashes "+
	   this_player()->query_possessive()+" Weight of war against "+
           ob->query_name()+" !"));

	   tell_object(ob,BS(this_player()->query_name()+" swings "+
	   this_player()->query_possessive()+" Weight of War against you !"));

	   return (hit);
    }
   return (random(hit));
}     

void init()
{
     ::init();
     add_action("do_use","use");
}

int do_use(string arg)
{
  object *inv;
  int i, sz;

    if (arg!="mace") 
        return 0;
    else if (!query_wielded())
    {
       notify_fail("You have to wield the mace before you can use it.\n");
       return 0;
    }
    else if (charges < 1)
    {
      write("Your mace seems powerless, you have to wait a while.\n");
      return 1;
    }
    say("The earth trembes and shivers !\n");
    write("The earth trembes and shivers !\n");
    charges--;

    inv = all_inventory(environment(this_player()));

    for (sz = sizeof(inv), i = 0; i < sz; i++)
    {
        if (living(inv[i]))
        {
          if (inv[i]->query_npc())
          {
            write(inv[i]->query_name()+" falls down on "+
                  inv[i]->query_possessive()+" butt !\n");
            tell_object(inv[i],"You fall on your butt !\n");
            if (!random(4))
                inv[i]->attack_object(this_player());
            inv[i]->hold(this_player(),2+random(4));
            inv[i]->hit_player( 20 + random(30),5);
          }
          else 
            tell_object(inv[i],"You stumble, but you didn't fall !\n");
        }
    }
   return 1;
}

       


