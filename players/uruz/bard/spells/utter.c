#include "bard.h"
#define CHAOS_COST 100
#define CHAOS_LEVEL 29

int main(string str) {
   string who, what;
   object target;

   if(!str) return 0;
   if(str!="chaos") return 0;
   ME("UTTER CHAOS!!!!!!\n");
   say("UTTER CHAOS!!!!!!\n");
   return 1;
}
