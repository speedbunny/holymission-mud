
/* probe */
#define _tp this_player()
#define _tpl _tp->query_level()
#define _tpn _tp->query_name()

inherit "/obj/treasure";

void reset(int flag)
{
   if (flag == 0)
   {
     set_name("combat sprite");
     set_alias("sprite");
     set_short(capitalize(query_name()));
     set_long(
     "This is just a sprite.\n");
     set_value(1000);
    set_weight(3);
   }
}
/*
void init()
{
  add_action("fcn_probe","probe");
  ::init();
}

int fcn_probe(string arg)
{
   object mob;
   string name;
   string poss;
   int level;
   int help;
   int hp;
   int ac;
   int wc;

   if (!(mob = present(arg,environment(this_player()))))
   {
       notify_fail("Probe what ?\n");
       return 0;
   }
   else if (!living(mob))
   {
       notify_fail("But "+arg+" is no living !\n");
       return 0;
   }
   else if (mob == _tp)
   {
      notify_fail("You think you are equal to your victim.\n");
      return 0;
   }
   else
   {
       name = mob->query_name();
       poss = mob->query_possessive();

       if (mob->query_player())
           level = 2 * mob->query_level();
       else 
           level = mob->query_level();
      
       hp = mob->query_hp();
       if (mob->query_ac() > mob->query_n_ac())
           ac = mob->query_ac();
        else
         ac = mob->query_n_ac();
        if (mob->query_wc() > mob->query_n_wc())
            wc = mob->query_wc();
         else
            wc = mob->query_n_wc();

       write("You probe "+name+" carefully:\n\n");
       say(_tpn+" probes "+name+" carefully.\n",_tp,mob);

       if (_tpl/2 >= level)
           write("Where did the chicken go ?\n");
       else if (_tpl >= level)
           write("You think that this could be an easy opponent.\n");
       else if ( (_tpl*2) >= level )
           write("You think that this could be a really hard fight.\n");
       else if ( (_tpl*3) >= level )
           write("You think that you might lose this fight.\n");
       else 
           write("You think that this opponent is your sure death.\n");

       if (_tp->query_hp() > hp)
           write(name+" seems to be in a worse condition than you.\n");
       else if ( (_tp->query_hp() * 2 ) > hp)
           write(name+" seems to be in a better condition than you.\n");
       else 
           write(name+" seems to be in a much better condition than you.\n");

       if (_tp->query_ac() > ac)
           write(capitalize(poss)+" armour seems to be worse.\n");
       else if ( (_tp->query_ac()*2) > ac)
           write(capitalize(poss)+" armour seems to be a bit better.\n");
       else
           write(capitalize(poss)+" armour seems to be much better.\n");

       if (_tp->query_wc() > wc)
           write(capitalize(poss)+" weapons seems to be worse.\n");
       else if ( (_tp->query_wc()*2) > wc)
           write(capitalize(poss)+" weapons seems to be a bit better.\n");
       else
           write(capitalize(poss)+" weapons seems to be much better.\n");
      return 1;
    }
  return 0;
}
*/
query_sprite()
{
    return 1;
}
      
       

      
       
            
            
        
       
       

