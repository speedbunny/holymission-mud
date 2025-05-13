/* Completed 29.01.1995. */

#include "/players/aaa/defs.h"
#include <std.h>
#include "/obj/door.h"

inherit "room/room";

void reset(int arg) {
    if(arg) return;
    set_light(1);
    short_desc="Aaa's castle, enterance";
    long_desc="This is the enterance to the castle of Aaa, the NOTORIOUS "+
        "black wizard. You have a strange feeling and suspect ancient "+
         "evil nearby. The silence is terrible. The castle is made of black "+
         "marble, but seems to be darker than it should be.\n"+
         "There is a SIGN on the wall that might be important.\n";
    dest_dir=({PA+"area1/ewroad1.c","west"});
    items=({"castle","Built of black marble, in a really odd style. In fact, "+
                     "it consist of nothing but three towers",
            "tower","Please, be more specific, there are three: left, right "+ 
                    "and middle",                                              
            "towers","There are three of them. The middle one is higher than "+
                     "the other two",
            "left tower","It's 20 meters [66 feet] high",
            "right tower","It's 20 meters [66 feet] high",
            "middle tower","It's 50 meters [164 feet] high and crowned with "+
                           "an upside-down cross",
            "cross","It is HUGE, and surely made of massive GOLD. Whoever "+   
                    "lives here must be STRONG if was able to collect and is "+
                    "able to keep such wealth. Some birds are circling around"+ 
                    " the cross",                                        
"upside-down cross","It is HUGE, and surely made of massive GOLD. Whoever "+ 
                    "lives here must be STRONG if was able to collect and is "+
                    "able to keep such wealth. Some birds are circling around"+ 
                    " the cross",                                        
            "birds","Vultures. They would enjoy playing with "+
                    "your eyes",
            "sign","There is something written on it, perhaps in the common"+
                   " language",
            "door",
               "A huge, 5 meter [17 feet] high portal. Too high even for "+    
               "a giant. It's made of\nvery strong metals and you guess "+     
               "its thickness is at least 10 centimeters\n[4 inches]",      
            "portal",
               "A huge, 5 meter [17 feet] high portal. Too high even for "+    
               "a giant. It's made of\nvery strong metals and you guess "+     
               "its thickness is at least 10 centimeters\n[4 inches]"});   
}

void init() {                                                                  
    ::init();                                                                  
    add_action("read","read");                                                 
    add_action("open","open"); 
    add_action("enter","enter");                                              
} 
                                                                             
int read(string str) {
    if (!str) {
        notify_fail("Nice hobby!");
        return 0;
    }
    if (str!="sign") {
        notify_fail("You can only read things that contain letters!");
        return 0;
    }
    write("This should be a welcome message... let's see...\n\nIt reads:\n"+
          "\n     You do not like death, i do not like trespassers.\n"+
          "     I think we got a deal.\n\n          Wizard Aaa\n\nHuh?\n");
    return 1;
}
                                                                               
void op() {                                                                    
    object ob;                                                                 
    say(this_player()->query_name()+" opens the door.\nCraaaaaaaaaaack...\n"); 
    if(ob=find_object(PA+"castle/antecham.c")) tell_room(ob,"The door "+   
                            "opens.\nCraaaaaaaaaaak....\n");                   
}                                                                              
                                                                               
void cl() {                                                                    
    object ob;                                                                 
    tell_room(this_object(),"The door closes.\nHasssssssssssssh!\n");          
    if(ob=find_object(PA+"castle/antechamber.c")) tell_room(ob,"The door "+   
                             "closes.\nHasssssssssssssh!\n");                  
}                                                                              

int open(string str) {                                                       
    if ((!str) || ((str!="door") && (str!="portal"))) {                        
        notify_fail("Open what?\n");                                           
        return 0;                                                              
    } 
    op();  
    write("Craaaaaaaaaaack...\nWith great effort, you open the door "+
          "which seems not to have happened for ages.\n"+
          "But while you hesitate whether you should enter or not, an "+
          "invisible force\ncloses it!\n");
    cl();        
    write("If you are REALLY determined to enter the castle, 'enter'.\n");
    return 1;
}  

int enter(string str) {
    if ((!str) || ((str!="door") && (str!="portal") && (str!="castle"))) {  
        notify_fail("Enter where?\n");
        return 0;
    }
    write("Craaaaaaaaaaack...\nWith great effort, you open the door.\n"); 
    op();  
    this_player()->move_player(" in the castle#"+PA+"castle/antecham.c");  
    cl();  
    return 1;
}       
