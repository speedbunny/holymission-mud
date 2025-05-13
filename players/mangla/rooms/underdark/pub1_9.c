inherit "room/room";
 
#include "/players/mangla/defs.h"

reset(arg) {
    if (arg) return;

    set_light(1);

    short_desc="Small Pub";

    long_desc=
             "This is a small pub that just serves enough to stay\n" +
             "open. There seems to be light here but you cannot\n" +
             "see where it would be coming from. The bar on the west\n" +
             "wall is small and has a small menu hanging above it.\n";

    items=({
            "menu","It contains food a drink prices. Try reading it",
            "bar","Simple wooden construct. There is a menu hanging over it",
          });

    dest_dir=({ROOM + "underdark/r2_9","east",
             });

    property=({ "no_fight","no_steal","no_teleport"});
}
 
init() {
    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
    ::init();
}


int read(string str) {
    if (str=="menu" || str=="sign") {
        write("                        Simple Pub                    \n"+
              "We offer:\n\n"+
              "1   Wine                                    200 coins \n"+
              "2   Beer                                     35 coins \n"+
              "3   Coffee                                   40 coins \n"+
              "4   Water                                    12 coins \n"
             );
        return 1;
    }
    return 0;
}


int order(string str) {

    string name, short_desc,art, mess;
    int value, cost, strength, heal,i;
    object dummy;

    if (!str) {
        write("You might feel the chaos in this world..order what??\n");
        return 1;
    }

    else if (str == "wine" || str == "1") {
        mess = "The wine makes you feel much better.... AHHHH";
        heal= 35;
        value = 200;
        strength = 16;
        art ="alko";
    }

    else if (str == "beer" || str=="2") {
        mess = "You enjoy the good taste of a good beer.... AHHHH";
        heal= 9;
        value = 35;
        strength = 4;
        art = "alko";
    }

    else if (str == "coffee" || str=="3") {
        mess = "WELL.... You feel your head getting clearer !";
        heal = 0;
        value = 40;
        strength = -2;
        art = "alko";
    }

    else if (str == "water" || str == "4") {
        mess = "WELL.... You feel your head getting clearer !";
        heal = 0;
        value = 12;
        strength = -1;
        art = "alko";
    }

 
    else {
        write("The bartender stares at you, saying: We don't have that.\n");
        return 1;
    }
 
    if (call_other(this_player(), "query_money", 0) < value) {
        write("Something states: You do not have enough gold.\n");
        return 1;
    }

    if (art=="alko" || art=="special") {
        if (!call_other(this_player(), "drink_alcohol", strength)) {
            write("Something states: I think you've had enough.\n");
            return 1;
        }
    }

    else if (art=="soft") {
        if (!call_other(this_player(),"drink_soft",strength)){
            write("Something states: Sorry, I think you have had enough.\n");
            return 1;
        }
    }

    write("You pay " + value + " coins.\n");
    this_player()->add_money(-value);
    if(art=="special") this_player()->restore_spell_points(heal);
    else this_player()->heal_self(heal);
    write(mess + ".\n");
    return 1;
}
