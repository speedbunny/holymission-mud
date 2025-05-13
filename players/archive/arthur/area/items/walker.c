/*Code by Arthur for Holy Mission 140.78.3.1 Date done 11.4.94*/
inherit "obj/treasure";
#include "/players/arthur/defs/ardefs.h"

int amount;

reset (arg) {
if (arg) return;
   set_id("Walker");
   set_short("A walker");
   set_alias("walker");
   set_long("This is an old ladys walker, you can probably runover other \n"+
   "players with it.\n");
   set_value(700);
   set_weight(4);
}
init() {
     add_action("run_over", "runover");
}
run_over(str){
    object ob;
    string sexxx,att;
    if (!str) return 0;
        ob = present(lower_case(str), environment(this_player()));
    if (!ob || !living(ob)) {return 0;}
    att=capitalize(lower_case(str));

    if(TP()->query_gender()==0){ sexxx="itself";}
    else if(TP()->query_gender()==1){ sexxx="himself";}
    else if(TP()->query_gender()==2){ sexxx="herself";}


    if (ob == TP()) {
        write("You look like a total dumbass trying to run the walker over yourself.\n");
        say(TPN+" smashes "+sexxx+" with a walker, WHAT a DUMBASS\n");
        CO(ob,"reduce_hit_point",500);/* deserved if they are that stupid:)*/
        return 1;}
    else {
        tell_object(ob,"THUMP, THUMP!!!\n"+TPN+" runs you over with a walker.\n");
        say(TPN+" wheels a walker over "+att+"!\n", ob);
        write("You run "+att+" with a walker!\n"); return 1;}
    }

