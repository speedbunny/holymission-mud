#define SAY(x) tell_room(environment(),x)
#define PPATH  "/players/patience/smilequest/"

inherit "obj/monster";
  string mess1, mess2, mess3, mess4;
status noseIsHere;
   

 reset(arg) {
   ::reset(arg);
   
 noseIsHere = 1;
   
 if (arg) return;
 
 set_name("clown");
 set_alias("sad clown");
 set_short("A sad clown");
 set_long(
          "A very sad looking human sitting on the floor, covering his face\n"+
          "with his both hands. He looks as if he had seen better days.\n"); 
 set_level(3);
 set_gender(1);
 transfer(clone_object("obj/soul"),this_object());
 }
 
 clook() {
   command("look");
   call_out("clook",20);
  }
  
 catch_tell(arg) {
   string str1;
   object nose;
   
   if (sscanf(arg,"%s arrives.",str1)==1) {
      command("sigh");
      mess1="The clown cries bitterly.\n";
      mess2="The clown says: I am soo sad that i can't make the princess happy any more.\n";
      mess3="The clown bursts into tears.\n";
      mess4="I am so sad, I wish anybody could give me a hug.\n";
      call_out("ctalk1",4);
      return 1;
     }
     
     else if (sscanf(arg,"%s hugs you.",str1)==1) {
      command("thank "+this_player()->query_name());
      mess1="The clown says: Well, that is good.\n";
      mess2="The clown says: Nobody has hugged me for years.\n";
      mess3="The clown bursts into tears.\n";
      mess4="The clown says: Maybe you can make the little girl happy.\n";
      
      if ( noseIsHere ) {
         nose = clone_object(PPATH + "cnose");
         if (transfer(nose,this_player())) {
            write( "But you can't carry that much.\n" );
            destruct( nose );
         }
         write("The clown gives you his nose.\n");
         noseIsHere = 0;
      }
      
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
     
     
     
     
   
 
