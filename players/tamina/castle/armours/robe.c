inherit "obj/armour";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (arg != 0) return;

    set_name("robe of the sorceress");
    set_alias("robe");
    set_type("robe");
    set_short("Robe of the Sorceress");
    set_long(
  "This is the legendary Robe of the Sorceress, once belonging to \n"+
  "the powerful witch, Morgan le Fey.  You think it has many \n"+
  "magical properties.  Perhaps you could get it identified.\n");
    set_ac(1);
    set_weight(1);
    set_size(0);
    set_value(3000);
}

int wear_fun(object ob) 
{
  object shad;

  if (!ob->robe_shad())
  {
    shad = clone_object(COBJ + "robe_shad");
    shad->start_shadow(ob, 0, "robe_shad");
    write("As you put on the wondrous robe, you suddenly feel less substantial.\n");
  }
  return 1;
}

int remove_fun(object ob)
{
  if (ob->robe_shad())
  {
    destruct(ob->robe_object());
    write("You body feels more substantial now.\n");
  }
  return 1;
}

int query_mage_wear()     {    return 1;    }
int query_monk_wear()     {    return 1;    }
int query_ninja_wear()    {    return 1;    }
int query_summoner_wear() {    return 1;    }
int query_fighter_wear()  {    return 1;    }

string query_info()
{
  return 
"This is the fabulous Robe of the Sorceress, worn by \n"+
"Morgan le Fey.  It has the power to absorb most attacks\n"+
"made against the wearer.\n";
}

