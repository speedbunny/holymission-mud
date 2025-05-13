inherit "room/room";

#include "/players/wilbie/def.h"
#define FOODS 2
#define Level this_player()->query_level()
#define Name this_player()->query_name()
#define Speak(s)   write("Serving Girl says: "+s+"\n")

int cm,mm,rmm;
string last_eater;

void reset(int arg) {

    if(!arg) {
        set_light(1);
        short_desc="White Crane Inn";
        long_desc=
            "You are in the White Crane Inn. Here you can buy food to still\n"+
            "your hunger, and quite an exotic selection is available.\n"+
            "@@show_menu";
        dest_dir=({
            FPATH+"v1","south",
                 });
        items=({
            "menu","The menu looks like this"
              });
    }
    cm=FOODS*4;
    mm=FOODS*2;
    rmm=FOODS;
}

init() {
    ::init();
    add_action("buy","buy");
    add_action("buy","order");
}

string show_menu() {

    write("\n");
    if(!(cm||mm||rmm)) 
  Speak("I beg your forgiveness, but we are out of food!");
    else {
write("1: Rice           ");write(cm);write("  20 gp\n");
write("2: Stir Fry       ");write(mm);write("  50 gp\n");
write("3: Squid          ");write(rmm);write("  90 gp\n");
write("4  Sake           ");write(" ");write("  2 gp\n");
        write("\n");
        write("Use 'buy <number>' to buy the desired Food. The food will\n"+
              "be consumed at once. Good appetite.\n\n");
    }
    return "";
}

int no_food() {

Speak("Sorry.  We all out of that!");
    if(cm||mm||rmm)
    Speak("Does something else sound good?");
    else
Speak("I go get more...  You come later, okay?");
    return 1;
}

int pays(int n) {

    if(this_player()->query_money() < n) {
Speak("You need more gold for that!");
        return 0;
    }
    this_player()->add_money(-n);
    return 1;
}

int tease(int n) {

    if(Name==last_eater)
Speak("You must be hungry one!");

    last_eater=Name;
    this_player()->heal_self(n);
    this_player()->eat_food(n);
    return 1;
}

int buy(string s) {

    if(!s) {
        Speak("What do you want to buy ?");
        return 1;
    }

// commonor's meal, price 20, heals 4, preferably for levels 1-6
    if(s=="1"||s=="<1>") {
        if(!cm) return no_food();
        if(!pays(20)) return 1;
write("You eat some bland rice.\n");
say(Name+" orders some rice.\n");
        cm=cm-1;
        return tease(4);
    }

// Fillet ofShark, price 50, heals 8, preferably for levels 7-12
    if(s=="2"||s=="<2>") {
        if(!mm) return no_food();
        if(!pays(50)) return 1;
        write("Mmmm -   Very tasty!\n");
say(Name+" orders some Stir Fry.\n");
        mm=mm-1;
        return tease(8);
    }

// Grilled Lobster Platter, price 90, heals 12, preferably for levels 13+
    if(s=="3"||s=="<3>") {
        if(!rmm) return no_food();
        if(!pays(90)) return 1;
write("A very filling meal indeed!\n");
say(Name+" orders the house special.\n");
        rmm=rmm-1;
        return tease(12);
    }

    if(s=="4"||s=="<4>"||s=="mug"||s=="ale") {
        if(!pays(2)) return 1;
        if(!this_player()->drink_alcohol(2)) {
Speak("You need to clear your head a little first!\n");
            this_player()->add_money(2);
            return 1;
        }
write("WOW! Some rather harsh Sake!\n");
say(Name+" barely swollows some Sake.\n");
        return 1;
    }
    Speak("We have no such number on the menu, try 1, 2 or 3.");
    return 1;
}
