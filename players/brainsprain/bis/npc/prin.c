inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("princess");
    set_race("human");
    set_gender(0);
    set_alias("fluentia");
    set_alt_name("princess bismarck");
    set_short("Princess Bismarck");
            set_long(
"This is the Fluentia, the most beautiful woman in the land.  Her ivory "+
"skin and blond hair seem to shine.  Her blue dress matches the color of "+
"her eyes.  Her face is a mask of pure innocence and beauty.  To see her "+
"is to fall in love.\n")+
    set_level(10);
    set_hp(230);
    set_al(400);
    set_ac(3);
    set_wc(12);
set_heart_beat(1);
set_dead_ob(this_object());
    }
heart_beat(){
  ::heart_beat();
  }

monster_died(ob){
write("The princess screams in rage and drags you to her workroom!\n");
move_object(this_player(),br+"/t-1-4.c");
return 0;
}
catch_tell(arg){
string str1;
if(sscanf(arg,"%s gloves",str1)==1){
write("Princess Fluentia says: you will have to fight me for them.\n");
return 1;
 }
}
