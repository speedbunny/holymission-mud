inherit "/obj/monster";
#include "/players/whisky/genesis/kfun/my_look.c"
 
#define CAP(x) capitalize(x)
#define tp this_player()
#define to this_object()
#define tpr apply(call,tp,"query_real_name")
#define env environment
#define SAY(x) tell_room(env(),x)
 
object friend;
static int counter;
object soul , curse ;
int stay;
static string petname;  
mapping places;
closure call;
  
/* prototyping */  
int no_follower(object player);
int query_weight();
string short();   
int do_name(string arg);
int get();
int drop();
     
void reset(int cat)
{
  ::reset(cat);
  if (cat) return;
     
     places = ([]);
     call = #'call_other;
     set_level(8);
     set_name("K");
     set_gender(1);
     set_race("Cathan");
     soul = clone_object("/players/whisky/obj/monst_soul");
     move_object(soul,this_object());
}
 
  
int query_quest_item() {
    return 1;
}
 
long()
{
  if (petname && friend)
     write("You see "+CAP(petname)+", "+apply(call,friend,"query_real_name")
          +"'s friend K.\n");
  else
     write("K is just hanging around looking for Alex.\n");
     printf("%s",tell_health());
}    
     
short()
{
   if (objectp(friend) && environment() == friend)
      return "K ["+friend->query_name()+"'s friend]";
   return "K";
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
     apply(call,to,"set_level",1 + apply(call,friend,"query_level")/3);
     tell_object(tp,"K smiles at you.\n");
     set_heart_beat(0);
     return 1;
  } else
     if (this_player() != this_object())
      SAY(short()+" makes a step aside as "+tpr+" tries to take it.\n");
    return 0;
}
  
     
int drop()
{
   set_heart_beat(1);
   return 0;
} 
  
void heart_beat()
{
  ::heart_beat();
   
  if (objectp(friend) && env()!=friend && !stay)
  {
      counter = 0;
      if (env()!=env(friend))
      {
          tell_room(env(friend),"K strides in.\n");
          SAY("K strides out.\n");
          if (transfer(to,env(friend)))
              stay = 1;
      }
  }
  else if (counter > 800)
         destruct(this_object());
  else
     counter++;
    return;
}
void init()
{ 
  add_action("do_name","name");
  add_action("do_kick","kick");
  if (this_player() && environment()!=this_player())
      add_action("fcn_command","C");  /* commanding K */
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
    my_look(1);
    stay = 0;
    set_heart_beat(1);
    return 1;
}
  
int fcn_remember(string arg)
{
    if (!arg || tp!=friend) return 0;
  
    if (sizeof(m_indices(places)) > 10)
    {
       SAY("K looks a little confused.\n");
       return 1;
    }
    if (member(places,arg)!=1)
        places = places + ([arg:file_name(environment(friend))]);
     
    SAY("K agrees.\n");
    return 1;
}

int fcn_forget(string arg)
{
    if (!arg || tp!=friend) return 0;
    
    if (member(places,arg)==1)
        places = m_delete(places,arg);
 
    SAY("K agrees.\n");
    return 1;
}   
int fcn_task(string arg)
{
  string where, what;
       
    if (!arg || sscanf(arg,"%s %s",where,what)!=2 || tp!=friend)
        return 0;
    else if (member(places,where)!=1 || what=="score")
    {
        say(apply(call,tp,"query_name")+" gives K an order.\n");
        SAY("K shrugs helplessly.\n");
        return 1;
    }
    call_other(places[where],"???");
    if (find_object(places[where]))
    {
       SAY("K strides out.\n");
       stay = 1;
       tell_room(places[where],"K strides in.\n");
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
 
  say(apply(call,tp,"query_name")+" gives K an order.\n");
  if (!arg || arg=="all")
  {
      inv = all_inventory();
      for(sz = sizeof(inv),i=0;i<sz;i++)
      {
          if (stringp(apply(call,inv[i],"query_name")))
          {
               command("remove "+inv[i]->query_name(),this_object());
               command("unwield "+inv[i]->query_name(),this_object());
              transfer(inv[i],environment());
              tell_room(environment(),
              "K drops "+apply(call,inv[i],"query_name")+".\n");
          }
       }
      return 1;
    }
     else if (arg=="coins" && query_money())
     {
         money = clone_object("/obj/money");
         apply(call,money,"set_money",apply(call,to,"query_money"));
         move_object(money,environment());
         add_money(-query_money());
         SAY("K drops some coins.\n");
        return 1;
     }
    if (ob=present(arg,this_object()))
    {
        tell_room(environment(),
        "K drops "+arg+".\n");
        transfer(ob,environment());
     }
    return 1;
 }
              
    
int fcn_resc(string arg)
{
   object vic;
  if (arg || this_player()!=friend)
      return 0;
   else if (objectp(apply(call,friend,"query_attack"))
            && vic!=this_object() && !stay)
   {
     if (env(friend) == env())
     {
       vic = apply(call,friend,"query_attack");
       write("K jumps into the fight to rescue you !\n");
       say(apply(call,friend,"query_name")+
           "' friend K jumps into the fight !\n");
       attack_object(vic);
       apply(call,vic,"change_attacker",to);
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
   SAY("K devours the corpse.\n");
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
     SAY("K sits down and rests.\n");
     stay = 1;
         return 1;
   }
   SAY("K stands up.\n");
   stay = 0;
   return 1;
}
   
int fcn_kill(string whom)
{
  object mob;
       
  if (stringp(whom))
  mob = present(whom,env());
  else {
    write("K looks a little confused.\n");
    return 1;
  }
 
 if (mob && living(mob) && this_player()==friend)
 {  
        if (interactive(mob) && mob->query_level() < 5)
        {
           tell_object(friend,"K dislikes your attemt.\n");
           return 1;
    }
        SAY("K hits "+mob->query_name()+".\n");
        attack_object(mob);
        change_attacker(mob);
 }
return 1;
}  
 
 
int fcn_command(string arg)
{      
  
 
    string h;
    
   if (!arg) return 0;
   if (sscanf(arg,"shout %s",h)==1)
   {
       write("K says: "+h+"\n");
       say("K says: "+h+"\n");
       return 1;
   }
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
           tell_object(friend,"K#"+arg);
}
       
int do_name(string arg)
{
 string h;
 if (sscanf(arg,"K %s",h)!=1)
     return 0;
 else if (tp!=friend)
 {
   notify_fail("You do not command K.\n");
   return 0;
 }  
   petname = h;
   set_alt_name(petname);
  write("K is now called "+petname+".\n");
  return 1;
}   
   
int no_follower(object player)
{
  object ofriend;
 
  if (ofriend = present("K",player) &&  
                apply(ofriend,"query_follower")==tp)
      return 0;
  else if (ofriend = present("mycat",env(player)) &&
           apply(ofriend,"query_follower")==tp)
     return 0;
     return 1;
}
     
hit_player(damage,kind)
{ 
  if (kind == 0 || kind == 7 || kind == 5)
  {
    switch(damage)
    {
     case 0..120:
         return ::hit_player(damage/2,kind);
     default:
          return ::hit_player(damage/4,kind);
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
    case 2..4:
      str = "grazes";
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
   tell_object(friend,"K tactifally leaves the fight.\n");
        destruct(to);
  }
  if (random(100) < 80)
      ::attack();
     return 1;
  }
  return 0; 
}
      
// finding even a hidden player
detect_invis()
{
   return 1;
}
 
// for storing the object
query_value()
{
   return 1;
}  
  
