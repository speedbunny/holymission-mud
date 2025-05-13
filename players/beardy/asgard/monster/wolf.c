inherit "obj/npc";
#include "../asgard.h"

#define TOAN this_object()->query_attack()->query_real_name()
#define herbs_max 6
int num;
object herb;

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("wolf");
    set_alt_name("wolf");
    set_race("wolf");

    set_short("killer-wolf");
    set_long("This is the famous killer-wolf. He swallows\n"+
             "everything that is present.\n");
    set_gender(1);

    set_level(60);
    set_attacks_change(100);
    set_attacks(4);    

    set_al(-300);
    set_aggressive(0);

    set_spell_mess1("");
    set_spell_mess2("");
    set_chance(40+random(30));
    set_spell_dam(30+random(20));
    set_heart_beat(1);

   for(num=0;num<herbs_max;num++)
    { switch(random(3))
      { case 1 : herb=clone_object("/players/beardy/asgard/obj/blueherbs"); break;
        case 2 : herb=clone_object("/players/beardy/asgard/obj/greenherbs"); break;
        default: herb=clone_object("/players/beardy/asgard/obj/herbs"); break;
      }
      move_object(herb,TO);
    }

  }
}

int attack()
{ if(::attack() && TO->query_attack())
  { switch(random(6))
    { case 0 : tell_room(environment(TO),"The wolf attacked "+TOAN+" very hard.\n");
               TP->reduce_hit_point(-random(20));
               return 1;
               break;
      case 1 : tell_room(environment(TO),"The wolf threw his teeth into "+TOAN+"'s flesh.\n");
               TO->query_attack()->reduce_hit_point(-random(40));
               TO->query_attack()->add_poison(random(20));
               return 1;
               break;
      case 2 : if(random(3)==0)
               { write("The wolf turned round and swallowed you.\n");
                 move_object(TO->query_attack(),TO);
                 TO->query_attack(0);
                 return 1;
               }
               break;
      case 3 : write("The wolf missed you.\n");
               return 1;
               break;
    }

  }
  return 0;
}

void heart_beat()
{ int i,j;
  object *env;

  ::heart_beat();
  if(!TO->query_attack())
  { if(random(3)==0)
      tell_room(environment(TP),"The great wolf hurrels in a circle.\n");
 
   env=all_inventory(environment(TP));
    for(i=0,j=sizeof(env);i<j;i++)
    { if(env[i]->query_player()==1)
        if((random(TP->query_dex()/4)==0)&&(env[i]->query_wizard()==0))
        { tell_object(env[i],"You are swallowed by the fericious killer-wolf.\n");
          move_object(env[i],TO);
        }
    }

    switch(random(15))
    { case 1 : command("west",TO);break;
      case 2 : command("north",TO);break;
      case 3 : command("east",TO); break;
      case 4 : command("south",TO); break;
      case 5 : command("northwest",TO); break;
      case 6 : command("northeast",TO); break;
      case 7 : command("southeast",TO); break;
      case 8 : command("southwest",TO); break;
     case 9 : command("out",TO); break;
     case 10: command("enter",TO); break;
    }
  }
}
