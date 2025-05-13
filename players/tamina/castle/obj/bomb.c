/*
 *  A Big Black Bomb, coded for Holy Mission
 *       By Elemental Tamina   10-08-94
 */

#include "/players/tamina/defs.h"
  object ob;
  int i,j;
  status lit;

int id(string str)
{
  return str == "bomb" || str == "black bomb";
}

string short()
{
  return "A big black Bomb";
}

void long()
{
  if (lit)
  {
    write("This is a large black bomb, with a hissing fuse !!!\n"+
	  "It is going to blow any second now !!\n");
  }
  else
  {
    write("A rather large beaker, with a wide open top, in which is\n"+
          "a strange blue powder.  Over the top there is a funnel, with\n"+
  	  "a little blue fuse poking out of the top.\n"); 
  }
}

int query_weight()
{
  return 4;
}
 
int query_value()
{
  return 1000;
}

int prevent_insert()
{
  write("The bomb is not stable enough to be put in there...\n");
  return 1;
}

int get()
{
  return 1;
}

init()
{
  AA("_light",   "light");
}

int _light(string str)
{
  if (str == "fuse" || str == "bomb" || str == "the bomb" || str == "the fuse")
  {
    if (lit)
    {
      write("But the bomb is already lit !!!\n"+
	    "It is going to blow !!\n");

      return 1;
    }
    write("You swiftly set a flame to the fuse on the bomb,\n"+
          "and watch it catch light.\n");
      say(TPN+" lights a fuse on "+TP->QPOS+" big, black, bomb...\n");

    call_out("explosion", 7);
    lit = 1;
    return 1;
  }
  else
  {
    NFAIL("Light what?\n");
    return 0;
  }
}

cloud()
{
  shout("\nA great black cloud passes over the lands of Holy Mission.\n");
  destruct(TO);

  return 1;
}

explosion()
{
  if (living(ENV))
  {
    TOBJ(ENV, 
     "The Bomb blows up into smithereens !!!\n");
    TRM (E (ENV),
     "A Big, Black Bomb, carried by "+ENV->NAME+", just exploded.\n"+
     CAP(ENV->QPRO)+" now looks slightly blackened...\n");

    ENV->set_description("looks slightly charred...well-done even!");
    ENV->hit_player(70 + random(55), 7); 

    destruct(TO);
    return 1;
  }
  else
  {
    shout("\n. . .B B B B O O O O O O O M M M M M M m m m m . . .\n\n");
    call_out("cloud", 3);

    ob = all_inventory (E(TO));
     j = sizeof (ob);
    if (j > 20)  j = 20;

    for (i = 0; i < j; i++)
    {
      if (living(ob[i]))
      { 
        ob[i]->attacked_by(TP);
        ob[i]->hit_player(175 + random(51));
      }
    }
    return 1;
  }
}
