#include "/players/exos/defs.h"
static string _type;
static object me;      

int start_shadow(object who,int time,string type) {
   if (objectp(who) && living(who) && intp(time) && strlen(type)) {
      _type=type;
      if (CO(who,type)) {
         TELL(who,"You are already using that shadow.\n");
         return 2;  
      }
      else {
         shadow(who,1);
         me=who;
         if (time > 0) CO("end_shadow",time,TO);
         return 1;
      }
   }
   return 0;
}

void end_shadow(object ob) DEST(ob); 

int shadow_time() return(find_call_out("end_shadow"));
 

