/* ############################################################################## 

                D R A G O N A I R L I N E    ( WHISKY && WARLORD (c))
                
   ############################################################################## */

#define TO  this_object()
#define TP  this_player()
#define TPN TP->query_name()
#define TPR TP->query_real_name()
#define TPP TP->query_possessive()
#define E   environment
#define DEST1 "/players/whisky/seaworld/room/sea_way2"
#define DEST2 "/players/whisky/island/room/island22"
   
   inherit "obj/monster";
      object me;
      int fly, mounted;
      string where;
   
     reset(dragon) {
        
        ::reset(dragon);
      
      if (!dragon) {
        
        set_name("dragon");
        set_living_name("trans_dragon");
        set_short("A friendly-green dragon");
        set_gender(2);
        set_level(60);
        me=TO;          /* just to get sure */
        enable_commands();
       }
      }
      
      query_light() {
          return ( 1 );
          }
  
  long( arg ) {
  
      if (present(TPR,E ( me ) ) ) {
           write("You see a mighty 80 feet high, green dragon.\n"+
                 "she is one of the famous members of the big\n"+
                 "dragon-airline. It seems like if you mount her\n"+
                 "she might bring you to a different place !\n");
         } else if (fly) {
           write("You see the back of the friendly-red dragon and\n"+
                 "you see some buildings of holy missions very little\n"+
                 "from your high point. Some wheels are passing by.\n");
         } else {
            write("You see the back of the friendly red dragon, you\n"+
                  "recognize that she is now in:\n\n"+                
                   E ( me )->short()+"\n\n");
             }
         }
                  
     
                   
      init() {
        add_action("do_mount","mount");
        add_action("do_kick","kick");
        add_action("do_leave","leave");
        ::init();
        }
        
      hit_player( dam ) {
         
          if (mounted) {
              return ( 0 );
             }
          
          return ::hit_player(dam);
       }
           
     attack() {
        
        if (::attack()) {
        
           tell_room(E(me),"The dragon leaves high up into the air\n");
           
           if ("/"+file_name(E(me))==DEST1) {
              move_object(me,DEST1);
            } else {
              move_object(me,DEST2);
           }
         }
       
       return ( 1 );
     }
       
           
      /*   *** mount   ***  */
        
      do_mount ( arg ) {
      
         if ( !id( arg ) ) {
             notify_fail("Mount what ?\n");
           
         } else if (present(TPR,E(me))) {
             tell_room(E(me),TPN+" mounts the dragon !\n");
             write("You get the feeling you should kick the dragon for a ride.\n");
             move_object( TP,me );
             mounted = 1;
            
          } else {
             write("You are just sitting on the dragon.\n");
           }
         
         return ( 1 );
        }
       
      do_leave( arg ) {
      
        if ( ( !id( arg ) )  || ( !(present(TPR,me) ) ) ) return ( 0 );
        
          if (!present( TPR,me ) ) {
              write("You cant leave a dragen, when you didn't mount it !\n");
              
          } else if (fly) {
               tell_object(TP,
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                 "\n\n ************** you are falling **************** \n\n"+
                  "BUT before you hit the ground the dragon makes a loop and\n"+
                  "catches you again !!!!\n\n");
                 
              } else {
                 tell_room(E(TP),TPN+" leaves the dragon.\n");
                 move_object(TP, E( me ) );
             
            return ( 1 );
           }
        
        return ( 1 );
       }
                 
           
       /*   *** kick ***   */
        
       do_kick ( arg ) {
       
         if ( !id( arg ) ) return ( 0 );
         
            if (!present( TPR, me ) ) {
               tell_room(E ( me ),"The green dragon kicks "+TPN+"\n");
            } else {
               tell_room(E(TP),TPN+" kicks the dragon and off you go !\n");
                              
               fly=1;
               where= "/"+file_name (E (me) );
               me->move_object("high up in the air#room/void");
               call_out("do_fly",2,TP);

               
             }
         
         return ( 1 );
        }
        
            
      /* *** fly *** */
      
      do_fly( ob ) {
      
        tell_room(E(ob),"You see the birds pass below.\n");
        
        call_out("do_fly2",4,ob);
        
        }
       
        
      do_fly2( ob ) {
      
         tell_room(E(ob),"Suddenly, the dragon makes a tremendous loop in the air\n"+
                         "You nearly fall off !\n");
                         
         call_out("do_fly3",6,ob);
         
       }
       
      do_fly3( ob ) {
      
        tell_room(E(ob),"The dragon suddenly lands and you fall down her back .\n");
        
        if (where==DEST1) {
            move_object(me,DEST2); 
        } else {
            move_object(me,DEST1);
          }
        
          fly_end( );
          
         return ( 1 );
        
        }
  
    
        
     fly_end(  ) {
     
       object inv; 
       int i;
       
       inv = all_inventory( me );
       
       for (i=0;i<sizeof(inv);i++) {
           
           tell_object(inv[i],"You leave the dragon !\n");
           tell_room(E(me),inv[i]->query_name()+" leaves the dragon !\n");
           
           move_object(inv[i],E( me ) );
           
           }
       fly = 0;    
       mounted = 0;
          
       return ( 1 );
     }
         
      
              
           
             
        
      
        
      
