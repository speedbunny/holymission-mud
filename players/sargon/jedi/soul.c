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

int _cast_(string str) {

    string *spellname;
    string newstr;
    int i, j;

    if(!str || str == "") {
      write("You must supply an arguement to cast.\n");
      return 1;
    }
    spellname = explode(str," ");
    i = sizeof(spellname);
    if( i > 1 )
        for(j=1;j<i;j++)
            if(j == 1) newstr = spellname[j];
            else newstr = newstr + " " + spellname[j];

    if(file_size(SPELL + spellname[0] + ".c") > 0)
        if ((SPELL + spellname[0])->main(newstr))
            return 1;
  if(TP->query_immortal()) {
    if(file_size(TESTING + spellname[0] + ".c") > 0)
      if ((TESTING + spellname[0])->main(newstr))
        return 1;
  }
    write("You do not seem to know that spell!\n");
    return 1;
}

int _cast(string str) {
  if(find_call_out("_cast_") != -1) {
    write("You are already casting.\n");
    return 1;
  }
  call_out("_cast_",1,str);
  return 1;
}

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39 || theverb[0] == 46) return 0;
    if(theverb[strlen(theverb)-1] == '.') return 0;

    if(theverb == "quit" || theverb == "dest") return 0;
    if(TP->query_immortal()) {
        if(file_size(TEST + theverb + ".c") > 0)
            if ((TEST + theverb)->main(str))
                return 1;
    }
    if(file_size(BIN + theverb + ".c") > 0)
        if ((BIN + theverb)->main(str))
            return 1;
        else return 0;
    if(theverb == "jedi/" || theverb == "j/") {
        (BIN+"jedi")->main(str);
        return 1;
    }
    return 0;
}

void reset(int arg) {

    if(arg) return;

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
    add_action("_cast","cast");
    add_action("_filter","",1);

    TELL(TP,"You can feel the Force floating through your whole body.\n");
    if(TP->RNAME!="mangla" && !TP->query_invis() && !TP->query_immortal())
        CD->do_chat(guild,"[* Jedi *] "+CAP(TP->RNAME)+
//            " returns from vacation, and is ready to battle some more.\n");
             ", an honored jedi warrior, returns.\n");

}

