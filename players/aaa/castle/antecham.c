/* Finished 07.02.1995 */

#include <std.h>
#include "/players/aaa/defs.h"

inherit "/room/room";

int s,n;

void reset(int arg) {
    object ob;
    n==0;
    s==0;
    ::reset();
    if (arg) return;
    property=({"no_teleport"});
    set_light(1);
    short_desc="Castle of Aaa - antechamber";
    long_desc="This is the antechamber in the castle of Aaa. The walls "+
     "are made of solid stone and gleam in a strange blue light. There "+
     "is a window on the eastern wall, the light is coming from that "+
     "direction. You stand under "+
     "the middle tower, where black marble stairs lead up. You remember "+
     "that the castle has three towers - where the other two can be?\n"+
     "You notice a sign just opposite to the enterance.\n"+
     "The exit is a door, leading west.\n";
     items=({"stair","They are leading up",                                    
            "stairs","They are leading up",                                    
            "wall","Their light is probably induced by magic. Maybe these"+    
                   " walls are hiding something",                              
            "walls","Their light is probably induced by magic. Maybe these"+   
                   " walls are hiding something",                              
            "window","It is made of special, unbreakable magic glass",         
            "sign","You are not surprised that it is written in "+      
                   "the common language",                                      
            "exit","A closed metal portal",                                     
            "door","A closed metal portal",      
            "portal","A closed metal portal"});     
    dest_dir=({PA+"castle/prg_room.c","up"});
}

void init() {
    ::init();
    add_action("go_north","north");
    add_action("go_south","south");
    add_action("read","read");
    add_action("touch","touch");
    add_action("search","search");
    add_action("open","open");
    add_action("leave","leave");
    add_action("bbreak","break");
}

int read(string str){
    if(!str) {
        notify_fail("Nice hobby!\n");
        return 0;
    }
    if (str!="sign") {
        notify_fail("You can only read something containing letters.\n");
        return 0;
    }
    write("The sign reads:\n"+
          "I admire Your courage. Welcome to my castle!\n"+
          "But remember, though, that some dangerious monsters live in "+
          "the towers, so going\n"+
          "upstairs only on your own risk.\n\n"+
          "Have a good time!\n"+
          "Wizard Aaa\n");
   return 1;
}

int touch(string str){
    int a,b;
    if(!str) {
        notify_fail("You are not a nihilist, can't touch the void!\n");
        return 0;
    }
    if(((str=="wall") || (str=="walls")) && (!n)) {
        write("You touch around the walls and reveal that a "+
          "considerable part of\nthe northern wall is illusion!\n");
        say(this_player()->query_name()+" touches around the walls, and "+
            "reveals that\na considerable part of the northern wall is "+
            "illusion!\n");
        n=1;
        return 1;
    }                                                         
    a=((str=="window") || (str=="sign") || (str=="door") || (str=="exit"));
    b=((str=="portal") || ((str=="wall") && (n)) || ((str=="walls") && (n)));
    if (a || b) {
        write("You can feel nothing special.\n");
        return 1;
    }
    notify_fail("You can't touch something that is not here!\n");
    return 0;
}

int go_north() {
    if (n==1) {
        this_player()->move_player(" north, through the wall#"+PA+"castle/nt1");
        n=0;
        return 1;
    }
    write("You would probably bang your head on the wall!\n");
    return 1;
}

int go_south() {
    if ((s==1) && present("anti-field emitter",this_player())) {
        this_player()->move_player(" south, through the wall#"+PA+"castle/st1");
        s=0;
        return 1;
    }
    if (s==1) {
        write("Ouch, that hurts! Luckily, the wall at least hasn't burned"+
              " you!\n");
        say(this_player()->query_name()+" runs into the south wall and seems "+
            "to be surprised that the wall is there.\n");
        return 1;
    }
    write("You would probably bang your head on the wall!\n");
    return 1;
}

int search(string str) {
    if ((!str) || ((str!="wall") && (str!="walls"))) {
        notify_fail("You search and search, but find nothing.\n");
        return 0;
    }
    if (s==1) {
          write ("You find nothing new.\n"+
          "Perhaps you should use not only your eyes, but hands as well?\n");
          return 1;
    }
    s=1;
    write("During closer inspection of the south wall, you find that "+
          "this wall is made of\npure power...\n"+
          "You have heared about the spell 'Wall of force' - this is similar, "+
          "but stronger and seems to be permanent. Perhaps a proper item may "+
          "help to penatrate it.\n");
    say(this_player()->query_name()+" searches the walls, and seems to find "+
        "something\n");
    return 1;
}

int bbreak(string str) {
    if (!str) {
        notify_fail("Hey, a professional break-dancer!\n");
        return 0;
    }
    if ((str=="door") || (str=="west door")) {
        write("This door is at least 10 centimeters [4 inches] thick,\n"+
              "so you wouldn't have chance even if it weren't made of "+
              "very strong metals.\n");
    return 1;
    }
    if ((str=="south door") && (s)) {
        write("You run into the south door and try to break it with "+
              "your shoulder. Total failure! This must be magic!\n");
        say(this_player()->query_name()+" tries to force the south door "+
           "but fails.\n");
        return 1;
    }
    if (str=="window") {
        write("The window is made of magical glass, so unbreakable.\n"+
              "Ouch! You hurt yourself!\n");
        say(this_player()->query_name()+" tries to break the window, but "+
            "fails.\n");
        return 1;
    }
    notify_fail("You can't break that, especially as that is not here!\n");
    return 0;
}

void op() {                                                                    
    object ob;                                                                 
    say(this_player()->query_name()+" opens the door.\nCraaaaaaaaaaack...\n"); 
    if(ob=find_object(PA+"area1/ante_castle.c")) tell_room(ob,"The door "+    
                            "opens.\nCraaaaaaaaaaak....\n");                   
}                                                                              
                                                                               
void cl() {                                                                    
    object ob;                                                                 
    tell_room(this_object(),"The door closes.\nHasssssssssssssh!\n");          
    if(ob=find_object(PA+"area1/a_castle.c")) tell_room(ob,"The door "+    
                             "closes.\nHasssssssssssssh!\n");                  
}                                                                              
                                                                               
int open(string str) {                                                         
    if ((!str) || ((str!="door") && (str!="portal"))) {                        
        notify_fail("Open what?\n");                                           
        return 0;                                                              
    }                                                                          
    op();                                                                      
    write("Craaaaaaaaaaack...\nWith great effort, you open the door.\n"+   
          "But won't escape so easy! An invisible force closes it!\n");    
    cl();                                                                      
    write("Perhaps, and only perhaps, you can leave by typing 'leave'.\n");   
    return 1;                                                                  
}                                                                              
                                                                               
int leave(string str) {    
    int a;                                                  
    if(str) {     
        notify_fail("You can't go there! If you want to leave, type just "+
                    "'leave'!\n");                                         
        return 0;                                                              
    }                                                                          
    write("Craaaaaaaaaaack...\nWith great effort, you open the door.\n");      
    op();                    
    a=random(35)+(this_player()->query_dex());
    if(a<25) write("This time, the demon or whatever was faster! The door "+
                   "closes\nbefore you could leave.\n");    
    if((a==25) || (a>25))
        this_player()->move_player(" the castle#"+PA+"area1/a_castle.c");   
    cl();                                                                      
    return 1;                                                                  
}                                                                              
