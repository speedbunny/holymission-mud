#define PPATH "/players/patience/smilequest/"
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";
   object cloak;
   int  opened, curtain_open, cloak_taken, ham_taken;

 reset(arg) {
   opened=0;
   curtain_open=0;
   cloak_taken=0;
   ham_taken=0;
   
  
   
   ::reset(arg);
   
 if (arg) return;
 
 smell="The air smells very fouly here !";
 set_light(-1);
 short_desc="In a dark cellar";
 long_desc=
            "You are in the dark cellar of the castle of sadness.\n"+
            "It's cold and wet. The vault smells a bit after bad wood.\n"+
            "There is a big wooden cupboard standing on the northern wall.\n"+
            "There is a small corridor leading further to the south.\n";
 items = ({
          "corridor","You see a small dark corridor, leading to the south",
          "bottom","You see a oak-wooden bottom",
          "walls","You see dark brick-walls",
          "vault","You see an oak-wooden vault",
          "wood","You see just oak-wood",
          "cupboard","@@query_cupboard@@",
          "cloak","@@query_cloak@@",
          "ham","@@query_ham@@",
          "curtain","It is @@chk_court@@, old, red curtain",
          });
          
 dest_dir = ({
             PPATH+"cellar3","south",
             });
             
  }
  
  init() {
     object rat;
     rat=present("rat",this_object());
     if (rat) {
       call_out("run_rat",2,rat);
     }
    add_action("search","search");
    add_action("open","open");
    add_action("push","push");
    add_action("push","lift");
    add_action("push","move");
    add_action("close","close");
    add_action("put","put");
    add_action("put","give");
    add_action("get","get");
    add_action("get","take");
    add_action("enter","enter");
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
   query_cupboard() {
     if (opened) {
         if (curtain_open && cloak_taken && ham_taken) {
            return "You see nothing, but the northern end of the open cupboard\n"+
                   "and a red curtain hanging on it's side";
                   }
         else if (curtain_open && cloak_taken) {
            return "You see nothing, but the northern end of the open cupboard. A red\n"+
                   "curtain hanging on it's side and a piece of ham hanging in it";
            }
         else if (curtain_open && ham_taken) {
            return "You see nothing, but the northern end of the open cupboard a red\n"+
                   "curtain hanging on it's side and a cloak hanging in it";
            }
         else if (!cloak_taken) {
            return "You see a cloak hanging in the open cupboard";
         }
         else {
             return "You see a curtain on the back of the open cupboard";
             }
          }        
       else {
         return "You see a big wooden cupboard, it's closed";
         }
       }
       
    open(arg) {
      if (arg=="cupboard" || arg=="the cupboard") {
         if (!opened) {
             write("You open the cupboard.\n");
             say(TPN+" opens the cupboard.\n");
             opened=1; 
             return 1;
            }
          else {
            write("The cupboard is already open.\n");
            return 1;
           }
          return 1;
         }
       if (arg=="curtain" || arg=="the curtain") {
          if (!opened) return;
          if (!curtain_open) {
          write("You open the curtain.\n");
          say(TPN+" opens the curtain.\n");
          curtain_open=1;
          return 1;
          }
          else {
           write("The curtain is already open.\n");
           return 1;
          }
        return 1;
        }
     return 1;
     }
   
   close(arg) {
    if (arg=="cupboard" || arg=="the cupboard") {
       if (opened) {
          write("You close the cupboard.\n");
          say(TPN+" closes the cupboard.\n");
          opened=0; 
          return 1;
        }
        else {
         write("The cupboard is already closed.\n");
         return 1;
        }
       return 1;
      }
      if (arg=="curtain" || arg=="the curtain") {
         if (!opened) return;
         if (curtain_open) {
         write("You close the curtain.\n");
         say(TPN+" closes the curtain.\n");
         curtain_open=0;
         return 1;
        }
        else {
          write("The curtain is already closed.\n");
        return 1;
        }
       return 1;
       }
     return 1;
    }
         
   push(arg) {
     if (arg!="curtain" && arg!="the curtain") {
         write("Nothing happens !\n");
         return 1;
        }
     if (!opened) return;
         if (curtain_open) {
         write("You close the curtain.\n");
         say(TPN+" closes the curtain.\n");
         curtain_open=0; 
         return 1;
        }
        else {
          write("You open the curtain.\n");
          say(TPN+" opens the curtain.\n");
          curtain_open=1;
        return 1;
        }
      return 1;
    }   
          
   get(arg) {
     object ham;
     ham=clone_object(PPATH+"ham"); 
     if (arg!="cloak" && arg!="ham" && arg!="the cloak" && arg!="the ham" &&
         arg!="cloak from the cupboard" && arg!="ham from the cupboard" &&
         arg!="cloak from  cupboard" && arg!="ham from  cupboard") return;
       
     
     if (arg=="cloak" || arg=="the cloak" || arg=="cloak from cupboard" || arg=="cloak from the cupboard") {
        if (!opened) return;
        if (cloak_taken)  return;
  
        cloak=clone_object("obj/armour");
        cloak->set_name("cloak");
        cloak->set_alias("black cloak");
        cloak->set_short("A black cloak");
        cloak->set_long("A black soft cloak.\n");
        cloak->set_weight(1);
        cloak->set_type("cloak");
        cloak->set_value(80);
        cloak->set_ac(1);
        
        if ( transfer(cloak,TP) ) {
           write( "You can't carry that much.\n" );
           destruct( cloak );
        }
        else {
           write("You take the cloak from the cupboard.\n");
           say(TPN+" takes a cloak from the cupboard.\n");
           cloak_taken=1;            
        }
        return 1;
       }
        
       if (arg=="ham" || arg=="the ham" || arg=="ham from cupboard" || arg=="ham from the cupboard") {
          if (!opened) return;
          if (ham_taken) return;
          if (!transfer(ham,TP)){
              move_object(ham,TP);
              write("You take a piece of ham.\n");
              say(TPN+" takes a piece of ham.\n");
              ham_taken=1;
              }
           else {
             write("You can't carry that much.\n");
             }
           return 1;
          }
        return 1;
       }
       
    query_ham() {
      if (ham_taken) {
          return "You can't find a ham";
         }
      else {
          return "You see a piece of ham hanging down in the cupboard";
          }
      return 1;
      }
      
     put(arg) {
       object cloak, ham;
       ham=present("ham",TP);
       cloak=present("cloak",TP);
       if (arg!="ham in cupboard" && arg!="cloak in cupboard") return;
       if (arg=="ham in cupboard") {
          if (ham) {
          write("You put the ham back into the cupboard.\n");
          say(TPN+" puts the ham back into the cupboard.\n");
          ham_taken=0;
           }
          else {
          write("You don't have a  ham !\n");
          }
         return 1; 
         }
        if (arg=="cloak in cupboard") { 
          if (cloak) {
           write("You put the cloak back into the cupboard.\n");
          say(TPN+" puts the cloak back into the cupboard.\n");
          cloak_taken=0;
          }
          else {
          write("You don't have a cloak !\n");
          } 
          return 1;
          }
        return 1;
        }
        
     enter(arg) {
       if (arg!="cupboard") return;
       write("The cupboard is to small for you to enter.\n");
       return 1;
       }
       
         
     query_cloak() {
       if (cloak_taken) {
          return "You can't find a cloak";
          }
       else {
          return "You see a black cloak hanging down in the cupboard";
          }
       return 1;
       }
       
chk_court( )
{
   if ( curtain_open )
      return( "an open" );
   else
      return( "a closed" );
}    
                        
