inherit "room/room";
string chats, a_chats; 
int i;
 
reset(arg) {
    if (!arg) {
#if 0
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Village street";
    no_castle_flag = 0;
    long_desc =
        "Village\n"
        + "\n"
        + "     This is busy part of town. There are peasants walking\n"
        + "     around here, chatting about the cliff and other\n"
        + "     interesting everyday things.\n";
        items = ({
        "mountains","The mountians are beautiful",
        "shop","They sell many explosives there",
        });
    dest_dir =
        ({
        "players/animal/shops/shop_street3", "north",
        "players/animal/shops/shop_street1", "south",
/*
         "players/animal/guild/guild","west",
        "players/animal/shops/exshop","east",
*/
        });
     }
     extra_reset();
     return;
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
 
get_chats() { 
    if (!chats) { 
chats = allocate(7); 
chats[0] = "The peasant shouts: Where is the King's guard?\n"; 
chats[1] = "The peasant shouts: I did not do anything wrong to you!\n"; 
chats[2] = "The peasant shouts: Help us!\n"; 
chats[3] = "The peasant shouts: Call the guard!\n"; 
chats[4] = "The peasant shouts: Hide the women!\n"; 
chats[5] = "The peasant shouts: I will kill you for this!\n"; 
chats[6] = "The peasant shouts: Leave us be!\n"; 
    } 
    return chats; 
} 
 
get_a_chat() { 
    if (!a_chats) { 
a_chats = allocate(7); 
a_chats[0] = "The peasant says: Where is the King?\n"; 
a_chats[1] = "The peasant says: Find the King!\n"; 
a_chats[2] = "The peasant says: Look everywhere for him!\n"; 
a_chats[3] = "The peasant says: Check the trees!\n"; 
a_chats[4] = "The peasant says: He is too fat and lazy.\n"; 
a_chats[5] = "The peasant says: The mystic is a wise man.\n"; 
a_chats[6] = "The peasant says: Buy a shot, they are good!\n"; 
    } 
    return a_chats; 
} 
 
extra_reset() 
{ 
    object money;
    object peasant;
 
    i = 0; 
    if (!present("peasant")) { 
     while(i<4) { 
    i += 1;
    peasant = clone_object("obj/monster"); 
    call_other(peasant, "set_name", "peasant"); 
    call_other(peasant, "set_alias", "ground hog"); 
    call_other(peasant, "set_race", "peasant"); 
    call_other(peasant, "set_level", random(9) + 2); 
    call_other(peasant, "set_hp", random(100)+80);  
    call_other(peasant, "set_al", 400);
    call_other(peasant, "set_short", "A peasant"); 
    call_other(peasant, "set_ac", 4); 
    call_other(peasant, "set_wc", 8);
    call_other(peasant, "set_aggressive", 0);
    call_other(peasant, "load_a_chat", 40, get_chats());
    call_other(peasant, "load_chat",10, get_a_chat()); /* backwards I know */
    money = clone_object("obj/money");               /* but hey I wrote it! */
    move_object(money, peasant);
    call_other(money, "set_money", random(300));
    move_object(peasant, this_object());
    }
  }
}
