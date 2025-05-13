#include "/players/sauron/guild/include/functions.c"

int start_shadow(object who,int time,string type) {
  if(objectp(who) && living(who) && intp(time) && strlen(type)) {
    if(call_other(who,type)) {
      destruct(TO);
      return 2;
    }
    else {
      shadow(who,1);
      if(time>0)
        call_out("end_shadow",time);
      return 1;
    }
  }
  return 0;
}

void end_shadow() {
  destruct(TO);
}

int shadow_time() {
  return(find_call_out("end_shadow"));
}
