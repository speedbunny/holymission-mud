#include "/players/tamina/defs.h"
  object ob1, ob2, ob3, bomb;

id(str)
{
  return str == "beaker" || str == "bomb ingredient" || str == "base";
}

short()
{
  return "A Beaker";
}

long()
{
  write("A rather large beaker, with a wide open top.\n");
}

query_weight()
{
  return 2;
}
 
query_value()
{
  return 40;
}

get()
{
  return 1;
}

init()
{
  AA("make",  "make");
}

int make(string str)
{ 
  ob1 = present("fuse", TP);
  ob2 = present("powder", TP);
  ob3 = present("funnel", TP);

  if (str == "bomb")
  {
    if (ob1 && ob2 && ob3)                 
    {
      write("You place the funnel over the beaker, and start to pour\n"+
	    "the powder into the base through the funnel.\n\n"+
	    "You then put the little fuse into the top of the beaker,\n"+
	    "and you now have your Bomb.\n");
	say(TPN+" makes a Bomb from "+TP->QPOS+" ingredients.\n");

      bomb = CLO (COBJ + "bomb");
      TR (bomb, TP);
  
      destruct(ob1);
      destruct(ob2);
      destruct(ob3);
      destruct(TO);

      return 1;
    }
    else
    {
      write("You do not have all the ingredients to make a bomb with.\n");
        say(TPN+" tries to make a bomb, but does not have all the\n"+
            "necessary ingredients.\n");

      return 1;
    }
  }
  else
  {
    write("Make what?\n");
    return 1;
  }
}
