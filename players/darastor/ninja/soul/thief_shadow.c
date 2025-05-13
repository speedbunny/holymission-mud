#define RM "race/master"
#define MAX_ST 30
#define W_DODGE 100     /* weight * 100/strength max for dodge */

inherit "/obj/std_shadow";
int count;

int stat_dam(object weap) {
  object vic;
  int level;
  level = me->query_level();
  
  if (!count)
    count = 1;
  else if (count < (5 - ((level/10 > 5) ? 5 : level/10)))
    count ++;
  else
    count = 0;
  
  if (!count && (vic = me->query_attack()) && 
      random(50) < (5+((me->query_dex()+level)/4)) ){
    tell_object(me,"You slip between "+vic->query_name()+"'s defenses.\n");
    say(me->query_name()+" slips between his opponent's defenses.\n",me);
    /*    if(me->stat_dam(weap)==0)
          return (20 * (random(5)+1));  */
    return (5 * (me->stat_dam(weap)+1));
  }
  return me->stat_dam(weap);
}

varargs mixed hit_player(int dam,int kind,mixed elem) {
  string          name, pname;
  int             dex, dk, enc, i, max, wt;

  dex = me->query_dex() - this_player()->query_dex();
  /* delta dexterity */
  wt = me->query_weight();          /* what we are carrying */
  enc = wt * 100 / me->query_str();
  name = me->query_name();
  pname = this_player()->query_name();

  if (!kind || kind == 0 || kind==1 || kind == 2 || kind == 6 || kind == 7)
    dk = 0;
  if (dk || dex < 1 || enc > W_DODGE) {
    return me->hit_player(dam, kind);          /* original route */
  }

  if (! (max = RM->query_max_stat(me->query_race(), 1)) )
    max = MAX_ST;

  /* First we check if a complete dodge of the attack is possible */

  i = dex * (W_DODGE - enc) / max;      /* % possibility reduced by weight */
  if (random(100) < i) {                              /* We dodge completely */
    write(name + " dodges your attack.\n");
    say(name+" swiftly dodges the attack of "+pname+".\n",me);
    tell_object(me, "You swiftly dodge the attack of " + pname + ".\n");
    return 0;
  }

  /* It isn't possible to dodge. But maybe we can reduce the damage ? */

  i = random(100 - i) / 2 + 50;             /* Minimum: 50 % damage */
  dam = dam * i / 100;
  i = me->hit_player(dam, kind, elem);
  write(me->query_name() +" tried to dodge your attack.\n");
  if (i)
    say(me->query_name() +" tried to dodge the attack of "+ pname +".\n",me);
  tell_object(me, "You tried to dodge the attack of "+ pname +".\n");
  return i;
}

look(str) {
  string p_str;
  
  if(str){
    p_str=xtra_look(str);
    if(p_str)write(p_str);
  }
  
  if (this_player()->test_dark())
    return notify_fail("It is too dark.\n"); 
  if (!str) 
    return this_player()->mylook(0);
  else
    return (this_player()->look(str)); 
}

string xtra_look(string arg){
  object looked_at;
  string poison_level, new_arg;
  if(sscanf(arg,"at %s",new_arg)==1){
    if(looked_at=present(new_arg, environment(me))){
      if(!living(looked_at)){return 0;}
      else{
        switch(looked_at->query_poisoned()){
        case 0:{return 0;}
        case 1..5:{poison_level="barely";break;}
        case 6..10:{poison_level="very weak";break;}
        case 11..15:{poison_level="weakly";break;}
        case 16..20:{poison_level="medium";break;}
        case 21..25:{poison_level="strong";break;}
        case 26..30:{poison_level="very strong";break;}
        case 31..45:{poison_level="critical";break;}
        }
        return ("You think "+looked_at->query_name()+" is "+poison_level+
                " poisoned.\n");
      }
    }
  }
  else{return "";}
}

int thief_shadow(){ 
  return 1; 
}

object thief_object() {
  return this_object();
}        

int query_guild(){  
  if(!objectp(me)) { return 1; }
  if(me->query_testchar()){
  tell_object(me,file_name(previous_object()));
  tell_object(me,"\n");
  tell_object(me,file_name(me));
  tell_object(me,"\n");
  if(previous_object()==me) tell_object(me,"p_o()==me"); 
  if(previous_object()!=me) tell_object(me,"p_o()!=me");
  tell_object(me,"\n");
  } 
 if(me->query_level()>25&&previous_object()!=me)
      return present("thiefsoul",me)->query_disguise();
             // you can fool your friends, but you cant fool yourself!
     
  return me->query_guild();
} 
