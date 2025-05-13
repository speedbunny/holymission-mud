inherit "obj/monster"; 

#include <lw.h>

string func,match,type;

void reset(int arg) {
    ::reset(arg);
    if(!arg)
    {
        set_name("akihito");
        set_alias("akihito shinozubi");
        set_alt_name("shinozubi");
        set_short("Akihito Shinozubi");
        set_long("Akihito Shinozubi is a tall, athletic ninja, who runs "+
          "the ninja weapon shop. He looks as though he would be a VERY "+
          "tough opponent. Only a fool or someone very brave would attack "+
          "him.\n");
        set_race("human");
        set_gender(1);
        set_al(0);
        set_size(3);
          
        set_level(90);
        set_hp(5000);
        set_str(140);
        set_dex(160);

        set_prevent_poison(1);
        set_no_steal(1);
        
        set_dead_ob(this_object());
        add_money(1000+random(2000));
   
        load_a_chat(5,
          ({
            "Akihito's face is a mask of hatred as he attacks you.\n",
            "Akihito says: Puny fool. Now I will have to kill you\n",
            "Akihito says: You dare to challenge my mastery of ninjutsu?\n",
            "Akihito concentrates hard on the fight.\n",
          })
        );
    }
}

void monster_died(object slayer)
{
    if(slayer)
    {
        shout(lw("With his last breath, Akihito Shinozubi shouts: Ninja "+
          "brothers, I am slain. Avenge yourselves on "+
          capitalize(attacker_ob->query_real_name())+".\n"));
    }
}

int run_away()
{
  return 0;
}

int detect_invis()
{
    return 1;
}

int hit_player(int dam,int kind)
{
    int dodge_switch;
    
    /* can dodge to reduce or nullify damage from physical attacks or
       int attacks */
    if(kind=0||kind=2||kind=4)
    {
        /* 25 % chance of avoiding damage altogether
           then 40 % chance of halving it by dodging
        */
        dodge_switch = random(20);
        switch(random(20))
        {
        
            case 0 .. 4 :
            
                tell_object(attacker_ob,"Akihito completely dodges your attack.\n");
                say("Akihito completely dodges "+attacker_ob->query_name()+
                  "'s attack.\n");
                return 0;
                break;
                
            case 5 .. 12 :
            
                tell_object(attacker_ob,"Akihito partially dodges your attack.\n");
                say("Akihito partially dodges "+attacker_ob->query_name()+
                  "'s attack.\n");
                return ::hit_player(dam/2,kind);
                break;
                
            default :
            
                return ::hit_player(dam,kind);
        }
    }
    else
    {
        return ::hit_player(dam,kind);
    }
}
