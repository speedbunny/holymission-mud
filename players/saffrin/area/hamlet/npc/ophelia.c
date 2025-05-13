inherit "/obj/monster";
#include "/players/saffrin/defs.h"
      
object crown, rose;

void reset (int arg){

  ::reset(arg);
  if(!arg) {
     set_name("ophelia");
     set_race("human");
     set_short("Ophelia");
     set_long("This is a beautiful maiden who is listening to the cardinals in the garden.\n"+
                "She looks very peaceful and serene.  It might prove disastorous to kill her,\n"+
                "so you might want to think twice about it.\n");
     set_level(1);
     set_gender(2);
     set_al(10000);

     MOVE(CLONE(HAM+"obj/ocrown"),TO);
         init_command("wear crown");
     MOVE(CLONE(HAM+"obj/rose"),TO);
  }
}
