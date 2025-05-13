
/* practice room */

#define _tp  this_player()
#define _tpn _tp->query_name()
#define PARTNER "/players/sauron/guild/room"
#define MAXPR   60

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("Monk Wuli");
       set_alt_name("wuli");
       set_short("Monk Wuli");
       set_level(60);
       set_wc(60);
       set_race("human");
       set_long(
       "You see a medium aged, blue eyed human monk.\n"+
       "He looks like one of the well-known monk masters.\n"+
       "All in all he look friendly and able to give you\n"+
       "some 'practice' sessions.\n");
      }
}

mixed attack()
{
   if (::attack() && random(60))
       return ::attack();
    return 0;
}
  
void init()
{
    ::init();
    add_action("do_practice","practice");
    add_action("do_practice","pr");
}

int do_practice(string arg)
{
   int cost, sklev;


    if (_tp->query_guild() != 7)
    {
        notify_fail("You are no Monk, go home !\n");
        return 0;
    }
    else if (catch(call_other(PARTNER,"???")))
    {
       notify_fail("The master has no time for you, go home !\n");
       return 0;
    }
    else if (!arg)
    {
       PARTNER->list_skills(_tp,2);
       return 1;
    }
    else if (!(sklev=PARTNER->query_skill(_tp,"monk_"+arg)) )
    {
        notify_fail("This is no skill I know !\n");
        return 0;
     }
     else if (_tp->query_money() < (cost=PARTNER->query_cost(_tp,"monk_"+arg)))
     {
         notify_fail("But further practice in "+arg+" would cost you \n"+
                     to_string(cost)+" coins.\n");
         return 0;
      }
      else if (sklev > MAXPR)
      {
          notify_fail("Sorry, but I can't teach you more, you have to\n"+
                      "find another master.\n");
           return 0;
      }
      else 
      {
         write("You practice your "+arg+" skill with Wuli for "+
               to_string(cost)+" gold coins.\n");
         _tp->add_money(-cost);
         PARTNER->raise_skill(_tp,"monk_"+arg,1);
      }
    return 1;
}


                     
     
