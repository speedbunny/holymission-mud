/* BH : bi/hitter */

#define env	environment
#define TP	this_player()
#define TO	this_object()
#define SAY(x)  tell_room(env(tp),x)
#define DBG(x)	tell_room("room/church",x)

inherit "obj/weapon";
object tp;

reset(arg) { 
  ::reset(arg);
  if (arg) return;
  set_id("bh");
  set_class(18);
}

init() {
  ::init();
}

hit(attacker) {
int tmp;
  
/*  DBG("hit !\n"); */ 
  
  tmp=::hit(attacker);
  set_heart_beat(1);
  return tmp;
}

wield(str) {
int r;
 
  if (r=::wield(str)) {
     tp=TP;
     write("The sharpness of your Bh feels reassuring.\n");
  } 
  return r;
}

heart_beat() {
object enmy;

/*   DBG("heart beat\n"); */
   
   if ((enmy=tp->query_attack()) && env(tp)==env(enmy)) {
     SAY("Da hast noch was, du Schwein !!!\n");
     tp->attack();
   } 
   else { set_heart_beat(0); DBG("heart beat off\n"); }
}
  
