
/* guard assist- due to time constriants had to borrow it from Whisky */

inherit "obj/npc";
#include "/players/whisky/island/island.h"

int created, call_friends;

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
        created = 0;
}

void create_guard()
{
  int lv;

  lv = query_level();

	set_alt_name("guard");
	set_race("human");
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
	create_guard();
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
