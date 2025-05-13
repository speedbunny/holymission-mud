/* Completed 05.05.1995. */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";
  int smoking;

void reset(int arg) {
object ob;
    ::reset(arg);
    set_light(1);
    short_desc="Strange room in Aaa's castle";
    long_desc="Strangly, this room has no windows, still it isn't dark here.\n"+
          "After a moment you notice that the light is coming from a\n" +
          "box that stands at the corner, on a table.\n" +
          "A man is sitting next to the box, running his fingers on a\n"+
          "plane, square thing. There is also a round thing on the table.\n"; 
    dest_dir=({PA+"castle/ante_dem.c","up",
               PA+"castle/antecham.c","down"});
   items=({"corner","A large table stands here with a magic-looking box on it",
    "table","An old, rusty table at the corner. There are an odd box, a"+
          "plane, square thing and a round thing on it",
    "thing","Which one do you mean? There are two: a square thing and a\n"+
              "round thing",
    "computer","There can't possibly be a computer here! Anyway, what is\n"+
           "a computer? I guess, only a strange word",
    "ashtray","A porcelain ashtary. It containes doezens of cigarette stabs",
    "round thing","A porcelain ashtray. It conaines doezens if cigarette "+
        "stabs",
    "plane thing","There are a lot of little cubes "+ 
         "attached to it, with a magic rune on each. The man presses them, "+
         "one after the other. Maybe someone dies when he uses the proper "+
         "combination. You wonder what your code is", 
     "square thing","There are a lot of little cubes "+ 
         "attached to it, with a magic rune on each. The man presses them, "+
         "one after the other. Maybe someone dies when he uses the  proper "+
         "combination. You wonder what your code is",
     "box","An 50 cm x 40 cm x 40 cm [ 20\" x 15\" x 15\"] box, that "+
         "dominates the room. One of its sides is made of a glass-like"+   
         "material, and the box emanates here such much light that"+
         "you can see. Somehow, runes can also be seen on the glass, but"+
         " the pattern changes without a stop. You quickly make the sign"+ 
         "of the cross in order to keep the evil away from yourself"});
    ob=present("aaa-programmer");
    if((!ob) || (!living(ob))) {
        ob=clone_object(PA+"castle/prgrmmer.c");
        move_object(ob,this_object());
    }       
}

void init() {
    ::init();
    add_action("smell_fv","smell");
    add_action("listen_fv","listen");
}
 
int smell_fv(string str) {
    if(!str) {
        write("You can smell the smoke of burning.\n"); 
        return 1;
    }
    if (str=="round thing") {             
        write("It's very smelly. You almost puke!\n");    
        return 1;             
    }
    notify_fail("You can't feel anything special.\n");
    return 0;
}    
                                                                              
int listen_fv(string str) {
    if(!str) {
         write("You can hear low, clicking sounds coming from the corner.\n");
         return 1;
    }
    if (str=="corner") {
         write("Yes, the clicking is coming from somewhere here...\n");
         write("Maybe the box?\n");
         return 1;
    }
    if (str=="box") {
         write("No, not the box - that is silent.\n");
         return 1;
    }
    if (str=="round thing") {
         write("Quiet, like a fish.\n");
         return 1;
    }
    if (str=="square thing" || str=="plane thing") {
       write("Yess! Whenever the man moves his fingers, a low 'click!' can\n");
         write("be heared.\n");
         return 1;
    }
    notify_fail("You can't hear anything interesting.\n");
    return 0;
}
