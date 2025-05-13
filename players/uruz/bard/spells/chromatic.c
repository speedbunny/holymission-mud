#include "bard.h"
#define CHROMATIC_COST 5
#define CHROMATIC_LEVEL 1
#define CAP capitalize
#define QN query_name()

int hurl_orb(int dam, int sp, string name, string color, object obj) {
   obj->attacked_by(TP);
   ME("You focus all your energy to summon a "+color+" orb and hurl it "+
   "at "+name+".\n");
   say(TPN+" hurls a "+color+" colored orb at "+name+"."+CAP(obj->QN)+" is "+
     "engulfed in a blur of crackling "+color+" electricity!\n");

   TELL(obj, TPN+" creates a "+color+" orb out of thin air and hurls it "+
   "at you. You become engulfed in crackling "+color+" electricity!\n");
   obj->HIT(dam);
   TP->XP(dam);
   TPRSP(-sp);
   return 1;
}

int orb(object obj) {
   int dam, sp;
   string name, color;

   name=obj->QNAME;
   if(TPSP>=(TPMSP*95/100) && TPL>=25) {
      dam=1200;
      if(!obj->QNPC) {
         if(obj->QHP/2 < 200 && obj->QHP > 200) dam=200;
         else dam=obj->QHP/2;
      }
      color="a black";
      sp=TPMSP*95/100;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=320 && TPL>=22) {
      dam=500;
      if(!obj->QNPC) {
         if(obj->QHP/3 < 150 && obj->QHP > 150) dam=150;
         else dam=obj->QHP/3;
      }
      color="a violet";
      sp=320;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=160 && TPL>=19) {
      dam=250;
      if(!obj->QNPC) {
         if(obj->QHP/4 < 100 && obj->QHP > 100) dam=100;
         else dam=obj->QHP/4;
      }
      color="a blue";
      sp=160;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=80 && TPL>=16) {
      dam=125;
      if(!obj->QNPC) {
         if(obj->QHP/10 < 60) dam=60;
         else dam=obj->QHP/10;
      }
      color="a turquoise";
      sp=80;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=40 && TPL>=13) {
      dam=90;
      if(!obj->QNPC) dam=45;
      color="a green";
      sp=40;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=20 && TPL>=10) {
      dam=60;
      if(!obj->QNPC) dam=30;
      color="a yellow";
      sp=20;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=15 && TPL>=7) {
      dam=40;
      if(!obj->QNPC) dam=20;
      color="an orange";
      sp=15;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   if(TPSP>=10 && TPL>=4) {
      dam=30;
      if(!obj->QNPC) dam=15;
      color="a red";
      sp=10;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   else {
      dam=20;
      if(!obj->QNPC) dam=10;
      color="a white";
      sp=5;
      hurl_orb(dam,sp,name,color,obj);
      return 1;
   }
   return 1;
}

int main(string str) {
   string who, what;
   object target;

   if(!str) return 0;
   if(sscanf(str,"%s at %s",what,who)!=2 && str!="orb" && str!="orb at") return 0;
   if(what && what!="orb") return 0;
   CHK_GHOST();
   CHK_LVL(CHROMATIC_LEVEL);
   CHK_SP(CHROMATIC_COST);
   if(!who && !TPATT) {
      ME("Cast Chromatic Orb at whom?\n");
      return 1;
   }
   if(!who) target=TPATT;
   else target=HERE(who,ENV(TP));
   if(!target || !living(target)) {
      ME("Cast Chromatic Orb at whom?\n");
      return 1;
   }
   if(target==TP) {
      ME("You think this may be very stupid and PAINFUL.\n");
      return 1;
   }
   orb(target);
   return 1;
}
