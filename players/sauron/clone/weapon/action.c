#ifndef __ACTION_C__

#define __ACTION_C__

#include "weapon_action.h"
#include "weapon_class.h"
#include "weapon_defs.h"
#include "weapon_log.h"
#include "weapon_magic.h"
#include "weapon_name.h"
#include "weapon_size.h"

/* USERDOC:
set_wield_func
Function: set_wield_func(o)
Examples: set_wield_func(this_object())
See also: set_hit_func

If this function is used, wield() will be called in 'o' when the weapon is
wielded. wield() will have this object as an argument. If wield returns
0, then the weapon will not be wielded.
*/

void set_wield_func(object ob) {
  if(objectp(ob))
    wield_func=ob;
}

int wield(string str) {
  int *where,i,counter;

  if(!str || TO!=present(str,TP))
    return 0;

  if(ENV()!=TP) 
    return 0;

  if(TP->query_ghost()) {
    write("You fail.\n");
    say(TPN+" failed to wield "+short_desc+".\n");
    return 1;
  }

  if(wielded) {
    write("You already wield the "+str+"\n");
    return 1;
  }

  i=weap_size-(int)TP->query_size();
  if(i>1 || i<-1) {
    write("The "+name_of_weapon+" is too "+(i>0?"large":"small")
         +" for you to wield.\n");
    return 1;
  }

  if(class_level>MAX_WEAP_CLASS || magic_level>MAX_MAGIC_LVL)
    log_weapon("wield");

  if(wield_func)
    if(!wield_func->wield(TO)) 
      return 1;

  if(two_handed || i!=0)
    where=(int *)TP->wield(TO,2);
  else 
    where=(int *)TP->wield(TO,1);

  if(!where || !sizeof(where)) {
    write("You fail to wield the "+name_of_weapon+".\n");
    return 1; 
  }

  wielded_by=TP;
  update_wt();

  str="You wield the "+name_of_weapon+" in your ";
  str+=(string)TP->get_hand_name(where[0]);
  where_wielded=(string)TP->get_hand_name(where[i]);
  counter=sizeof(where);

  for(i=1;i<counter;i++) {
    str+=" and "+(string)TP->get_hand_name(where[i]);
    where_wielded+=" & "+(string)TP->get_hand_name(where[i]);
  }
  if(counter>1) {
    str+=" hands\n";
    where_wielded+=" hands";
  }
  else {
    str+=" hand\n";
    where_wielded+=" hand";
  }
  wielded=1;
  _do_modify(1);
  write(str);
  return 1;
}

// called from living, do not change !!!
int un_wield() {
  if(wielded) {
    wielded=0;
  }
  return 1;
}

int do_unwield(string what) {
  if(!what || TO!=present(what,TP))
    return 0;

  else if(wielded) {
    if(!wielded_by->stop_wielding(TO))
      wielded=1;          // could be removed by living, so set it again
    else {
      wielded=0;
      tell_object(wielded_by,"You unwield the "+name_of_weapon+".\n");
      say(CAP(TPN)+" unwields "+name_of_weapon+".\n");
      _do_modify(-1);
      wielded_by=0;
    }
    return 1;
  }
  else
    return 0;
}

/* USERDOC:
query_wielded
Function: i=query_wielded()
Examples:
See also: 

This function returns whether the weapon is wielded or not. 0 = not
wielded, and 2 returns something else.
*/

int query_wielded() {
  return wielded;
}

void init() {
  add_action("wield","wield");
  add_action("do_unwield","unwield");
//  add_action("do_unwield","remove"); // Sauron: Remove a weapon?
}

#endif // __ACTION_C__
