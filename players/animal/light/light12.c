#include "../../../room/room.h"
 
#undef EXTRA_RESET 
#define EXTRA_RESET extra_reset(); 
 
#undef EXTRA_INIT
#define EXTRA_INIT ex_init();
 
string chats; 
 
get_chats() { 
    if (!chats) { 
chats = allocate(7); 
chats[0] = "Gopher crys: Humans stink!\n"; 
chats[1] = "Gopher crys: Leave us alone please!\n"; 
chats[2] = "Gopher crys: Help me!\n"; 
chats[3] = "Gopher crys: Run!\n"; 
chats[4] = "Gopher crys: Hide!\n"; 
chats[5] = "Gopher crys: Butcher!\n"; 
chats[6] = "Gopher crys: Killer!\n"; 
    } 
    return chats; 
} 
 
extra_reset() 
{ 
    object money;
    object gopher, weapon; 
    int n,i,class,value,weight; 
    string w_name,alt_name; 
 
    i = 0; 
    if (!present("gopher")) { 
     while(i<4) { 
    i += 1;
    gopher = clone_object("obj/monster"); 
    call_other(gopher, "set_name", "gopher"); 
    call_other(gopher, "set_alias", "ground hog"); 
    call_other(gopher, "set_race", "gopher"); 
    call_other(gopher, "set_level", random(5) + 2); 
    call_other(gopher, "set_hp", random(60)+80);  
    call_other(gopher, "set_al", 200);
    call_other(gopher, "set_short", "A gopher"); 
    call_other(gopher, "set_ac", 3); 
    call_other(gopher, "set_wc", 7);
    call_other(gopher, "set_aggressive", 0);
    call_other(gopher, "load_a_chat", 40, get_chats());
    money = clone_object("obj/money");
    move_object(money, gopher);
    call_other(money, "set_money", random(150));
    move_object(gopher, this_object());
}
    }
}
 
reset(arg) {
    if(arg) return;
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4);
#endif
    set_light(1);
    long_desc =
      "The gopher's place\n\n"+
      "   You are in the gopher's prairie. This place is FULL of holes and\n" +
      "   of course, gophers! They are all over the place making more holes.\n"+
      "\n";
    short_desc = "The gopher prairie";
    dest_dir = ({
          "players/animal/light/light20", "east",
          "players/animal/light/light11", "west",
	});
    items = ({
     "holes","There are many holes, some are BIG",
     "hole","This is one BIG hole",
    });
    extra_reset();
    return;
}
 
init()  {
	::init();
     add_action("down","down");
     add_action("enter","enter");
}
 
down() {
     write("That must be one BIG gopher that made this hole!\n");
     call_other(this_player(),"move_player","down a hole#players/animal/light/light27");
     return 1;
}
 
enter(str) {
     if(!str) {
     write("Enter what???");
     return 1;
     }
     if (str == "hole" || str == "holes" || str == "gopher hole")  {
     write("That must be one BIG gopher that made this hole!\n");
 call_other(this_player(),"move_player","down a hole#players/animal/light/light27");
     return 1;
     }
}    
