/*******************************************************************
                               T U R T L E         copied from air_dragon
*********************************************************************/

#define TO  this_object()
#define TP  this_player()
#define TPN TP->query_name()
#define TPR TP->query_real_name()
#define TPP TP->query_possessive()
#define E   environment
#define TO_LANK "/players/goldsun/lank/room/coast1"
#define TO_HM "/players/goldsun/lank/coast_cott"
                                        
inherit "obj/monster";

object me;
int swim, mounted;
string where;
   
reset(arg) {
  ::reset(arg);
      
if (!arg) {
        
     set_name("turtle");
     set_living_name("trans_turtle");
     set_short("A friendly sea turtle");
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
	   write("You see a green large sea turtle. She looks\n"+
                 "very friendly. It seems like if you mount her\n"+
                 "she might bring you to a different place !\n");
         } else if (swim) {
           write("You see the back of the friendly sea turtle and\n"+
	 	"nice blue sea around. The waves are rolling towards\n"+
	 	"turtle and you get a peacefull feeling.\n");
         } else {
            write("You see the back of the friendly sea turtle, you\n"+
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
        
           tell_room(E(me),"The turtle dives down into the sea\n");
           
           if ("/"+file_name(E(me))==TO_LANK) {
              move_object(me,TO_LANK);
            } else {
              move_object(me,TO_HM);
           }
         }
       
       return ( 1 );
     }
       
           
      /*   *** mount   ***  */
        
      do_mount ( arg ) {
      
         if ( !id( arg ) ) {
             notify_fail("Mount what ?\n");
           
         } else if (present(TPR,E(me))) {
             tell_room(E(me),TPN+" mounts the turtle !\n");
             write("You get the feeling you should kick the turtle for a ride.\n");
             move_object( TP,me );
             mounted = 1;
            
          } else {
             write("You are just sitting on the turtle.\n");
           }
         
         return ( 1 );
        }
       
      do_leave( arg ) {
      
        if ( ( !id( arg ) )  || ( !(present(TPR,me) ) ) ) return ( 0 );
        
          if (!present( TPR,me ) ) {
              write("You cant leave a turtle, when you didn't mount it !\n");
              
          } else if (swim) {
               tell_object(TP,
                 "\n\n ************** you are falling  **************** \n\n"+
                 "\n\n ************** you can't breath **************** \n\n"+
                 "\n\n ************** you are falling  **************** \n\n"+
                 "\n\n ************** you can't breath **************** \n\n"+
                 "\n\n ************** you are falling  **************** \n\n"+
                 "\n\n ************** you can't breath **************** \n\n"+
                 "\n\n ************** you are falling  **************** \n\n"+
                  "BUT before you lost in the sea the turtle makes a loop and\n"+
                  "catches you again !!!!\n\n");
                 
              } else {
                 tell_room(E(TP),TPN+" leaves the turtle.\n");
                 move_object(TP, E( me ) );
             
            return ( 1 );
           }
        
        return ( 1 );
       }
                 
           
       /*   *** kick ***   */
        
       do_kick ( arg ) {
       
         if ( !id( arg ) ) return ( 0 );
         
            if (!present( TPR, me ) ) {
               tell_room(E ( me ),"The green turtle kicks "+TPN+"\n");
            } else {
               tell_room(E(TP),TPN+" kicks the turtle and off you go !\n");
                              
               swim=1;
               where= "/"+file_name (E (me) );
               me->move_object("in the sea#room/void");
               call_out("do_swim",2,TP);

               
             }
         
         return ( 1 );
        }
        
            
      /* *** swim *** */
      
      do_swim( ob ) {
      
        tell_room(E(ob),"You see the fishes pass below.\n");
        
        call_out("do_swim2",4,ob);
        
        }
       
        
      do_swim2( ob ) {
      
   tell_room(E(ob),"Suddenly, the turtle makes a loop in the water\n"+
                         "You nearly fall off !\n");
                         
         call_out("do_swim3",6,ob);
         
       }
       
      do_swim3( ob ) {
      
        tell_room(E(ob),"The turtle suddenly lands and you fall down her back .\n");
        
        if (where==TO_LANK) {
            move_object(me,TO_HM); 
        } else {
            move_object(me,TO_LANK);
          }
        
          swim_end( );
          
         return ( 1 );
        
        }
  
    
        
     swim_end(  ) {
     
       object inv; 
       int i;
       
       inv = all_inventory( me );
       
       for (i=0;i<sizeof(inv);i++) {
           
           tell_object(inv[i],"You leave the turtle !\n");
           tell_room(E(me),inv[i]->query_name()+" leaves the turtle !\n");
           
           move_object(inv[i],E( me ) );
           
           }
       swim = 0;    
       mounted = 0;
          
       return ( 1 );
     }
         
      
              
           
             
        
      
        
      
