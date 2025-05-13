
#define TP  this_player()
#define TPN TP->query_name()
#define TO  this_object()
#define TPR TP->query_real_name()

inherit "obj/container"; 
   
 reset(arg) {

  ::reset(arg);
  if (arg) return;
    set_name("catapult");
    set_alias("big catapult");
    set_max_weight(1000); 
    set_short("A big Catapult");
    set_long("This is a huge wooden Catapult. But it isn't build very fine.\n"+
             "Something tells you not to enter. There is a sign.\n");
    set_value(0);
    set_weight(1000);
}

    init() {
      add_action("do_read","read");
      add_action("do_enter","enter");
     
      ::init();
      }
      
    do_read( arg ) {
    
       if ( !arg && arg!="sign" ) return ( 0 );
       
       write("Regret your sins.\n\n"+
             "Show that you really regret your sins.\n"+
             "Sacrifice your life.\n\n");
             
      return ( 1 );
      }
      
     do_enter( arg ) {
     
         if ( arg!="catapult" || !arg ) {
             notify_fail("Enter what ?\n");
     
         } else {
              TP->set_vis();
              write("You enter the catapult.\n");
              say(TPN+" enters the catapult.\n");
              move_object(TP,TO);
              shout(TPN+" is a fireball crossing the firmament.\n");
           TP->move_player(" #/players/tegerl/jabberwocky/rooms/out/dt");
            
         } 
         
        return ( 1 );
       }
       
  
           
  get() { return ( 0 ); }      
          
          
        
         
         
               
