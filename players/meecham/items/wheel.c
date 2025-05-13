inherit "obj/treasure";
#include "/players/meecham/def.h"
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("magic wheel");
  set_alias("wheel");
  set_short("Magic wheel"); 
  set_long("\This simple wheel has pegs along the outside and an external\n\
peg which plinks through the rest while the wheel is spinning.  You can\n\
try your luck, risking experience or gold, and 'spin wheel'.\n");
}
 
init()
{
  ::init();
  add_action("spin","spin");
}
 
spin(str)
{
  int rnd_value,rnd_choice,win_lose;
  if((!str) || (str !="wheel")) return 0;
  if(TP->query_money()<5000)
    write("You must have at least 5000 coins to spin the wheel.\n");
  else if(TP->query_exp()<5000)
    write("You must have at least 5000 experience points to spin the wheel.\n");
  else
  {
    rnd_value=(random(5)+1)*1000;
    rnd_choice=random(2);
    win_lose=random(2);
    printf("%d %d\n",rnd_choice,win_lose);
    write("The wheel spins round and round and slows to a stop.\n");
    say(TPN+" spins the wheel.\n");
    switch(rnd_choice)
    {
      case 0: /* money */
        switch(win_lose)
        {
          case 0: /* lose money */
            write("You lose "+rnd_value+" coins.\n");
            say(TPN+" looks very unhappy.\n");
            TP->add_money(-rnd_value);
            break;
 
          case 1: /* win money */
            write("You win "+rnd_value+" coins!\n");
            say(TPN+" looks very happy.\n");
            TP->add_money(rnd_value);
            break;
        }
        break;
 
      case 1: /* experience */
        switch(win_lose)
        {
          case 0: /* lose experience */
            write("You lose "+rnd_value+" experience points.\n");
            say(TPN+" looks very unhappy.\n");
            TP->add_exp(-rnd_value);
            break;
 
          case 1: /* win experience */
            write("You win "+rnd_value+" experience points!\n");
            say(TPN+" looks very happy.\n");
            TP->add_exp(rnd_value);
            break;
        }
        break;
    }
  }
  return 1;
}
            

get() { return 0; }
