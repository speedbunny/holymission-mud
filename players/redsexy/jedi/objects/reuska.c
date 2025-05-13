inherit "obj/treasure";
#include "/players/redsexy/defs.h"

object ob;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Reuska table");
  set_alias("table");
  set_short("Reuska table"); 
  set_long("The game of Reuska is one which follows the Noghri traditions " +
           "of chance and death.  You risk experience and credits playing " +
           "here. For more information, type 'help reuska'.\n");
}
 
init()
{
  ::init();
  add_action("_play","play");
  add_action("_help","help");
}

_help(str)
{
    if ((!str) || (str != "reuska"))
    {
        return 0;
    }

    write("Reuska is a Noghri game of pure chance, deriving its name from\n");
    write("their word for 'voluntary suicide'.  You are given a spherical\n");
    write("metal object, which you have to throw against the wall to which\n");
    write("the table is adjancent.  This object, the 'reuska', is deflected\n");
    write("off the wall into one of the holes on the table, and each hole \n");
    write("holds its own prize or loss.\n\n");
    write("Hole 1 represents the Noghri God of Love and rewards you experience.\n");
    write("Hole 2 represents the Noghri God of Wealth and rewards you with credits.\n");
    write("Hole 3 represents the Noghri God of War and takes away experience.\n");
    write("Hole 4 represents the Noghri God of Greed and takes away credits.\n\n");
    write("The maximum loss incurred in any one throw is 5000 experience points.\n");
    write("If you are not willing to take that risk, then do not play the game.\n\n");    
    write("                                                            Redsexy.\n\n");          
    return 1;
}

 
_play(str)
{
  int rnd_value,rnd_choice,win_lose,has;
    
  ob=present("red-credits",TP);
  if(!ob) 
    {write("You have no credits to bet with.\n");
    return 1;}
  has=ob->query_credits(); 
  if(5000>has)
    {write("You have to have 5000 credits to play at this table!\n");
        return 1;
   }
  else 
    if(TP->query_exp()<5000)
    {write("You must have at least 5000 experience points to play Reuska.\n");
  }

  else
  {
    rnd_value=(random(5)+1)*1000;
    rnd_choice=random(2);
    win_lose=random(2);
    write("You throw your reuska against the wall.\n");
    say(TP->RNAME+" throws the reuska.\n");
    switch(rnd_choice)
    {
      case 0: /* credits */
        switch(win_lose)
        {
          case 0: /* lose credits */
            write("The Noghri jeer as the reuska lands in hole 4.  You lose "+rnd_value+" credits.\n");
            say("The reuska lands in hole 4 and "+TP->RNAME+" loses some credits.\n");
            ob->add_credits(-rnd_value);
            break;
 
          case 1: /* win credits */
            write("The reuska lands in hole 2 and the Noghri are upset.  You win "+rnd_value+" credits.\n");
            say("The reuska lands in hole 2 and "+TP->RNAME+" wins some credits.\n");
            ob->add_credits(rnd_value);
            break;
        }
        break;
 
      case 1: /* experience */
        switch(win_lose)
        {
          case 0: /* lose experience */
            write("The Noghri cackle in glee as the reuska lands in hole 3.  You lose "+rnd_value+" experience points.\n");
            say(TP->RNAME+" loses some experience as the reuska lands in hole 3.\n");
            TP->add_exp(-rnd_value);
            break;
 
          case 1: /* win experience */
            write("The Noghri sound angry as the reuska falls into hole 1 and you win "+rnd_value+" experience points!\n");
            say(TP->RNAME+" wins some experience as the reuska lands in hole 1.\n");
            TP->add_exp(rnd_value);
            break;
        }
        break;
    }
  }
  return 1;
}
            

get() { return 0; }
