
/* Completed 19.02.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";
int progress; /* 1 if game in progress, 0 otherwise */
string plr; /* Name of the current opponent of the math-demon */
string rules="We start with 0, and the first player can add an integer "+
            "number to it. At least 1 must be added, and at most 10 can be. "+
            "Then it's the other player's turn, who\ncan do the same. After "+
            "it, the first player comes again, and so on, alternately.\n"+
            "The winner is the one who reaches 100.\n"+
            "We will play 5 rounds of this game. Not less, not more.\n"+
            "You can recall the rules bye 'rules', see the current state of "+
            "the game by\n'game' and make your move by 'play <number>', where"+
            " <number> is how much you\nwant to add.\n";
int demon_win,player_win,sum;

void reset(int arg) {
    ::reset(arg);
    if ((!plr) || (!present(plr))) progress=0;
    if(arg) return;
    set_light(-30);
    property=({"no_teleport"});
    short_desc="dark room";
    long_desc="It is dark.\n";
    dest_dir=({PA+"castle/nt1.c","down"});
    items=({ });   
}

void start_game() {                                                            
    if ((progress) && (this_player()->query_real_name()==plr)) { 
        write("You can hear a terrific whisper:\n");                           
        write("Ah, you back! I could hardly wait, ha-ha.\n");                  
        return;                                                                
    }  
    if (progress) return;
    write("You can hear a terrific whisper:\n");                               
    write("I am a demon, a demon without body. But don't think i can't "+      
          "hurt you! Once i\nmade a mistake: i've attacked the great wizard "+  
          "Aaa. Since then, i'm imprisoned\nhere and my work is to guard the "+ 
          "tower. My defeator's command was: 'Only the\nintelligent shall "+    
          "pass'. So, if you feel smart enough, you can 'challenge' me\nfor "+  
          "a game. If not, you can always go down. Perhaps, that's the wise "+ 
          "decision!\n");
    return;                                                                    
}                                                                              

void init() {
    ::init();
    add_action("challenge","challenge");
    add_action("rules","rules");
    add_action("game","game");
    add_action("play","play");
    add_action("up","up");
    call_out("start_game",3,0);
}

void player_won() {                                                            
    write("The demon crawls:\nA simple mortal out-foxed me!\n"+ 
          "What a shame!\n");                                                  
    this_player()->move_player("by magic#"+PA+"castle/nt3");                   
    progress=0;                                                                
    return;                                                                    
}                                                                              
                                                                               
void player_lost() {                                                           
     write("You lost! Get out of here, puny creature "+                        
            "and be happy that i spare your\npathetic life!\n"); 
     this_player()->move_player("by magic#/room/church");                      
     progress=0;                                                               
}                                                                              

int play(string str) {
    int arg;
    if((!progress) || (this_player()->query_real_name()!=plr)) {
        notify_fail("What ?\n");
        return 0;
    }
    if ((!to_int(str)) && (str!="0")) {
        notify_fail("You can only add an integer number! Type 'rules' "+
                    "if forgot them.\n");
        return 0;
    }
    arg=to_int(str);
    if (arg>10) {
        write("You hear a frightening whisper:\n"+
              "You can add at most 10 !\n");
        return 1;
    }
    if (arg<0) {
        write("You hear a frightening whisper:\n"+
              "You can't substract!\n");
        return 1;
    }
    if (arg==0) {
        write("You hear a terrific whisper:\n"+
              "You must add at least 1!\n");
        return 1;
    }
    sum=sum+arg;
    write("You say: I add "+arg+", that comes to "+sum+".\n");
    if ((sum==100) || (sum>100)) {
        write("The demon growls at you:\n"+
              "Hey, you won this game!\n");
        player_win++;
        if (player_win+demon_win==5) {
            if (player_win>demon_win) {
                player_won();
                return 1;
            }
            write("But i won more than you!\n");
            player_lost();
            return 1;
        }
        write("But it was not the last game! Now I will be first.\n"+          
              "Hm, i add 1, that is, 1 is the result.\nNow it's your turn.\n");
        /* Player can only win if she/he was the first. Yep, first player 
        has a winning strategy, and however demon is coded in such a way 
        that he knows this strategy */
        sum=1;                                                                 
        return 1;                                                              
    }           
    arg=random(10)+1;  
    if (((sum-1)%11)!=0) arg=11-((sum-1)%11);
    if (arg>10) arg=arg-10;  
    sum=sum+arg;
    write("Demon whispers:\n"+
          "I add "+arg+" , that is, "+sum+" is the result.\n");
    if ((sum==100) || (sum>100)) {
        write("He-he, i won!\n");
        demon_win++;
        if (demon_win+player_win==5) {
            player_lost();
            return 1;
            /* Since surely demon won the 2nd and 4th game, if the 5th is
               his again, the player must have lost */
        } 
        write("But it was not the last game!\n");
        if ((demon_win+player_win)%2) {
            write("Now I will be first.\n"+
            "Hm, i add 1, that is, 1 is the result.\nNow it's your turn.\n");
            sum=1;
            return 1;
         }
        write("You are the first now.\n");
        sum=0;
        return 1;
    }                                                                          
    write("Now it's your turn.\n");
    return 1;
}
        
int game(string str) {
    if((!progress) || (this_player()->query_real_name()!=plr)) {
        notify_fail("What ?\n");                                               
        return 0;                                                              
    }                                                                          
    if (str) {                                                                 
        notify_fail("If you want to see the state of the game, type just "+
                    "'game'.\n");  
        return 0;                                                              
    }                                                                          
    write("You won "+player_win+" games so far, and the demon won "+
          demon_win+".\nThe current sum is "+sum+". It is your turn.\n");
    return 1;
}

int rules(string str) {
    if((!progress) || (this_player()->query_real_name()!=plr)) {
        notify_fail("What ?\n");                                               
        return 0;                                                              
    }                                                                          
    if (str) {                                                                 
        notify_fail("If you want to recall the rules, type just 'rules'.\n");  
        return 0;                                                              
    }                                                                          
    write(rules);
    return 1;
}

int challenge(string str) {    
    if(str) {
        if (progress) {
            if (this_player()->query_real_name()==plr) {
                notify_fail("You can hear a terrific whisper:\n"+
                            "We are already playing!\n");
                return 0;
            }
            notify_fail("You can hear a terrific whisper as if coming from "+  
                        "a grave:\nWait for your turn!\n");                     
            return 0;                                                          
            /* This branch was made for the case that the player may have
            something with her/him to challenge, so i can only notify_fail
            her/him that game against demon is in progress :) */
            }
        notify_fail("You can hear a terrific whisper:\n"+
        "If you really want to challenge me, type simple 'challenge'!\n");
        return 0;
    }
    if(progress) {
        if (this_player()->query_real_name()==plr) { 
            write("You can hear a terrific whisper:\n"+
                  "We are already playing!\n");
            return 1;
        }
        write("You can hear a terrific whisper as if coming from "+  
              "a grave:\nWait for your turn!\n");                     
        return 1;
    }
    write("You say: 'Someone else already defeated you, why i can't? "+
          "We will see, who of\nus is better!'\n");
    write("You can hear a terrific whisper:\n"+
          "Good, mortal, let's see! The game is very simple:\n"+rules);
    progress=1;
    plr=this_player()->query_real_name();
    sum=0;
    demon_win=0;
    player_win=0;
    write("I give you a chance: you are the first in the first game!\n");
    return 1;
}

int up(string str) {
    if(str) {
        notify_fail("What ?\n");
        return 0;
    }
    if (lower_case(this_player()->query_real_name())=="aaa") {
        this_player()->move_player("by magic#"+PA+"castle/nt3.c");
        return 1;
    }
    write("What ?\n");
    return 1;
}
