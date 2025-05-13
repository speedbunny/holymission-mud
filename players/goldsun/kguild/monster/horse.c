/*         H O R S E           version 1.2  made by Goldsun && Whisky */

inherit "/obj/monster";

#define CAP(x) capitalize(x)
#define tp this_player()
#define to this_object()
#define tpr tp->query_real_name()
#define env environment
#define SAY(x) tell_room(env(),x)

object friend;
object soul;
static int counter;
int stay;
static string petname;
status is_mounted;

/* prototyping */
int query_weight();
string short();
int do_name(string arg);
int get();

void reset(int horse)
{
  ::reset(horse);
  if (horse) return;
     set_level(8);
     set_name("horse");
     set_race("myhorse");
     soul = clone_object("/players/whisky/obj/monst_soul");
     move_object(soul,to);
     is_mounted=0;
     set_dead_ob(to);
}  


long()
{
  if (petname && friend)
     write("You see "+CAP(petname)+", "+friend->query_real_name()+"'s horse.\n");
  else 
     write("You see a cute green-eyed, brown horse.\n");
  if (is_mounted) write("It is rode by "+friend->query_name()+".\n");
     printf("%s",tell_health());
}

short()
{
  if (friend)
      return name+" ["+CAP(friend->query_real_name())+"'s horse]";
  else 
     return "A horse"; 
}

/* for test */
void rescue()
{
    object vic;

      if (objectp(friend) && env(friend) == env() &&
          objectp(vic = friend->query_attack()) && vic != to)
      {
          to->attack_object(vic);
          vic->change_attacker(to);
      }
}

heart_beat()
{
  ::heart_beat();

/*  if (is_mounted==1) rescue();   */ /* auto rescue */
  if (objectp(friend) && env()!=friend && !stay)
  {
      counter = 0;
      if (env()!=env(friend) )
      {  if (is_mounted==0)
         {
          tell_room(env(friend),"Horse arrives.\n");
          SAY("Horse leaves.\n");
         }
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
  ::init();

  add_action("do_name","name");
  add_action("do_kick","kick");
  add_action("fc_mount","mount");
  add_action("fcn_dismount","dismount");
  add_action("do_owner","tame");
  add_action("do_rescue","rescue");
  add_action("fcn_command","comm");  /* commanding the horse */
  add_action("fcn_stay","stay");     /* staying and checking */
}


int fc_mount(string str){
object shdh;

 if (str=="horse" && this_player()==friend){
  if (!is_mounted)
  {
    shdh=clone_object("/players/goldsun/guild/obj/horse_shad");
    shdh->start_shadow(this_player(),0,"horse_shad");
    SAY(CAP(tpr)+" mounts his horse.\n");
    is_mounted=1;
   }
   else{
    write("But you are already on your horse.\n");
   }
  return 1;}
 else{
  if (this_player() !=friend){
   SAY("A horse gets rid of "+tp->query_name()+" as "+tp->query_pronoun()+
       " tries to mount it.\n");
   return 1;
  }}
 }


int fcn_dismount(string str){
 
 if (str=="horse" && this_player()==friend){
  if (is_mounted){
    if (friend->horse_shad()){
       friend->end_shadow(friend->query_horse_shad());
    }
    is_mounted=0;}
   else write("You aren't on your horse.\n");
  }
  else write("Dismount what ?\n");
 return 1;
}

int do_rescue()
 {
  if (this_player()==friend )
   {
      rescue();
      return 1;
/*    write("But you are not on your hourse. The horse neighs.\n");
    return 1;   this was for rescuing only if is_mounted */
   }
 return 0;
}

int do_owner(string str){
 if (str=="horse")
  if (friend==tp){
   write("This horse is your.\n");
   return 1;
   }
  else if (!objectp(friend)){
   friend=tp;
   is_mounted=0;
   this_object()->set_level(5+friend->query_level()/2);
   tell_object(tp,"Your horse neighs happily.\n");
   return 1;}
 else SAY("A horse gets rid of "+tpr+" as "+tp->query_pronoun()+
     " tries to tame it.\n");
  return 1;
 }
 

int fcn_stay()
{
   if (this_player()!=friend) return 0;

   if (!stay)
   {
     SAY("horse stops move.\n");    
     stay = 1;
	 return 1;
   }
   SAY("horse starts follow his owner.\n");    
   stay = 0;
   return 1;
}

  
int fcn_command(string arg)
{
   if (this_player()==friend)
          command(arg,to);
   return 1;
}

void catch_tell(string arg)
{
   if (friend && interactive(friend) && stay)
	   tell_object(friend,"horse#"+arg);
}

	   
int do_name(string arg)
{
 string h;
 if (sscanf(arg,"horse %s",h)!=1)
     return 0;
 else if (tp!=friend) 
 {
   notify_fail("You are not the owner of this horse.\n");
   return 0;
 }  
  petname = h;
  write("Your horse is now called "+petname+".\n");
  return 1;
}

hit_player(damage,kind)
{
  if (kind==7 || kind==5)
  {
    switch(damage)
    { 
     case 0..20:
         return ::hit_player(damage/2,kind);
     case 21..80:
         return ::hit_player(damage/3,kind);
     case 81..240:
          return ::hit_player(damage/4,kind);
     default:
         return ::hit_player(damage/20,kind);
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
       how = " with it's front right hoof";
       break;
     case 1:
       how = " with it's front left hoof";
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
      str = "kicks";
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
  if (friend && attacker_ob==friend)
  {
    friend->catch_tell("Your horse flees head over heals.\n");
          if (friend->horse_shad()){
             friend->end_shadow(friend->query_horse_shad());
          }
	
	destruct(to);
  }
  if (random(100) < 12)
      attack();
  return ::attack(); 
}

int do_kick(string arg)
{
   if ((arg!="horse" && arg!=petname) || tp!=friend)
      return 0;
   if (is_mounted){
    write("Your horse cannot to leave you because you are on it.\n");
    return 0;
    }
   write("Your horse leaves you.\n");
   destruct(this_object());
   return 1;
}

monster_died(object ob)
{
   if (friend->horse_shad()){
       friend->end_shadow(friend->query_horse_shad());
   }
}
