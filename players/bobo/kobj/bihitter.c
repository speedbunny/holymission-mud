/* BH : bi/hitter */
/* You can inherit it, if you want */

#define env	environment
#define TP	this_player()
#define TO	this_object()
#define SAY(x)  tell_room(env(tp),x)

inherit "obj/weapon";
object tp;
string second_hit;

reset(arg) { 
  ::reset(arg);
  if (arg) return;
  second_hit=0;
}

init() {
  ::init();
}

hit(attacker) {
int tmp;
  
  tmp=::hit(attacker);
  set_heart_beat(1);
  return tmp;
}


heart_beat() {
object enmy;

   
   if ((enmy=tp->query_attack()) && env(tp)==env(enmy)) {
     if(second_hit) SAY(wielded_by->query_name()+" "+second_hit);
     tp->attack();
   } 
   else set_heart_beat(0);
}
  
wield(str) {
int r;
 
  if (r=::wield(str)) {
     tp=TP;
  } 
  return r;
}

set_second_hit(s) { second_hit=s; }


