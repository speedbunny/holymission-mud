inherit "obj/treasure";
#include "/players/redsexy/defs.h"

object ob;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Mandalesk table");
  set_alias("table");
  set_short("Mandalesk table"); 
  set_long("Mandalesk is a Whipid game of die!\n" +
           "You risk loosing experience,credits or both by playing with the big boys " +
           "but for more information, type 'help mandalesk'.\n\n");
}
 
init()
{
  ::init();
  add_action("_play","play");
  add_action("_help","help");
}

_help(str)
{
    if ((!str) || (str != "mandalesk"))
    {
        return 0;
    }

    write("Mandalesk is a Whipid die game, centering around their belief\n");
    write("that numbers are magical.  Odd numbers are considered particularly\n");
    write("cursed, and even numbers are meant to represent good fortune - so\n");
    write("quite simply in this game you are given a die to throw, and the \n");
    write("Whipids reward you according to how lucky or cursed they believe \n");
    write("you to be after seeing the outcome of the throw.\n\n");
    write("1,3 and 5 are considered cursed numbers.  The higher the number the worse the punishment.\n");
    write("2,4 and 6 are considered lucky numbers.  The higher the number, the greater the reward.\n");
    write("The maximum loss incurred in any one throw is 2000 experience points and credits.\n");
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
  if(2000>has)
    {write("You have to have 2000 credits to play at this table!\n");
        return 1;
   }
  else 
    if(TP->query_exp()<2000)
    {write("You must have at least 2000 experience points to play Mandalesk.\n");
  }

  else
  {
    rnd_value=(random(2)+1)*1000;
    rnd_choice=random(3);
    win_lose=random(2);
    write("You throw your die on the table.\n");
    say(TP->RNAME+" throws the Whipid die.\n");
    switch(rnd_choice)
    {
      case 0: /* credits */
        switch(win_lose)
        {
          case 0: /* lose credits */
            write("You throw a 1.  The Whipids take "+rnd_value+" credits off you, whispering about your curse.\n");
            say(TP->RNAME+" throws a 1 and loses some credits.\n");
            ob->add_credits(-rnd_value);
            break;
 
          case 1: /* win credits */
            write("You have thrown a 2!  The Whipids bless you further with "+rnd_value+" credits.\n");
            say(TP->RNAME+" Throws a 2 and wins some credits.\n");
            ob->add_credits(rnd_value);
            break;
        }
        break;
 
      case 1: /* experience */
        switch(win_lose)
        {
          case 0: /* lose experience */
            write("You throw a 3.  The Whipids laugh at your misfortune and take "+rnd_value+" experience points.\n");
            say(TP->RNAME+" loses some experience by throwing a 3.\n");
            TP->add_exp(-rnd_value);
            break;
 
          case 1: /* win experience */
            write("You throw a four, the Whipids are delighted and reward you with "+rnd_value+" experience.\n");
            say(TP->RNAME+" wins some experience by rolling in a 4.\n");
            TP->add_exp(rnd_value);
            break;
        }
        break;

      case 2: /* both*/
        switch(win_lose)
        {
          case 0: /* lose */
            write("You throw a 5.  The Whipids don't even look at you, taking \n");
            write(rnd_value+" experience points and credits away.\n");
            say(TP->RNAME+" loses experience and credits by throwing a 5.\n");
            TP->add_exp(-rnd_value);
            ob->add_credits(-rnd_value);
            break;
 
          case 1: /* win */
            write("You throw a six, the Whipids beg desperately for your good fortune, \n");
            write("rewarding you with "+rnd_value+" experience and credits.\n");
            say(TP->RNAME+" wins some credits and experience by rolling in a glorious 6.\n");
            TP->add_exp(rnd_value);
            break;
        }
        break;

    }
  }
  return 1;
}
            

get() { return 0; }
