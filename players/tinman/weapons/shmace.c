
/* coded by gambit */

inherit "/obj/weapon";
#include "/players/whisky/genesis/sys/break_string.h"

#define BS(x) break_string(x+"\n",65)

int charges;

void reset(int flag)
{
    if (flag == 0)
    {
     charges = 2; /* 2 earthquakes per reset */
	  set_name("earthquake mace");
	  set_alias("mace");
          set_type(1);
          set_class(9);
	  set_long(
	    "The earthquake mace is a weapon made out of a wooden handle\n "+
	    "and a glowing steel ball on the end. The power can be felt\n "+
	    "flowing through the handle. With 'use mace' you can sometimes\n "+
       "cast earthquakes with it.\n");
       set_value(300);
	  set_weight(2);
     set_value(500);
     set_hit_func(this_object());
   }
}

string short()
{
    if (query_wielded())
	     return "An earthquake mace [wielded]";
    return "An earthquake mace";
}

int weapon_hit(object ob)
{
    int hit;

    hit =  1 + this_player()->query_str()/3;

    /* critical */
    if (random(200) <= this_player()->query_str())
    {
	write(BS(
	    "Crack, you recklessly smash your earthquake mace against "+
       ob->query_name()+" !"));
	say(BS(
	  "Crack, "+this_player()->query_name()+" recklessly smashes "+
	   this_player()->query_possessive()+" earthquake mace against "+
           ob->query_name()+" !"));

	   tell_object(ob,BS(this_player()->query_name()+" swings "+
	   this_player()->query_possessive()+" earthquake mace against you !"));

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

       


