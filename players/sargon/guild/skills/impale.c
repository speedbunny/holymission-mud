#include "/players/sargon/define.h"
impale(str){

object pike, here;
string corpname, name, name1, corpse;

        if(!str){
             write("Useage: impale corpse of <name>\n");
             return 1;
             }

        if(TP->query_spell_points()< 5){
             write("You are too tired to impale anything!\n");
             return 1;
             }
        if(!present("corpse", E(TP))){
             write("There is no corpse here to impale!\n");
             return 1;
             }
        if(here->query_living()){
             write("You can only impale a corpse!\n");
             return 1;
             }
       
        write("You impale the "+name+" on a long pike! You feel as rush as"+
        " the blood oozes through your hands!\n");
        say(CAP(TPN)+" grabs the bloody remains of the "+name+" and impales"+
        " it upon a rather long pike, leaving it as a symbol of a fighter's "+
        "true savagery!\n", TP);

        return 1;
        }
