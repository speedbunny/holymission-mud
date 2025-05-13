
/*  iblackmoon the mistress */

#define _tp  this_player()
#define _tpn _tp->query_name()
#define PARTNER "/players/warlord/guild/room"
#define MAXPR    100
#define _wiz "/players/whisky/"
#define _to  this_object()

inherit "/obj/npc";
int chk;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("Nun Blackmoon");
       set_alt_name("blackmoon");
       set_living_name("blackmoon");
       set_short("Nun Blackmoon");
       set_level( 5);
       set_race("hobbit");
       set_gender(2);
       load_chat(8,
       ({ 
        "Nun Blackmoon says: The more you practice the better are your skills.\n",
        "Nun Blackmoon says: Cure and Meditate are one of the best skills.\n", 
        "Nun Blackmoon starts to concentrate on aikido.\n",
        "Nun Blackmoon examines her rucksack.\n",
        "Nun Blackmoon drinks some water.\n",
        "Nun Blackmoon says: The follower will never be better than the leader.\n",
        "Nun Blackmoon smiles happily.\n",
        "Nun Blackmoon hugs you.\n",
        "Nun Blackmoon sings a beautiful song.\n",
        "Nun Blackmoon says: Beeing a Monk means accepting the law of nature.\n",
        "Nun Blackmoon bounces around.\n",
       }));
       load_a_chat(8,
       ({
        "Nun Blackmoon says: Better you leave now, or I'll have to kill you.\n",
        "Nun Blackmoon growls.\n",
        "Nun Blackmoon says: Here we go and give you some lessons.\n",
        "Nun Blackmoon fumes angrily.\n",
       }));
       set_long(
       "You see a medium aged, green eyed hobbit nun.\n"+
       "She looks like one of the well-known monk masters.\n"+
       "All in all she look friendly and able to give you\n"+
       "some 'practice' sessions.\n");
       set_dead_ob(this_object());
       set_attacks(7);
       set_attacks_change(70);
       set_fol_change(30);
       set_rid_change(10);
       set_no_steal();
       set_wimpy();
       add_money(10000 + random(5000));
       move_object(clone_object("/players/whisky/obj/jeweled_earrings"),
       this_object());
       init_command("wear earrings");
       move_object(clone_object(_wiz+"seaworld/obj/rucksack"),_to);
       move_object(clone_object(_wiz+"guild/obj/mace"),_to);
       init_command("wield mace");
       enable_commands();
       chk = 1;
      }
}

int id(string arg)
{
     return arg=="nun blackmoon" || arg=="nun" || arg=="blackmoon";
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
        "Nun Blackmoon curseys gracefully.\n");
        return 0;
     }
    if (sscanf(arg,"%s smiles %s",h1,h2)==2)
    {
        tell_room(environment(),
        "Nun Blackmoon snickers happily.\n");
        return 0;
     }
    if (sscanf(arg,"%s kicks %s",h1,h2)==2)
    {
        tell_room(environment(),
        "Nun Blackmoon fumes angrily.\n");
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
        
        write("Blackmoon tells you:\n"+
        "You are no Monk, go home !\n");
        return 1;
    }
    else if (catch(call_other(PARTNER,"???")))
    {
       write("Blackmoon tells you:\n"+
       "I have no time for you, go home !\n");
       return 1;
    }
    else if (!arg)
    {
       write("Blackmoon tells you: Here are the skills I can teach you:\n");
       tell_object(this_player(),PARTNER->list_skills(_tp,2));
       return 1;
    }
    else if (!(sklev=PARTNER->query_skill(_tp,"monk_"+arg)) )
    {
        write("Blackmoon tells you:\n"+
                    "This is no skill I know !\n");
        return 1;
     }
      else if (sklev > MAXPR)
      {
          write("Blackmoon tells you:\n"+
                      "Sorry, but I can't teach you more, you are already "+
                      "as good as i am.\n");
          return 1;
      }
      else 
      {
         if (chk && sklev > random(MAXPR + _tp->query_int() + _tp->query_dex()))
         {
             write("You practice your "+arg+" skill with Blackmoon for "+
                   to_string(cost)+" gold coins.\n");
             write("You are confused.\n");
             say(_tp->query_name()+" looks confused.\n");
             chk--;
             return 1;
         }
         if (PARTNER->raise_skill(_tp,"monk_"+arg,100))
         {
             write("You practice your "+arg+" skill with Blackmoon for "+
                   to_string(cost)+" gold coins.\n");
             chk=1;
          }
          else
          {
             write("Oops, Blackmoon made a mistake. She seems to tired to teach.\n");
             write("You pay nothing.\n");
          }
      }
    return 1;
}


                     
     
varargs int hold(object ob,int time)
{
    if (time > 4)
        return random(4);
    return time;
}

int monster_died(object mob)
{
   object ob;

   ob = find_object("/players/whisky/guild/monster/blackmoon");
   if (!this_player()->query_immortal())
   {
   shout(this_player()->query_name()+
   " sucessfully challenged Blackmoon the Monk Mastress !\n");
   }

   if (ob)
       destruct(ob);
  return 0;
}

int add_poison(int x)
{
    return (x/30);
}
