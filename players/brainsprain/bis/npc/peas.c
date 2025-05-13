inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
int randomizer;
int rand2;
object wep;
void reset(int arg){
    ::reset(arg);
if(arg) return;
    set_name("peasant");
    set_race("human");
randomizer = (random(6));
if(randomizer == 0){
    set_short("Ragged peasant");
            set_long(
"  This raggedy peasant shuffles around the room biting his nails.\n"+
"  His shirt is soiled from a combination of sweat and dirt.  His pants\n"+
"  are ripped just below the knees and his bare feet are dirty.\n"+
"\n");
  }
if(randomizer == 1){
    set_short("Peasant");
    set_long(
"  This peasant seems to be one of the more well of citizens of the kingdom\n"+
"  Although none of his clothes are ripped, they are a bit threadbare.\n"+
"  He stands among his peers and tries his best to look aloof.\n"+
 "\n");
set_gender(1);
set_alias("man");
  }
if(randomizer == 2){
set_gender(1);
set_alias("man");
    set_short("Old peasant");
    set_long(
"  This old man is stooped over and sits heavily against his staff.  His\n"+
"  head is slumped forward on his chest as he dozes.  His fists are tightly\n"+
"  clenched as he rocks back and forth.  His long, greasy white hair hangs\n"+
"  limply in his face.\n"+
"\n");
  }
if(randomizer == 3){
set_female();
set_alias("woman");
    set_short("Peasant woman");
    set_long(
"  This young woman is clad in little more than a bikini convered with a\n"+
"  this gauze wrap.  Her gypsy veil is carefully held in place and she\n"+
"  is flirting with every man in the place.  As she sees you she wiggles\n"+
"  her stomach seductively and winks.\n"+
"\n");
}
if(randomizer == 4){
    set_short("Merchant");
set_gender(1);
set_alias("merchant");
    set_long(
"  This merchant is dressed in fine clothes.  He is attempting to dress\n"+
"  in the styles that are vogue for the nobles.  He looks at the other\n"+
"  people in the room and attempts to sidle away from them.  He grins\n"+
"  as he notices you walk into the room.\n"+
"\n");
}
if(randomizer == 5){
    set_short("Fur trader");
set_gender(1);
set_alias("trader");
    set_long(
"  This fur trader is swathed in a thick bear hide.  The head of the bear\n"+
"  is set of on the mans right shoulder.  He is wearing a buckskin pants\n"+
"  and a thin elkskin shirt.  The smell of the untanned bear hide hangs\n"+
"  in the air and explains why this man is standing alone.\n"+
"\n");
  }
    set_level(10);
    set_hp(240);
    set_ac(4);
    set_wc(13);
    set_al(10);
    }
