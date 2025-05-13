inherit "obj/npc";
#include "../asgard.h"
object *group = ({ });

reset(int arg) 
{ ::reset(arg);
  if(!arg)
  { set_name("jukie");
    set_alt_name("jukie");
    set_race("berzerker");

    set_short("Jukie (Leader)");
    set_long("This is Jukie a Berzerkian patroll leader.\n");
    set_gender(1);

    load_a_chat(20,
            ({"Jukie says: Come on Berzerkers get him.\n",
              "Jukie kicks you.\n",
              "Jukie gives some secret winks to his companions.\n",
              "Jukie makes you going mad.\n",
              "Jukie starts singing his war-song.\n",
             }));

    set_level(20);
    set_attacks_change(100);
    set_attacks(3);    

    set_al(-20);
    set_aggressive(1);
    add_money(400);

    set_spell_mess1("Jukie makes a combat move");
    set_spell_mess2("Jukie hits you with his fist");
    set_chance(20);
    set_spell_dam(30);

    enable_commands();
  }
}

void init()
{ object *env;
  int i,j,k,l,flag;
  ::init();

  flag=0;  

  for(i=0,j=sizeof(group);i<j;i++)
  { if(!present(group[i],environment(TO)))
       transfer(group[i],environment(TO));
  }

  env=all_inventory(environment(TP));

  for(i=0,j=sizeof(env);i<j;i++)
  { if((env[i]->query_race()=="berzerkian_follower"))
    { for(k=0,l=sizeof(group);k<l;k++)
      { if(group[k]==env[i])
        { flag=-1;
          break;
        }
      }

      if(flag==0)
      { group= group + ({ env[i] });
        tell_room(environment(TO),"Jukie added a compannion.\n");
      }
      flag=0;
    }
  }
}   
