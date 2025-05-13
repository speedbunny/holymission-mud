inherit "/obj/monster";
#include "/players/saffrin/defs.h"

object quill;

void reset(int arg){

  ::reset(arg);
  if (!arg) {
     set_name("William Shakespeare");
     set_alias("william");
     set_alt_name("shakespeare");
     set_race("human");
     set_short("William Shakespeare");
     set_long("The legendary poet and playwrite.  He is wearing a ruffled collar\n"+
              "and a dark blue tunic.  He has dark hair and a goatee.  There\n"+
              "are ink stains on his fingers.\n");
     set_level(100); 
     set_wc(18);
     set_ac(20);
     set_al(1000);
     set_aggressive(0);
     set_gender(1);
     add_money(70000 + random(1000));

     MOVE(CLONE(HAM+"obj/quill"),TO);
        init_command("wield quill");
  }
}
