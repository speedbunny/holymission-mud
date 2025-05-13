#define TP this_player()
#define SAY(x) tell_room(environment(),x)

inherit "obj/monster";
   string msg1,msg2,msg3,msg4,msg5,msg6;
   int happy;
 
  reset(arg) {
    happy=0;
    ::reset(arg);
    
  if (arg) return;
  
   set_name("The girl");
   set_alias("girl");
   set_alt_name("sad girl");
   set_short("A sad girl");
   set_long(
            "You see a little sad girl, big teardrops are running down her eyes.\n"+
            "She looks as if she had seen better days, but since her mother died\n"+
            "she is really unhappy and cant even smile any more.\n");
   set_level(2);
   move_object(clone_object("obj/soul"),this_object());
   }
   
   glook() {
     if (random(100)<80) { command("look"); }
     else {
     command("sigh");
     }
    call_out("glook",20);
    return 1;
    }
   
   catch_tell(arg) {
       string str1;
       object hat, shoes, nose, cloak;
       
       hat=present("fhat",TP);
       shoes=present("fshoes",TP);
       nose=present("fnose",TP);
       cloak=present("fcloak",TP);
       
    if (sscanf(arg,"%s arrives.",str1)==1) {
         msg1="The girl cries bitterly.\n";
         msg2="The girl says: I am sooo unhappy since my mother died.\n";
         msg3="The girl burst into tears.\n";
         msg4="The girl says: I am sooooo unhappy, I wanna die.\n";
         msg5="The girl says: Only Bonzo could make me happy.\n";
         msg6="Big tears are running from the cheeks of the girl.\n";
         call_out("m1",2);
        return 1;
       }
        
    if ((sscanf(arg,"%s does the disco duck.",str1)==1) || (sscanf(arg,"%s sweeps you across the dance floor.",str1)==1)) {
       if ((hat && hat->query_worn()) && (shoes && shoes->query_worn()) && (nose && nose->query_worn()) && (cloak && cloak->query_worn())) {
          msg1="The girl laughs loudly !\n";
          msg2="The girl flips head over heals.\n";
          msg3="The girl says: Bonzo didn't ever make it better.\n";
          msg4="The girl giggles happily.\n";
          msg5="The girl laughs happily at you.\n";
          msg6="The girl says never seen such a funny person.\n";
          happy=1;
          this_player()->set_quest("smilequest");
          call_out("m1",2);
          }
        else if ((hat) || (shoes) || (nose) || (cloak)) {
          msg1="The girl smiles sadly.\n";
          msg2="The girl says: Bonzo was much better than you.\n";
          msg3="The girl sulks in the corner.\n";
          msg4="The girl says: With old Bonzo I could really laugh.\n";
          msg5="The girl cries bitterly.\n";
          msg6="The girl says: I am sooooo unhappy !\n";
          call_out("m1",2);
         }
        else {
           msg1="The girl cries bitterly.\n";
           msg2="The girl says: I am sooo unhappy since my mother died.\n";
           msg3="The girl burst into tears.\n";
           msg4="The girl says: I am sooooo unhappy, I wanna die.\n";
           msg5="The girl says: Only Bonzo could make me happy.\n";
           msg6="Big tears are running from the cheeks of the girl.\n";
           call_out("m1",2);
        return 1;
       }
       return 1;
       }
     
     return 1;
     }
           
   m1() {
    SAY(msg1);
    call_out("m2",4);
    }
   m2() {
    SAY(msg2);
    call_out("m3",4);
    }
    
   m3() {
    SAY(msg3);
    call_out("m4",4);
    }
    
   m4() {
    SAY(msg4);
    call_out("m5",4);
    }
   
   m5() {
    SAY(msg5);
    call_out("m6",4);
    }
    
   m6() {
    SAY(msg6);
    }
    
   query_happy() {
     if (happy) return 1;
     return;
     }
     
    
        
    
