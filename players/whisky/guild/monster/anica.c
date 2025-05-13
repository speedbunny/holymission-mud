
/* anica the mistress */

#define _tp  this_player()
#define _tpn _tp->query_name()
#define PARTNER "/players/sauron/guild/room"
#define MAXPR   65
#define _wiz "/players/whisky/"
#define _to  this_object()

inherit "/obj/monster";
int chk;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("Nun Anica");
       set_alt_name("anica");
       set_living_name("anica");
       set_short("Nun Anica");
       set_level(75);
       set_race("hobbit");
       set_gender(2);
       load_chat(8,
       ({ 
        "Nun Anica says: The more you practice the better are your skills.\n",
        "Nun Anica says: Cure and Meditate are one of the best skills.\n", 
        "Nun Anica starts to concentrate on aikido.\n",
        "Nun Anica examines her rucksack.\n",
        "Nun Anica drinks some water.\n",
        "Nun Anica says: The follower will never be better than the leader.\n",
        "Nun Anica smiles happily.\n",
        "Nun Anica hugs you.\n",
        "Nun Anica sings a beautiful song.\n",
        "Nun Anica says: Beeing a Monk means accepting the law of nature.\n",
        "Nun Anica bounces around.\n",
       }));
       load_a_chat(8,
       ({
        "Nun Anica says: Better you leave now, or I'll have to kill you.\n",
        "Nun Anica growls.\n",
        "Nun Anica says: Here we go and give you some lessons.\n",
        "Nun Anica fumes angrily.\n",
       }));
       set_long(
       "You see a medium aged, green eyed hobbit nun.\n"+
       "She looks like one of the well-known monk masters.\n"+
       "All in all she look friendly and able to give you\n"+
       "some 'practice' sessions.\n");
       set_spell_mess1("Nun Anica makes a combat move\n");
       set_spell_mess2("You are hit by Anica's feet in your face !\n");
       set_chance(80);
       set_spell_dam(80); 
       set_move_at_reset();
       set_wimpy();
       add_money(2500 + random(4000));
       move_object(clone_object("/players/whisky/obj/earrings"),
       this_object());
       init_command("wear earrings");
       move_object(clone_object(_wiz+"seaworld/obj/rucksack"),_to);
       move_object(clone_object(_wiz+"guild/obj/mace"),_to);
       init_command("wield mace");
       enable_commands();
       chk=1;
      }
}

int id(string arg)
{
     return arg=="nun anica" || arg=="nun" || arg=="anica";
}

int attack()
{
   if (::attack())
   {
      if (!random(2))
          ::attack();
      if (!random(3))
          ::attack();
      if (!random(4))
          ::attack();
      if (!random(5))
          ::attack();
      return 1;
    }
    return 0;
}
  
void init()
{
    ::init();
    add_action("do_practice","practice");
    add_action("do_practice","pr");
}

mixed catch_tell(string arg)
{
   string h1, h2;

    if (sscanf(arg,"%s bows %s",h1,h2)==2)
    {
        tell_room(environment(),
        "Nun Anica curseys gracefully.\n");
        return 0;
     }
    if (sscanf(arg,"%s smiles %s",h1,h2)==2)
    {
        tell_room(environment(),
        "Nun Anica snickers happily.\n");
        return 0;
     }
    if (sscanf(arg,"%s kicks %s",h1,h2)==2)
    {
        tell_room(environment(),
        "Nun Anica fumes angrily.\n");
        return 0;
     }
    return ::catch_tell(arg);
}

/* practice */

int do_practice(string arg)
{
   int cost, sklev;


    if (_tp->query_guild() != 7)
    {
        
        write("Anica tells you:\n"+
        "You are no Monk, go home !\n");
        return 1;
    }
    else if (_tp->query_level() < 11)
    {
        write("Anica tells you:\n"+
        "I only teach Monks above level 10 !\n");
        return 1;
    }
    else if (catch(call_other(PARTNER,"???")))
    {
       write("Anica tells you:\n"+
       "I have no time for you, go home !\n");
       return 1;
    }
    else if (!arg)
    {
       write("Anica tells you: Here are the skills I can teach you:\n");
       tell_object(this_player(),PARTNER->list_skills(_tp,2));
       return 1;
    }
    else if (!(sklev=PARTNER->query_skill(_tp,"monk_"+arg)) )
    {
        write("Anica tells you:\n"+
                    "This is no skill I know !\n");
        return 1;
     }
     else if (_tp->query_money() < (cost=PARTNER->query_cost(_tp,"monk_"+arg)))
     {
         write("Anica tells you:\n"+
         "Further practice in "+arg+" would cost you "+
                     to_string(cost)+" coins.\n");
         return 1;
      }
      else if (sklev > MAXPR)
      {
          write("Anica tells you:\n"+
                      "Sorry, but I can't teach you more, you have to "+
                      "find another master.\n");
           return 1;
      }
      else 
      {
         if (chk && sklev > random(MAXPR +_tp->query_int()+_tp->query_dex()) )
         {
             write("You practice your "+arg+" skill with Anica for "+
                   to_string(cost)+" gold coins.\n");
             say("Nun Anica shows something to "+_tp->query_name()+"\n",_tp);
             _tp->add_money(-cost);
             write("You are confused.\n");
             say(_tp->query_name()+" looks confused.\n");
             chk--;
                if (sklev > (MAXPR/2) && !random(5))
             {
                write("Anica tells you: Maybe you should visit Blackmoon "+
                      "she is a better mastress.\n");
             }
             return 1;
         }
         else if (PARTNER->raise_skill(_tp,"monk_"+arg,1))
         {
             write("You practice your "+arg+" skill with Anica for "+
                   to_string(cost)+" gold coins.\n");
             say("Nun Anica shows something to "+_tp->query_name()+"\n",_tp);
             _tp->add_money(-cost);
             chk=1;
          }
          else
          {
             write("Oops, Anica made a mistake. She seems to tired to teach.\n");
             write("You pay nothing.\n");
          }
      }
    return 1;
}


                     
     
