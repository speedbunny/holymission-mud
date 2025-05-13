#include "/players/redsexy/defs.h"
#include "/players/redsexy/geomancer/geodefs.h"

int guild, level, legend_level, dex, str;
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
    return (str=="geosoul" || str=="guildsoul");
}

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39 || theverb[0] == 46) return 0;
    if(theverb[strlen(theverb)-1] == '.') return 0;

    if(theverb == "quit" || theverb == "dest") return 0;
      if(file_size(BINDIR + theverb + ".c") > 0)
        if ((BINDIR + theverb)->main(str))
            return 1;
        else return 0;
    if(theverb == "geomancer/" || theverb == "g/") {
        (BINDIR+"geomancer")->main(str);
        return 1;
    }
    return 0;
}

void reset(int arg) {

    if(arg) return;

    guild = 9;
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
    add_action("_filter","",1);

    tell_object(TP,"You become more aware of your environment.\n");
    if(TP->RNAME!="redsexy" && !TP->query_invis() && !TP->query_immortal())
        CD->do_chat(guild,"[*Geomancer] "+CAP(TP->RNAME)+
//            " studies the environment closely, preparing to do battle.\n");
             ", has arrived to cause chaos with the surroundings.\n");

}

