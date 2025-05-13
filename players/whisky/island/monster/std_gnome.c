
/* std_gnome */

inherit "/obj/npc";
#include "../island.h"

int created, call_friends;

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
        created = 0;
}

void create_gnome()
{
  int lv;

  lv = query_level();

      set_alt_name("gnome");
      set_race("gnome");
      set_attacks(1+ lv/15);
      set_attacks_change(10 + lv);
      set_dodge(10+lv/3); 
      set_short(query_name()+" the Gnome");
      set_str(1 + lv/2);
      set_con(1 + lv/2);
      set_hp(60 + lv * 15);
      set_sp(80 + lv * 20);
      CO("warbag");
      CO("knife");
      add_money(random(10*lv) + (lv * lv)/3); 
      init_command("wield knife");
      init_command("wear warbag");
}

int query_dex()
{
    return (query_level()*3/2);
}

int query_int()
{
    return (query_level()*3/2);
}

int query_str()
{
    return (query_level()*3/2);
}

void help_me(object vic)
{
   object *all;
   int i, sz;

   all = filter_objects(all_inventory(environment()),"query_npc");

   for(sz=sizeof(all),i=0;i<sz;i++)
   {
       if (apply(call,all[i],"has_called_friends")==1 && all[i]!=this_object())
       {
           apply(call,all[i],"attack_object",vic);
           apply(call,all[i],"set_called_friends",1);
       }
   }
}
 
   
void init()
{
     call_friends = 0;
     if (!created)
     {
         create_gnome();
         created = 1;
     }
   ::init();
}

int attack()
{
     if (::attack() && attacker_ob && !call_friends)
     {
          call_friends = 1;
          help_me(attacker_ob);
          return 1;
     }
   return 0;
}     

int has_called_friends()
{
    return (call_friends + 1);
}

void set_called_friends(int f)
{ 
    call_friends = f;
}
