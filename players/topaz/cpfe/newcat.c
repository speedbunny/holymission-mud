inherit"obj/treasure";

#include "/players/exos/defs.h"
   object aimedat, there, here, item, ob;
   string name;
   int LOADED, READIED, uses, nobreak, dmg;
   int i, charged;

reset(arg) {
   ::reset(arg);
   if(arg) return;
  
   set_id("trebuchet");
   set_short("A battered trebuchet");
   set_long("A trebuchet is a long lever, ending in a sling on one end\n"+
            "and a massive counter-weight on the other end.  A windlass\n"+
            "cranks the sling-end down to be loaded.  A lever next to the\n"+
            "windlass releases the hold, firing the trebuchet.  A large\n"+
            "wheel rotates the trebuchet for aiming.\n");
   uses=random(10)+1;
   nobreak=0;LOADED=0;READIED=0;dmg=0;
   charged=0;
}

init() {
   ::init();
   AA("_repair","repair");
   AA("_ready","ready");
   AA("_ready","cock");
   AA("_arm","arm");
   AA("_target","target");
   AA("-target","aim");
   AA("_fire","fire");
   AA("_turn","turn");
   AA("_pull","pull");
}
   
get() {
   write("It is secured to the ground.\n");
   say(TPN+" tried to take the trebuchet.\n");
   return 0;
}

_repair(arg) {
   object rband;
   if (!arg || arg!="trebuchet") return 0;
   if (uses) {
      write("The trebuchet is not broken!\n");
      return 1;
   }
   rband=present("rubber_band",TP);
   if (!rband) {
      write("What are you going to repair the trebuchet with?\n");
      return 1;
   }
   write("You repair the trebuchet.\n");
   say(TPN+" repairs the trebuchet's cord.\n");
   rband->dest_me();
   uses=random(10)+1;
   return 1;
}

_turn(arg) {
   if (!arg) return 0;
   if (arg=="windlass") {
      _ready("trebuchet");
      return 1;
   }
   if (arg=="wheel") {
      write("Use: aim <person> to target.\n");
      return 1;
   }
}

_ready(arg) {
   if (!arg || arg!="trebuchet") return;
   if(charged) {
      write("The trebuchet is not yet ready!\n");
       return 1;
   }
   if (READIED) {
      write("The trebuchet is already cocked.\n");
      return 1;
   }
   if (TPS < 10) {
      write("You strain, but the windlass is too tight for you to budge.\n");
      say(TPN+" strains at the windlass, to no avail.\n");
      return 1;
   }
   else {
      write("You turn the windlass and cock the trebuchet.\n");
      say(TPN+" turns the windlass and cocks the trebuchet.\n");
      READIED=1;
      return 1;
   }
}

_arm(arg) {
   if (!arg) return 0;
   if (!READIED) {
      write("You have to cock the trebuchet first!\n");
      return 1;
   }
   if (LOADED) {
      write("There is already "+item->short()+" in the trebuchet.\n");
      return 1;   
   }
   item=present(arg,TP);
   if (item) {
      MOVE(item,TO);
      TP->add_weight(-item->QWGT);
      write(item->short()+" loaded.\n");
      say(TPN+" loads "+item->short()+" into the trebuchet's bucket.\n");
      LOADED=1;
      return 1;
   }
   else {
      write("You don't have that!\n");
      return 1;
   }
}

_target(arg) {
   aimedat=find_living(arg);
   if (!aimedat) {
      write(arg+" is not on!\n");
      return 1;
   }
   if (arg=="exos") aimedat=TP; 
   name=aimedat->QNAME;
   if (ENV(TP)==ENV(aimedat)) {
      write("You cannot target someone that close!\n");
      return 1;
   }
   if (!TPWIZ && aimedat->QWIZ) {
      write("You are not allowed to target wizards!\n");
      return 1;
   }
   write("You turn the wheel.  The trebuchet aims at "+name+".\n");
   TELL(aimedat,"You have an uneasy feeling...\n");
   say(TPN+" turns the wheel and aims the trebuchet.\n");
   return 1;
}

_pull(arg) {
   if (!arg || arg!="lever") return 0;
   _fire("trebuchet");
   return 1;
}

_fire(arg) {
   int busy;

   if (!arg || arg!="trebuchet") return 0;
   if (!READIED) {
      write("The trebuchet is not cocked!\n");
      return 1;
   }
   if (!LOADED) {
      write("The trebuchet is not loaded with anything!\n");
      return 1;
   }
   if (!aimedat) {
      write("The trebuchet is not aimed at anyone!\n");
      return 1;
   }
   if(TPS<5) {
      write("You strain, but you cannot pull the lever.\n");
      return 1;
   }
   ob=users();
   write("You pull the lever.  The trebuchet snaps forward with a loud\n"+ 
         "clatter!  The sling opens and spews forth its ammo!\n");
   say(TPN+" pulls the lever.  The trebuchet snaps forward with a loud\n"+ 
       "clatter!  The sling opens and spews forth its ammo!\n");
   if (!TPWIZ) shout("Something is catapulted over your head!\n");
   if(random(100)<100-TPL) {
      write("A bolt flies off the trebuchet and hits you in the face!\n");
      say("A bolt hits "+TPN+" in the face!\n");
      TP->HIT(10);
   }
   there=ENV(aimedat);
   charged=1;
   CO("READY",60);
   CO("OUCH",5+random(35));
   if (random(10)!=3) item->dest_me();
   else nobreak=1;
   LOADED=0;READIED=0;uses--;
   if(uses==0) {
      write("The trebuchet cord snaps and hits you in the face!\n");
      TP->HIT(20);
      return 1;
   }
   return 1;
}

OUCH() {
   for(i=0;i<sizeof(ob);i++){
      if(ob[i]->QRNAM=="exos") TELL(ob[i],TPN+" splatted "+aimedat->QNAME+".\n");
      if(ENV(ob[i])==there && ob[i]!=aimedat) {
         TELL(ob[i],name+" is smacked in the back of the head with a flying "+
         item->short()+" and falls to the grould, writing in pain!\n");
      }
       if(ob[i]==aimedat) {
         TELL(ob[i],"OWWW! "+item->short()+" comes flying through the air\n"+ 
              "and smacks you in the back of your head!  You fall to the\n"+
              "ground, writhing in pain!\n");
         TELL(ob[i],"You were smacked by "+TPN+"\n");
      }
   }
   if(nobreak) {
      MOVE(item,ob[i]);
      dmg=random(item->QWGT)-1;
   }      
   else {
      TELL(aimedat,"Unfortunately, "+item->short()+" shatters!\n");
      TLRM(ENV(aimedat),item->short()+" shatters upon impact!\n");
      dmg=random(item->QWGT)+2;
   }
   aimedat->REDHP(dmg);
   if (dmg > 15) {
      write("The force of the hit blows you into the next room!\n");
      say("The force blows "+name+" into the next room!\n");
      aimedat->RUN;
   }
   nobreak=0;dmg=0;
}

READY() {
   charged=0;
   say("The trebuchet's lever slowly falls into the ready position.\n");
   return 1;
}
