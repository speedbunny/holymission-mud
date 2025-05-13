
#define TP  this_player()
#define TPN TP->query_name()
#define TO  this_object()
#define TPR TP->query_real_name()
#define E   environment
#define F1  "/players/whisky/island/room/gnome2"
#define F2  "/players/whisky/island/room/gnome4"
#define F3  "/players/whisky/island/room/gnome8"
        
inherit "obj/container"; 
   
 reset(arg) {

  ::reset(arg);
  if (arg) return;
    set_name("catapult");
    set_alias("big catapult");
    set_max_weight(1000); 
    set_short("A big Catapult");
    set_long("You see a big wooden Catapult. It looks like a big shovel,\n"+
             "with a strong rope on it. There is big iron sign on it.\n");
    set_value(0);
    set_weight(1000);
}

    init() {
      add_action("do_say","say");
      add_action("do_read","read");
      add_action("do_enter","enter");
      add_action("do_leave","leave");
      ::init();
      }
      
    do_read( arg ) {
    
       if ( !arg && arg!="sign" ) return ( 0 );
       
       write("CatapultVersion2000:\n\n"+
             "TypeEnterCatapultAndWeWillPutYouInThenSayInWhichFloor\n"+
             "YouWantToBeShotWeOfferFloor 1 , 2 Or 3\n\n");
             
      return ( 1 );
      }
      
     do_enter( arg ) {
     
         if ( arg!="catapult" || !arg ) {
             notify_fail("Enter what ?\n");
     
         } else if ( (!check_loaded() ) && (!present(TPR,TO)) ) {
              TP->set_vis();
              write("You enter the catapult.\n");
              say(TPN+" enters the catapult.\n");
              move_object(TP,TO);
              
              
         } else if ( present(TPR,TO) ) {
            write("You are already in the catapult.\n");
            
         } else {
           write("The Catapult seems to small for 2 people to enter.\n");
           }
         
        return ( 1 );
       }
       
       
      do_leave( arg ) {
      
           if ( arg!="catapult" ) {
             notify_fail("Leave what ?\n");
     
         } else if ( present(TPR,TO ) ) {
         
              write("You leave the catapult.\n");
              tell_room(E(TO),TPN+" leaves the catapult.\n");
              move_object( TP,E(TO) );
              
              
         } else  {
            notify_fail("You aren't in the catapult.\n");
           }
         
        return ( 1 );
       }


       do_say( arg ) {
         
         if ( arg!="floor 1" && arg!="floor 2" && arg!="floor 3") {
             return ( 0 );
            }
            
         
        if ( !present("gnome",E(TO) ) ) {
           write("But, there is nobody here to activate the catapult.\n");
           return ( 1 );
        }
                
          if ( !check_loaded() ) {
             notify_fail("A Gnome says: SorryButThereIsNobodyIn.\n");
             
          } else if ( !present(TP,TO) ) {
             tell_room(E(TO),"A Gnome shrugs helplessly.\n");
             
            return ( 1 );
            }
            
          switch( arg ) {
            
            case "floor 1":
            
                if ( random(100) < 90 ) { 
                
                   fling( F1 , TP , 1);
                  
                } else if (random(100) < 95) {
                   fling( F2 , TP, 2);
                   
                } else {
                   fling( F3 , TP, 2);
                }
                
             break;
         
            case "floor 2":
             
                if ( random(100) < 90 ) { 
                
                   fling( F2 , TP , 1);
                  
                } else if (random(100) < 95) {
                   fling( F1 , TP, 0);
                   
                } else {
                   fling( F3 , TP, 2);
                }
             break;
            
            case "floor 3":
            
               if ( random(100) < 90 ) { 
                  fling( F3 , TP , 1);
                  
                } else if (random(100) < 95) {
                   fling( F2, TP, 0);
                   
                } else {
                   fling( F1, TP, 0);
                }
                 
                break;
            
            default: return ( 0 );
            
           return ( 1 );
           }
       
       return ( 1 );
      }
           
           
     fling( where , ob , stat) {
            
        tell_object(ob,
            "A Gnome activates the catapult FlINGGGGGGG\n\n"+
            "Suddenly the catapult throws you HIGH UP INTO THE AIR !!!!\n\n");
            
        if (stat==1) {
           
            tell_object(ob,
               "With a speed of nearly 100 miles/hour you crash against the SECURITY NET !!\n");
            
            
        } else if (stat==2) {
                     
            tell_object(ob,
               "But SHIT You fly too wide with a speed of nearly 100 miles/hour\n"+
               "you crash against the SECURITY NET one floor higher !!\n");
        
        } else {
        
           tell_object(ob,
               "But SHIT You fly too short with a speed of nearly 100 miles/hour\n"+
               "you crash against the SECURITY NET one floor lower !!\n");
         }
         
         
         move_object(ob,where);
         
         tell_room(E(TO),
              "A Gnome activates his catapult and "+ob->query_name()+"\n"+
              "flies high up into the air !\n");
              
          
         
        return ( 1 );
        }
 
        
     check_loaded() {
       object inv;
       int i;      
       
       inv = all_inventory( TO );
       
       for( i=1 ; i<sizeof(inv) ; i++ ) {
          if ( inv[i]->query_player() ) return ( 1 );
            }
        
        return ( 0 );                 
     }
           
  get() { return ( 0 ); }      
          
          
        
         
         
               
