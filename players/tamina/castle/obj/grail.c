/* The fabulos Holy Grail                       */
/* Coded for Holy Mission by Tamina 27-07-94    */

#include "/players/tamina/defs.h"

int full;

int id(string str) 
{ 
  return str == "grail" || str == "chalice";
}

string short () 
{
  return "The Holy Grail";
}

void long(string str) 
{
  if (!id(str)) return;

  if (intp(full) && full > 0)
  {
    write(
      "This is the most prized holy relic in existence.\n"+
      "Many mortal lives have been lost in the Great Quest\n"+
      "for the Holy Grail, and now, thanks to your brilliant\n"+
      "deeds, the Chalice has been saved from the Darkness.\n"+
      "    You can see that there is a modest amount \n"+
      "    of water at the bottom of the Grail... \n"+
      "    Perhaps it might heal you.\n");
  }
  else
  {
       write(
	"This is the most prized holy relic in existence.\n"+
	"Many mortal lives have been lost in the Great Quest\n"+
	"for the Holy Grail, and now, thanks to your brilliant\n"+
	"deeds, the Chalice has been saved from the Darkness.\n"+
	"    Sadly, you have used up the healing powers of \n"+
	"    the Grail for this day.  Wait for the magic to \n"+
        "    regenerate.\n");
   }
}

void reset(int flag) 
{
   full = 4;
}

void init() 
{
  AA("do_drink", "drink");
}

do_drink(string str) 
{
  int HEAL;
  object vic;
 
  HEAL = 10 + random((TP->query_alignment())/2);

  if (HEAL > 40)   HEAL = 40;

  if (strstr(str,"grail",0)!=-1)
  {
    if (full > 0) 
    {
      if (TP->query_money() < (HEAL*2)) 
      {
        write("Sadly, you do not have enough to show sufficient\n"+
	      "gratitude to your God...\n");
        return 1;
      } 
      else 
      if (objectp(vic=TP->query_attack()) && E(TP) == E(vic) )
      {
	write("Drinking from the Grail while fighting is NOT allowed!!\n");
        return 1;
      }
      else 
      if (TP->query_alignment() < -10)
      {
        write("Thou heretic!!\n"+
	      "Dost thou think that such a devil as thee,\n"+
	      "is allowed to take even a sip from the Holy Chalice?\n");
	  say(TPN+" is so evil that "+TP->QPRO+" poisons "+TP->QOBJ+"self\n"+
	      "on the Holy Water from the Grail.\n");
        TP->add_poison(HEAL/4);
        TP->hit_player(HEAL);
        return 1;
      }
      else 
      if (full > 0)
      {
        write("You let the healing waters of the Holy Grail slip\n"+
              "tenderly down your throat.  You instantly feel\n"+
	      "regenerated!!\n"+
	      "You show your thanks to your God.\n");
           say(TPN+" takes a sip of Holy Water from the Holy Grail.\n"+
               CAP(TP->QPRO)+" looks instantly revived!\n");
         TP->heal_self(HEAL);
         TP->add_money(-(HEAL*2));
         full = full -1;
         return 1;
      }
    }
    else  
    {
      write("Sadly, there is no Holy Water left in the Grail.\n");
      return 1;
    }   /* endif */
  }    /* endif */
  NFAIL("Drink what from where?\n");
  return 0;
}

int get()
{  
  return 1;  
}

int query_weight() 
{  
  return 1;  
}

string query_auto_load() 
{  
  return "players/tamina/castle/obj/grail:"+full;  
}

void init_arg(string arg)
{
}
 
void dest() 
{  
  destruct(TO);  
}

int drop(string arg) 
{
  if (arg && !id(arg)) return 0;

  if (query_verb() == "sell") 
  {
    write("You really don't want to sell the Holy Grail\n"+  
          "that you fought so hard for.\n");
    return 1;
  }
  else if (query_verb() == "give") 
  {
    write("You do not want to just give the Holy Grail away!\n");
    return 1;
  }
  write("Such a marvellous relic, you do not want to drop the Holy Grail.\n");
  return 1;
}
