#define PPATH "/players/patience/smilequest/"
inherit "room/room";
   

 reset(arg) {
   
   ::reset(arg);
   
 if (arg) return;
 
 smell="The air smells very fouly here !";
 set_light(-1);
 short_desc="In a dark cellar";
 long_desc=
            "You are in the dark cellar of the castle of sadness.\n"+
            "It's cold and wet. The vault smells a bit after bad wood.\n"+
            "There is a small corridor leading further to the south and west.\n";
 items = ({
          "corridor","You see a small dark corridor, leading to the south and west",
          "bottom","You see a oak-wooden bottom",
          "walls","You see dark brick-walls",
          "vault","You see an oak-wooden vault",
          "wood","You see just oak-wood",
          });
          
 dest_dir = ({
             PPATH+"cellar2","south",
             PPATH+"cellar_entry","west",
             });
             
  }
  
  init() {
     object rat;
     rat=present("rat",this_object());
     if (rat) {
       call_out("run_rat",2,rat);
     }
    add_action("search","search");
    ::init();
    }
    
   search(arg) {
     
     if (!arg) 
        return;
     write("You search and search, but find nothing.\n");
     say(this_player()->query_name()+" searches around.\n");
   return 1;
    } 
    
   run_rat(rat) {
      rat->run_away();
      }
   
      
