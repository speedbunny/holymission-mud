

inherit "/obj/monster";
#include "/players/whisky/genesis/kfun/my_look.c"

#define CAP(x) capitalize(x)
#define tp this_player()
#define to this_object()
#define tpr tp->query_real_name()
#define env environment
#define SAY(x) tell_room(env(),x)

object friend;
static int counter;
object soul;
int stay;
static string petname;
mapping places;

/* prototyping */
int no_follower(object player);
int query_weight();
string short();
int do_name(string arg);
int get();
int drop();


void reset(int dog)
{
  ::reset(dog);
  if (dog) return;
     places = ([]);
     set_level(1000);
     set_ac(700);
    set_hp(30000);
     set_name("dog");
     set_gender(1);
     set_race("dog");
     set_alt_name("misty");
     soul = clone_object("/players/whisky/obj/monst_soul");
     move_object(soul,this_object());
}  


long()
{
  if (petname && friend)
     write("You see "+CAP(petname)+", "+friend->query_real_name()+"'s dog.\n");

  else 
     write("You see an intellegent black dog with bushy white eyebrows.\n");
     printf("%s",tell_health());
}

short()
{
   if (objectp(friend) && environment() == friend)
      return "Dog ["+friend->query_name()+"'s pet]";
   return "Dog";
}


int query_weight()
{
  return 4;
}


int get()
{
  if (friend == tp)
  {
      set_heart_beat(0);
      return 1;
  }
  else if (!objectp(friend))
  {
     friend = tp;
     this_object()->set_level(3 + friend->query_level()/3);
     tell_object(tp,"Your dog barks loudly.\n");
     set_heart_beat(0);
     return 1;
  } else 
      SAY(short()+" growls angrily as "+tpr+" tries to touch it.\n");
    return 0;
}


int drop()
{
   set_heart_beat(1);
   return 0;
}
heart_beat()
{
  ::heart_beat();

  if (objectp(friend) && env()!=friend && !stay)
  {
      counter = 0;
      if (env()!=env(friend))
      {
          tell_room(env(friend),"Dog trots in.\n");
          SAY("Dog trots out after his master.\n");


          move_object(to,env(friend));
      }
  } 
  else if (counter > 800) 
	 destruct(this_object());
  else 
     counter++;
    return;
}
 
init()
{
  add_action("do_name","name");
  add_action("do_kick","kick");
  add_action("fcn_command","C");  /* commanding the dog */
  add_action("fcn_kill","K");     /* killing a victim */
  add_action("fcn_stay","S");     /* staying and checking */
  add_action("fcn_crawl","crawl");
  add_action("fcn_remember","remember"); 
  add_action("fcn_forget","forget");
  add_action("fcn_places","places");
  add_action("fcn_task","command");
  add_action("fcn_eat","E");      /* eating a corpse */
  add_action("fcn_resc","R");     /* rescuing */
  add_action("fcn_drop","D");
  ::init();
}

int fcn_crawl(string arg)
{
     if (tp != friend)
         return 0;
     if (objectp(friend) && environment()==friend)
        return 0;

    stay = 1;
    command(arg);
    my_look(0);
    stay = 0;
    return 1;
}
    
int fcn_remember(string arg)
{
    if (!arg || tp!=friend) return 0;
  
    if (sizeof(m_indices(places)) > 10)
    {
       SAY("Dog looks bewildered.\n");
       return 1;
    }
    if (member(places,arg)!=1)
        places = places + ([arg:file_name(environment(friend))]);

    SAY("Dog wags his tail excitedly.");
    return 1;
} 
        
int fcn_forget(string arg)
{
    if (!arg || tp!=friend) return 0;
    
    if (member(places,arg)==1)
        places = m_delete(places,arg);

     SAY("Dog wags his tail excitedly.");

    return 1;
} 

int fcn_task(string arg)
{
  string where, what;

    if (!arg || sscanf(arg,"%s %s",where,what)!=2 || tp!=friend) 
        return 0;
    else if (member(places,where)!=1)
    {
        say(tp->query_name()+" gives his dog an order.\n");
        SAY("Dog shrugs helplessly.\n");
        return 1;
    }
    call_other(places[where],"???");
    if (find_object(places[where]))
    {
       SAY("Dog trots out.\n");
       stay = 1;
      tell_room(places[where],"Dog trots in.\n");
       move_object(this_object(),places[where]);
       my_look(1);
       command(what);
       stay = 0;
    }
  return 1;
}
    
int fcn_places()
{
   int i, sz;
   string *arr;

    if (tp!=friend) return 0;

    arr = m_indices(places);
    sz = sizeof(arr);   

    write("Places:\n\n");

    for (i = 0; i < sz ; i++) 
         write(arr[i]+"\n");
    return 1;
}
    

int fcn_drop(string arg)
{
  object *inv,ob;
  object money;
  int i, sz;

  if (tp!=friend) return 0;

  say(tp->query_name()+" gives his dog an order.\n");
  if (!arg || arg=="all")
  {
      inv = all_inventory();
      for(sz = sizeof(inv),i=0;i<sz;i++)
      {
          if (stringp(inv[i]->query_name()))
          {
              move_object(inv[i],environment());
              tell_room(environment(),
              "Dog drops "+inv[i]->query_name()+".\n");
          }
       }
      return 1;
    }
     else if (arg=="coins" && query_money())
     {
         money = clone_object("/obj/money");
         money->set_money(query_money());
         move_object(money,environment());
        add_money(-query_money());
        SAY("Dog drops some coins.\n");
        return 1;
     }
    if (ob=present(arg,this_object()))
    {
        tell_room(environment(),
        "Dog drops "+arg+".\n");
        transfer(ob,environment());
     }
    return 1;
 }


int fcn_resc(string arg)
{
   object vic;

   if (arg || this_player()!=friend) 
      return 0;
   else if (objectp(friend->query_attack()) && vic!=this_object() && !stay)
   {
     if (env(friend) == env())
     {
       vic = friend->query_attack();
       write("Your dog jumps into the fight to rescue you !\n");
       say(friend->query_name()+"' dog jumps into the fight !\n");
       attack_object(vic);
       vic->change_attacker(this_object());
    }
     return 1;
   }
  return 0;
}

int fcn_eat()
{
  object corpse;

  corpse=present("corpse",env());

  if (corpse && !living(corpse))
  {
   SAY("Dog devours the corpse.\n");
   destruct(corpse);
   if (query_hp() < query_max_hp())
  heal_self( query_level() + (query_max_hp() - query_hp()) / 3);
   }
  return 1;
}


int fcn_stay()
{
   if (this_player()!=friend) return 0;

   if (!stay)
   {
     SAY("Dog sits down and rests.\n");
     stay = 1;
	 return 1;
   }
   SAY("Dog stands up.\n");
   stay = 0;
   return 1;
}

int fcn_kill(string whom)
{
  object mob;

  if (stringp(whom))
  mob = present(whom,env());
  else {
    write("Your dog looks confused.\n");
    return 1;
  }

 if (mob && living(mob) && this_player()==friend)
 {
	if (interactive(mob) && mob->query_level() < 12)
	{
           friend->catch_tell("Your dog dislikes your attempt.\n");
	   return 1; 
    }

        SAY("A dog bites "+mob->query_name()+".\n");
	attack_object(mob);
	change_attacker(mob);
 }
return 1;
}

  
int fcn_command(string arg)
{
   if (!arg) return 0;
   if (this_player()==friend)
   {
      command(arg);
      set_heart_beat(1);
   }
   return 1;
}

void catch_tell(string arg)
{
   if (friend && interactive(friend) && stay)
           tell_object(friend,"dog#"+arg);
}

	   
int do_name(string arg)
{
 string h;
 if (sscanf(arg,"dog %s",h)!=1)
     return 0;
 else if (tp!=friend) 
 {
    notify_fail("Only Haplo can control this dog.\n");
   return 0;
 }  
   petname = h;
   set_alt_name(petname);
  write("Your dog is now called "+petname+".\n");
  return 1;
}
 
int no_follower(object player)
{
  object ofriend;
  
  if (ofriend = present("dog",player) && ofriend->query_follower()==tp)
      return 0;
  else if (ofriend = present("mycat",env(player)) && 
           ofriend->query_follower()==tp) 
     return 0;
     return 1;
}
     
hit_player(damage,kind)
{
  if (kind == 0 || kind == 7 || kind == 5)
  {
    switch(damage)
    { 
     case 0..10:
         return ::hit_player(damage/2,kind);
     case 11..120:
         return ::hit_player(damage/4,kind);
     default:
          return ::hit_player(damage/8,kind);
     }
   }
  return ::hit_player(damage,kind);
}
        
query_hit_msg(dam,name,att,def)
{
  string how, str;

   switch(random(2))
   {
     case 0:      
       how = " with it's right claw";
       break;
     case 1:
       how = " with it's left claw";
       break;
    }
   switch(dam)
   {
    case 0:
      str = "misses";
      break;
    case 1:
      str = "tickles";
      break;
    case 2..4:
      str = "gazes";
      break;
    case 5..10:
      str = "hits";
      break;
    case 11..15:
      str = "smashes";
      break;
    default:
      str = "pounds";
      break;
    } 

   return ({
   "",str+" you "+how+".",str+" "+name+how+"." 
    });
}

attack()
{
  if (::attack())
  {
  if (friend && attacker_ob==friend)
  {
    friend->catch_tell("Your cat flees head over heals.\n");
	destruct(to);
  }
  if (random(100) < 80)
      ::attack();
     return 1;
  }
  return 0;
}

int do_kick(string arg)
{
   if ((arg!="dog" && arg!=petname) || tp!=friend)

      return 0;
   write("Your dog leaves you.\n");
   destruct(this_object());
   return 1;
}
add_poison()
{
      return 0;
  }
int query_familiar()
{
    return 1;
}
// for storing the object
   query_value()
   {
       return 1;
   }
