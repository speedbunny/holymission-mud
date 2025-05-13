/*  fighter sledge !!!!! */
// Mangla: Fixing some syntax and sissy stuff
// Damn right a fighter.  Fighters do not "bounce" around etc

#define _tp  this_player()
#define _tpn _tp->query_name()
#define PARTNER "/players/portil/guild/room"
#define MAXPR  95 
#define _wiz "/players/portil/"
#define _to  this_object()

inherit "/obj/npc";
int chk, is_berz;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("Fighter Sledge");
       set_living_name("sledge");
       set_alt_name("sledge");
       set_short(query_name());
       set_level(85);
       set_race("human");
       set_size(3);
       set_gender(1);
       load_chat(5,
       ({ 
        "Fighter Slege says: Type practice to train your skills with me.\n",
        "Fighter Sledge says: My skills improve your damage !\n",
        "Fighter Sledge says: Type 'practice' to see your skills.\n",
        "Fighter Sledge says: Type 'practice <skill>' and I will teach you.\n",
        "Fighter Sledge says: Use 'help weapontype' for more information!\n",
        "Fighter Sledge grins evily.\n",
       }));
       load_a_chat(9,
       ({
        "Fighter Sledge growls: You had better leave now or\nI will be forced to kill you!\n",
"Fighter Sledge growls: I will cut you into so many pieces,\n your mother will not even recognize you.\n",
        "Fighter Sledge growls: Here let me teach you some lessons!\n",
        "Fighter Sledge roars in anger.\n",
       }));
       set_long(
       "You see a big, muscular Human Fighter. He is well known\n"+
       "as one of the best fighters in this world. With his grinning\n"+
       "face he looks at you like he would say:\n\n"+
       "             Get some 'practice' weakling !\n");
       set_spell_mess1("Fighter Sledge attacks with his shield!\n");
       set_spell_mess2("Fighter Sledge bashes you with his shield.\n");
       set_chance(70);
       set_dead_ob(this_object());
       set_spell_dam(90); 
       set_attacks(3);
       set_attacks_change(90);
       set_no_steal();
       add_money(9000 + random(7000));
       move_object(clone_object("/players/llort/secure/thammer"),
       this_object());
       move_object(clone_object("/players/llort/animals_stuff/diring"),
       this_object());
       move_object(clone_object("/players/whisky/obj/arms"),
       this_object());
       move_object(clone_object("/players/whisky/obj/scales/steel_scale"),
       this_object());
       move_object(clone_object("/players/whisky/obj/tower_shield"),
       this_object());
       move_object(clone_object("/players/uglymouth/vikings/items/vikhelm"),
       this_object());
       init_command("wield hammer");
       init_command("wear arms");
       init_command("wear dragonhide");
       init_command("wear shield");
       init_command("wear helm");
       init_command("wear ring");
       chk = 1;
       is_berz = 0;
      }
}

int attack()
{
    ::attack();
    if (!random(2) && attacker_ob && environment()==environment(attacker_ob)
        && !is_berz)
    {
       tell_room(environment(),"Fighter Sledge goes berzerk !\n");
       is_berz = 1;
       set_attacks(5);
       call_out("remove_berzerk",200);
       return 1;
    }
  return 0;
}

void remove_berzerk()
{
     is_berz = 0;
}
    
        
int query_str()
{
    return 130;
}

void init()
{
    ::init();
    add_action("do_practice","practice");
    add_action("do_practice","pr");
}

/* practice */

int do_practice(string arg)
{
   int cost, sklev;


    if (_tp->query_guild() != 3)
    {
        
        notify_fail("Fighter Sledge tells you:\n"+
        "You are no Fighter, go home !\n");
        return 0;
    }
    else if (catch(call_other(PARTNER,"???")))
    {
       notify_fail("Fighter Sledge tells you:\n"+
       "I have no time for you, go home !\n");
       return 0;
    }
    else if (!arg)
    {
       write("Fighter Sledge tells you: "+
             "Here are the skills I can teach you:\n");
       tell_object(this_player(),PARTNER->list_skills(_tp,2));
       return 1;
    }
    else if (!(sklev=PARTNER->query_skill(_tp,"fighter_"+arg)) )
    {
        notify_fail("Fighter Sledge tells you:\n"+
                    "This is not a skill I know !\n");
        return 0;
     }
     else if (_tp->query_money()<(cost=PARTNER->query_cost(_tp,"fighter_"+arg)))
     {
         notify_fail("Fighter Sledge tells you:\n"+
         "Further practice in "+arg+" would cost you "+
                     to_string(cost)+" coins.\n");
         return 0;
      }
      else if (sklev > (MAXPR - 20) && 
               this_player()->query_property("fighter_legend")==-1)
      {
           notify_fail("Fighter Sledge tells you:\n"+
                 "You have to be a Legend that I'll teach you more !\n");
           return 0;
        }
      else if (sklev >= MAXPR)
      {
          notify_fail("Fighter Sledge tells you:\n"+
                      "Sorry, but I can't teach you more, you now nearly "+
                      "as good as i am !\n");
           return 0;
      }
      else 
      {
         if (chk && sklev > random(MAXPR + _tp->query_int() + _tp->query_dex()))
         {
             write("You practice your "+arg+" skill with Fighter Sledge for "+
                   to_string(cost)+" gold coins.\n");
             say("Fighter Sledge shows something to "+_tp->query_name()+"\n",_tp);
             _tp->add_money(-cost);
             write("You are confused.\n");
             say(_tp->query_name()+" looks confused.\n");
             chk--;
             return 1;
         }
         if (PARTNER->raise_skill(_tp,"fighter_"+arg,1))
         {
             write("You practice your "+arg+" skill with Fighter Sledge for "+
                   to_string(cost)+" gold coins.\n");
             say("Fighter Sledge shows something to "+_tp->query_name()+"\n",_tp);
             _tp->add_money(-cost);
             chk=1;
          }
          else
          {
             write("Oops, Fighter Sledge made a mistake. He seems to tired to teach.\n");
             write("You pay nothing.\n");
          }
      }
    return 1;
}


int monster_died(object mob)
{
   object ob;

   if (!this_player()->query_immortal())
   {
   shout(this_player()->query_name()+
   " sucessfully challenged Fighter Sledge !\n");
   }

   if (ob)
       destruct(ob);
  return 0;
}

int add_poison(int x)
{
    return (x/30);
}
int run_away()
{
    return 1;
}
