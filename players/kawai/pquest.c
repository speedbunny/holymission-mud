inherit "obj/quest_obj";
#include <lw.h>
#define LEVEL 75

reset(arg) {if(!arg){
set_name("puzzles");
set_hint(lw(
 "One of the arrogant Grand Wizards has proclaimed himself to\n"+
 "be the wisest of all creatures and gods.  To prove his point\n"+
 "he has devised a simple test of 3 puzzles for anyone\n"+
 "who would dare challenge his claim.  The lords of Holy Mission\n"+
 "fear that if unchalanged, the Wizard may soon carry out a\n"+
 "ruthless policy of genocide against those creatures deemed \n"+
 "'non-intellegent' and unworthy of living.  Prove the Wizard\n"+
 "wrong and bring pride to the citizens of this land.\n"));
set_short_hint("Take the Wizard's Challenge!");
set_weight(LEVEL);
set_killing(1);
}}

