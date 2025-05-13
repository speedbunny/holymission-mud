inherit "/obj/treasure";
#include "/players/mangla/defs.h"

#define ME environment()

int his_str,his_dex,his_chr,his_ac;

int takeback() {

    remove_call_out("takeback");
    if(living(ME) || ME->query_player()) {
        ME->set_str(his_str);
        ME->set_dex(his_dex);
        ME->set_chr(his_chr);
        ME->set_ac(his_ac);
    }
    destruct(this_object());
    return 1;
}

int _start(int time,int percentage) {

    object obj;
    int new_str,new_dex,new_chr;

    his_str = ME->query_str();
    his_dex = ME->query_dex();
    his_chr = ME->query_chr();
    new_str = his_str - (his_str*percentage/100);
    new_dex = his_dex - (his_dex*percentage/100);
    new_chr = his_chr - (his_chr*percentage/100);
    ME->set_str(new_str);
    ME->set_dex(new_dex);
    ME->set_chr(new_chr);

    his_ac=ME->query_ac();
    ME->set_ac(his_ac-(his_ac*percentage/100));
/*
    if (obj) {
        TELL(obj,"Fighting: "+TP->RNAME+" vs. "+ME->NAME+"\n" +
                 "Percentage: " + percentage + "%\n" +
                 "Strength Dexterity Charisma\n" +
                 "Old stats: " + his_str + " " + his_dex + " " + his_chr + "\n" +
                 "New stats: " + new_str + " " + new_dex + " " + new_chr + "\n" +
                 "New AC should be: " + ME->query_ac() + "\n");
    }
*/
    call_out("takeback",time);
    return 1;
}

int drop() { return 1; }

void reset(int arg) {

    set_id("weakerobj");
    set_alias("weaker");
}

init() {

  object all;
  int i, sizeall, flag;

  all=all_inventory(ME);
  sizeall = sizeof(all);
  for(i=0; i < sizeall; i++) {
    if(all[i]->id("weakerobj")) {
      if (flag) all[i]->takeback();
      flag = 1;
    }
  }    
}

