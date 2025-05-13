inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset(arg);
if(arg) return;
    set_name("count");
    set_race("human");
    set_gender(1);
    set_alias("count bismarck");
    set_alt_name("bismarck");
    set_short("Count Bismarck");
            set_long(
"This is the renowned Count Bismarck, the ruler of the entire Bismarck "+
"domain.  He is a big man, and he towers over most of his followers.  A "+
"natural aura hangs around him that creates an instant respect.  He is "+
"dressed in the finest clothes available in the land.  He is wearing an "+
"impressive crown and he walks so that it tilts slightly to the left.\n");
    set_level(10);
    set_hp(230);
    set_al(1000);
    set_ac(3);
    set_wc(12);

  move_object(clone_object(bi+"/scep.c"),this_object());
    }
init(){
  ::init();

  }

catch_tell(arg)
{
string str1;
 if (sscanf(arg,"%s help",str1)==1)
   {
   write("The king clears his throat and says:\n");
   write("Ever since that dastardly mage stole my staff, the kingdom has\n"+
         "fallen into shambles.  I will pay 10000 coins to the person\n"+
         "who returns his staff to me. If you will do it, go see Duke\n"+
         "Jasper, he will help you on your quest.\n");
   return 1;
}
}
