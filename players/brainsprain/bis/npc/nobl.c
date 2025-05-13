inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
int randomizer;
void reset(int arg){
    ::reset(arg);
if(arg) return;
    set_name("noble");
    set_race("human");
    set_gender(1);
    set_alias("man");
randomizer = (random(4));
if(randomizer == 0){
    set_short("Minor noble");
            set_long(
"This is one of the minor dukes in the kingdom.  He is dressed in robes "+
"laced with golden strings.  He is walking around the room attempting to "+
"mingle with the others, but most of the nobles are to busy posturing.\n");
  }
if(randomizer == 1){
    set_short("Noble");
    set_long(
"This is a titled man of the kingdom.  He is dressed in simple breeches "+
"and is wearing a white shirt with a black vest.  His long, curly brown "+
"hair is loosely tied back and his carefully trained beard is braided.\n");
  }
if(randomizer == 2){
    set_short("Old noble");
    set_long(
"This old gentleman is slightly slumped over but he has a regal look to "+
"him.  His hawk like nose and piercing blue eyes make him look like a "+
"natural leader.  His left ear is pierced and he has a cross in it.\n");
  }
if(randomizer == 3){
    set_short("Noble woman");
    set_long(
"This severe looking noble woman is clad in a heavily starched dress. A "+
"corset pulls her stomach in and presses her breasts out making her very "+
"shapely.  She is wearing a light perfume that barely covers the scent of "+
"body odor.\n");
}
    set_level(7);
    set_hp(150);
    set_al(0);
    set_ac(2);
    set_wc(9);
    }
