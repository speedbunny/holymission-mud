
/* Completed 28.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";
int count;

void reset(int arg) {
    ::reset(arg);
    count=10;
    if(arg) return;
    set_light(1);
    short_desc="Shore of a stream.";
    long_desc="You are standing on the shore of a little stream. It "+
         "is possible to pass it, but no use of that: an unclimbable rock "+
         "wall forms the southern shore. You can go back to the road north.\n";
    dest_dir=({PA+"area1/ewroad2.c","north"});
    items=({"stream","Its water is clean like a crystal",
            "water","Crystal-clean. Tipical place for trouts",
            "shore","Covered with sand",
            "sand","Sure, the god of the mud has hidden his treasure here :)",
            "wall","About 50 meters [160 feet] high. Perhaps you don't want "+
                   "to find your death falling down from it",
            "rock wall","About 50 meters [160 feet] high. Perhaps you don't "+
                   "want to find your death falling down from it"});   
}

void init() {
    add_action("search","search");
    ::init();
    add_action("fish","fish");
    add_action("search","search");
    add_action("drink","drink");
}         

int fish() {
    object ob;
    ob=present("rod",this_player());
    if (!ob) {
        write("You are not quick enough to catch a fish with your "+
                    "bare hands.\n");
        return 1;
    }
    if (!call_other(ob,"id","aaa-special-fishingrod")) {
        write("You need a special fishingrod for stream-fishing, "+
              "the one you have won't do!\n");
        return 1;
    }
    if (call_other(ob,"query_in_use"))  {
        write("You are already fishing!\n");
        return 1;
    }
    call_other(ob,"set_in_use",1);
    write("You sit down and put your rod in the water.\n"+
          "The rest is matter of patience and luck.\n");
    say(this_player()->query_name()+" sits down and starts fishing.\n");
    call_out("fish_result",40,ob);
    return 1;
}

void fish_result(object ob2) {
    int a;
    int b;
    object ob;
    object tp;
    string str;
    tp=this_player();
    str=" his ";
    if (!ob2) return;       
    call_other(ob2,"set_in_use",0);                  
    if ((!present(tp)) || (!present(ob2,tp))) return;            
    if (tp->query_gender()==2) str=" her ";     
    if (tp->query_gender()==0) str=" its ";     
    a=random(100)-2*(tp->query_dex());
    if ((a<(count*10)) || (a==(count*10))) {
        write("The god of the fishers smiles at you as you catch a trout!\n");
        say(tp->query_name()+" managed to catch a fish!\n");
        ob=clone_object(PA+"area1/trout.c");
        b=transfer(ob,tp);
        if (b==1) {
            write("As it is too heavy for you, you drop the fish. It slips "+
                  "back in the water.\n");
            say(tp->query_name()+" drops back"+str+"fish in the "+
                "water!\nWhy?\n");
        return;
        }
        count=count-1;
        return;
    }
    write("Well, well... The fishes don't bite today :(\n");
    say(tp->query_name()+" pulls out"+str+"line from the water "+
        "angrily. Seems this is not"+str+"day.\n");
    return;
}

int search(string str) {
    if ((!str) || ((str!="water") && (str!="stream") && (str!="sand"))) {
        notify_fail("After a half of an hour searching, you are completely "+
                    "sure: absolutely nothing is here.\n");
        return 0;
    }
    if ((str=="stream") || (str=="water")) {
        write("You find fishes!\nBut they are too quick :(\n");
        say(this_player()->query_name()+" tries to draw out the stream, but "+
            "fails.\n");
        return(1);
    }
    write("You find nothing. But the treasure must be here! Perhaps you "+
          "should try again?\n");
    say(this_player()->query_name()+" searches the sand as a greedy maniac. "+
        "I reveal you, and only you, that there is nothing hidden here, but "+
        "keep it in secret!\n");
    return 1;
}

int drink(string str) {
     if ((!str) || (str!="water")) {
         notify_fail("Drink what?\n");
         return 0;
     }
    write("Argh, that was good! Much better than that watered wine in the "+
         "pubs!\n");
    say(this_player()->query_name()+" drinks some water from the stream and "+
        "seems to enjoy it very much.\n");
    return 1;
}   
