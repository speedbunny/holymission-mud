/* Completed 12.02.1995. */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";
int code;
string *ans;
string *quast;

void reset(int arg) {
    ::reset(arg);
    code=random(3);
    if(arg) return;
    ans=allocate(4);
    ans=({"233","451","322","154"});
    quast=allocate(4);
    quast=({
          "1, 17      2, 15      3, 61           4, 13       5, 17\n"+      
          "1, apple   2, pear    3, strawberry   4, cherry   5, plum\n"+    
          "1, ant     2, smurf   3, Gorgurack    4, mole     5, sparrow\n\n", 
/* 2-not prime number, 3-grow not on tree 3-not a newbie-monster */
          "1, 17        2, 23        3, 5         4, 12      5, 9\n"+       
          "1, Hungary   2, Germany   3, Ukraine   4, Spain   5, Israel\n"+  
          "1, paladin   2, thief     3, mage      4, ninja   5, fighter\n\n",
/* 4-even number 5-not in Europe 1-not a guild in HM */  
          "1, 165       2, 34560      3, 459      4, 455       5, 0\n" +       
          "1, Moscow    2, New York   3, Peking   4, Nairobi   5, Vienna\n"+
          "1, demonic   2, neutral    3, good     4, evil      5, saintly\n\n", 
/* 3-not divisible by 5  2-not a capital 2-neutral align.
          "1, 57          2, 700   3, 91         4, 28       5, 49\n\n"+
          "1, Washington  2, Bush  3, Jefferson  4, Lincoln  5, Churchill\n"+  
          "1, elf         2, human 3, troll      4, dragon   5, hobbit\n\n"
/* 1-not divisible by 7  5-not a US president  4-not a player-race in HM */
           });   
    property=({"no_teleport"});
    set_light(1);
    short_desc="Aaa's castle, bottom of north tower";
    long_desc="As you remember the castle, now you should be under the "+
              "north tower. Despite of this, you can't see stairs. As a "+
              "matter of fact, you can't see anything due to the darkness "+
              "but a lighting crystalline face.\n";
    dest_dir=({PA+"castle/antecham.c","south"});
    items=({"crystal","Who knows, there are letters on it",
            "face","Who knows, there are letters on it",
            "crystalline face","Who knows, there are letters on it"});   
}

void init() {
    ::init();
    add_action("read","read");
    add_action("think","think");
}

int read(string str) {
    int a;
    a=((str!="face") && (str!="crystal") && (str!="letters"));
    if (a && (str!="crystalline face")) {
        write("There is nothing on that to read.\n");
        return 0;
    }
    write("You read the following:\n\n");
    write(quast[code]);
    write("\nThink out a solution and 'think' on it (e. g. 'think 123').\n"+
          "Hint: Find the item that is exceptional.\n");
    return 1;
}

int think(string str) {
    write("You think on "+str+".\n");
    if (str==ans[code]) {
        this_player()->move_player("by magic#"+PA+"castle/nt2.c");
        write("You are magically transferred somewhere!\n");
        return 1;
    }
    write("Nothing happens.\n");
    return 1;
}
