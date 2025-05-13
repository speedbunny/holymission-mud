#define SAY(x) tell_room(environment(),x)

inherit "obj/monster";
  string mess1, mess2, mess3, mess4; 
   

 reset(arg) {
   ::reset(arg);
   
 if (arg) return;
 
 set_name("king");
 set_alias("sad king");
 set_short("A sad king");
 set_long(
          "A very sad looking human, covering his face with both hands.\n"+
          "He looks like a very mighty man, but very sad.\n"); 
 set_level(40);
 set_gender(1);
 move_object(clone_object("obj/soul"),this_object());
 }
 
 clook() {
   command("look");
   call_out("clook",20);
  }
  
 catch_tell(arg) {
   string str1;
   
   if (sscanf(arg,"%s arrives.",str1)==1) {
      command("sigh");
      mess1="The king cries bitterly.\n";
      mess2="The king says: I am so sad nobody can make my daughter happy.\n";
      mess3="The king bursts into tears.\n";
      mess4="The king says: I really could die.\n";
      call_out("ctalk1",4);
      return 1;
     }     
    return 1;
  }
     
     ctalk1() {
      SAY(mess1);
      call_out("ctalk2",4);
      }
      
     ctalk2() {
      SAY(mess2);
      call_out("ctalk3",4);
      }
     ctalk3() {
      SAY(mess3);
      call_out("ctalk4",4);
      }
     ctalk4() {
      SAY(mess4);
      }
     
     
     
     
   
 
