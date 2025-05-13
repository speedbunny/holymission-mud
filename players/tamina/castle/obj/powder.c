#include "/players/tamina/defs.h"

inherit "obj/thing";
  object ob;
  int i, j;

reset(arg) 
{
  ::reset(arg);
  if (arg) return;

    set_name("powder");
    set_short("Some powder");
    set_long("This is a little packet of a strangely aromatic powder.\n");
    set_weight(0);
    set_value(60);
    set_can_get(1);
}

int prevent_insert()
{
  write("But you would lose all the powder if you put it in there !!\n");
  return 1;
}

init()
{
  ::init();
  AA("_light", "light");
}

int _light(string str)
{
  if (str == "powder" || str == "the powder")
  {
    write("You set alight the strangely smelling powder, and it begins to hiss...\n");
      say(TPN+" sets alight "+TP->QPOS+" powder.  It begins to hiss.\n");

    call_out("explosion", 4);

    return 1;
  }
}

explosion()
{
  if (living(ENV))
  {
    TOBJ (ENV,
     "The small packet of powder explodes in your face !!\n");
    ENV->hit_player(25 + random(41));

    TRM (E (ENV),
     "Smoke starts to rise from "+ENV->NAME+"...\n");

    destruct (TO);
    return 1;
  }
  else
  {
    TRM (E (TO), 
     "\nThere is a great explosion in the room !!\n");

    ob = all_inventory (E(TO));
     j =  sizeof(ob);
    if (j > 20) j = 20;

    for (i = 0; i < j; i++)
    {
      if (living(ob[i]))
      {
        ob[i]->attacked_by(TP);
        ob[i]->hit_player(20 + random(21));
      }
    }
    destruct (TO);
    return 1;
  }
}
