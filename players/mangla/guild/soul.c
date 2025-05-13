#include "/players/mangla/defs.h"
#include "/players/mangla/guild/tsoul.h"
#include "/players/mangla/guild/bin/lightning.h"
/**********  ARRRGGHHH have to keep lightning in soul since it
                       has such a long time delay. If in its own
                       object it would start to overlap when more
                       than one jedi using it.
***********/

//#include "/players/mangla/guild/extra_look.h"
//#include "/players/mangla/guild/soul_func.h"

#define TEST "/players/mangla/guild/TEST/"

int guild, level, legend_level, dex, str;
int parrying,preparing;
object thispl;

int recognize_fight() {

  if(legend_level && (str+dex) > 65)
    TP->attack();
  if(!random(41 - dex))
    TP->attack();
}

int get() {
  return 1;
}

int drop () {
  return 1;
}

int id(string str) {
  return (str=="jedisoul" || str=="guildsoul");
}

int query_parrying() {
  return parrying;
}

int query_preparing() {
  return preparing;
}


int _actions_(string strSpell, string strArgs, int intTestDir) {

  switch(intTestDir) {
  case 0:
    return (BIN + strSpell)->main(strArgs);
    break;
  case 1:
    return (TEST + strSpell)->main(strArgs);
    break;
  }
  return 0;
}

int _actions(string strArgs) {

  int     intDelay;
  string  theverb;

  intDelay = 0;
  theverb = (string)query_verb();

  // 39 is '   and   46 is .
  if(theverb[0] == 39 || theverb[0] == 46)
    return 0;

  if(theverb[strlen(theverb)-1] == '.')
    return 0;

  if(theverb == "quit" || theverb == "dest")
    return 0;
  if(TP->query_immortal() || TP->query_testchar()) {
    if(file_size(TEST + theverb + ".c") > 0) {
      intDelay = (TEST + theverb)->query_delay();
      if(intDelay == 0) {
        return (TEST + theverb)->main(strArgs);
      }
      else {
        if(find_call_out("_actions_") != -1) {
          write("You are already casting.\n");
          return 1;
        }
        call_out("_actions_", 1, theverb, strArgs, 1);
        return 1;
      }
    }
  }

  if(file_size(BIN + theverb + ".c") > 0) {
    intDelay = (BIN + theverb)->query_delay();
    if(intDelay == 0) {
      return (BIN + theverb)->main(strArgs);
    }
    else {
      if(find_call_out("_actions_") != -1) {
        write("You are already casting.\n");
        return 1;
      }
      call_out("_actions_", 1, theverb, strArgs, 0);
      return 1;
    }
  }
  if(theverb == "jedi/" || theverb == "j/") {
    return (BIN + "jedi")->main(strArgs);
  }
  return 0;
}


void reset(int arg) {

  if(arg)
    return;

  guild = GM->query_number("jedi");
  preparing = 0;
  thispl = ENV();
  if(TP) {
    TP->set_infravision();
    level = TPL;
    legend_level = TP->query_legend_level();
    dex = TP->DEX;
    str = TP->STR;
    if(level > 20) {
      TP->set_n_wc(10);
    }
    else {
      TP->set_n_wc(5);
    }
  }
}

void init() {

  add_action("_prepare","prepare");
  add_action("_spread","spread");
  add_action("_free","free");
  add_action("_actions","",1);

  TELL(TP,"You can feel the Force floating through your whole body.\n");
  if(TP->RNAME!="mangla" && !TP->query_invis() && !TP->query_immortal())
      CD->do_chat(guild,"[* Jedi *] "+CAP(TP->RNAME)+
                        ", an honored jedi warrior, returns.\n");
}

