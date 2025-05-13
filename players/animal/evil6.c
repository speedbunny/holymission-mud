#include "../../room/std.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET\
        ex_reset();
 
#undef EXTRA_INIT
#define EXTRA_INIT\
       ex_init();
 
#undef EXTRA_LONG
#define EXTRA_LONG\
       ex_long(str);
 
TWO_EXIT("players/animal/evil3", "north",
         "players/animal/evil7", "east",
        "A small and dingy room.",
"Small room\n\n" +
"    You are in a small and stinky room. You smell freshly burnt\n" +
"    hair in the air. An old hag lives here and she does not seem\n" +
"    very glad to see you.\n\n",0)
 
object hag, owl;
int passage_open;
 
ex_init() {
    add_action("search"); add_verb("search");
    add_action("down"); add_verb("down");
}
 
ex_long(){
    if (passage_open) write("There is a trap door open leading down\n");
}
 
down(){
    if (!passage_open) return 0;
    if (present("hag")) {
        write("The hag blocks your way!\n");
        return 1;
    }
    call_other(this_player(),"move_player","down#players/animal/evil24");
    return 1;
}
 
search(str){
    object ob;
    if (!str) str = "room";
    if (str=="room") {
 write("A careful search of this place reveals a trap door in the floor!\n");
     say(call_other(this_player(),"query_name") +
     " finds a trap door leading down.\n");
        passage_open=1;
    }
    return 1;
}
 
ex_reset() {
        object item,ob;
int i;
    passage_open=0;
    if (!hag) {
        hag = clone_object("obj/monster");
        call_other(hag,"set_name","hag");
        call_other(hag,"set_alias","hag");
        call_other(hag,"set_level",12);
        call_other(hag,"set_long","The hag is old and evil looking.\n");
        call_other(hag,"set_ac", 4);
        call_other(hag, "set_hp", 250);
        call_other(hag,"set_wc", 12);
        call_other(hag,"set_aggressive",0);
        call_other(hag,"set_chance",20);
        call_other(hag,"set_spell_mess1",
          "The hag points and shrieks!");
        call_other(hag,"set_spell_mess2",
          "The hag points at you and shrieks!");
        call_other(hag,"set_spell_dam",25);
        call_other(hag,"set_al",-750);
        move_object(hag,this_object());
}
if(!owl) {
call_other("players/animal/evil24","clear");
/* Herp: no /players/ringer here ... */
#if 0
            item = clone_object("players/ringer/fam_item");
            call_other(item,"set_id","black stone");
            call_other(item,"set_alias","stone");
            call_other(item,"set_short","A black stone");
            call_other(item,"set_long",
"The stone is dark.  You find yourself wanting to gaze into it.\n");
            call_other(item,"set_value",500);
            call_other(item,"set_weight",1);
            move_object(item,"/players/animal/evil24");
            owl = clone_object("players/ringer/familiar");
            call_other(owl,"set_name","black owl");
            call_other(owl,"set_alias","owl");
            call_other(owl,"set_short","A black owl");
            call_other(owl,"set_long",
     "The owl is large and black.  He stares at you menacingly.\n");
            call_other(owl,"set_level",6);
            call_other(owl,"set_aggressive",0);
            call_other(owl,"set_ac", 2);
            call_other(owl,"set_wc", 5);
            call_other(owl,"set_control_ob",item);
            call_other(item,"set_familiar",owl);
            call_other(owl,"set_familiar_mess",
  "Your eyes clear and you see the world through a new perspective.  You\n"
                       +"ruffle your feathers.  FEATHERS!");
          call_other(owl,"set_think",this_object());
            move_object(owl,this_object());
#endif
        }
}
 
think(ob) {
    int t;
    t=random(4)+1;
    if (t==1){
        tell_object(ob,
"The owl thinks to himself: I wonder if the old hag is playing with my\n"
+"mind again. But, somehow it seems different this time...\n");
        return 1;
    }
    if (t==2) {
        tell_object(ob,
"The owl thinks to himself: Hmm, the old hag sure has been working in\n"
+"the lab alot lately.\n");
        return 1;
    }
    if (t==3) {
        tell_object(ob,
"The owl thinks to himself: Mice.  I need some good mice to eat.\n");
        return 1;
    }
    if (t==4) {
        tell_object(ob,
"The owl thinks to himself: Oh I wish Animal was here.\n");
        return 1;
    }
}
