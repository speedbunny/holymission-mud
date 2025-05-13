/* Bertls Gemeiner Gummiball HM 27.11.94 */
inherit "obj/treasure";
#include "/players/bertl/defs/bdefs.h"

reset (arg) 
{
  if (arg) return;
  set_id("Ball");
  set_short("A strange Ball");
  set_alias("ball");
  set_long("Its a strange looking ball. It is filled up with air.\n" +
           "Maybee you should drop it?\n");
  set_value(10);
  set_weight(1);
}

init() 
{
   add_action("stop_shout", "shout");
   add_action("ball_destruct", "destruct");      
   add_action("ball_throw", "throw");      
   add_action("ball_junk", "junk");
   add_action("ball_drop", "drop");
   add_action("ball_sell", "sell"); 
   add_action("ball_quit", "quit");
   add_action("ball_give", "give");
   add_action("ball_deflate", "deflate");
   ::init();
}

stop_shout(str)
{
   write("It's not possible to shout with a ball on the face!\n");
  return 1;
}

ball_quit(str)
{

   destruct(this_object());
   return 0;
}
ball_give(str)
{
   string player;

   if(!str)
   return 0;

   if(sscanf(str, "ball to %s",player) != 1)
      return 0;
   
   if(lower_case(TP()->query_real_name()) == "bertl")
   {
      return 0;
   }
   else
   {
      tell_object( TP(), "Why do you wanna give away such a nice gift?\n");
      return 1;
   }   
}

ball_destruct(str)
{
   if(!str)
      return 0;

   if(str!="ball")
      return 0;

   tell_object( TP(), "Oh no, not this way, dear Wizz, try a better one :)\n");
   return 1;
}

ball_junk(str)
{
   if(!str)
      return 0;

   if(str!="ball")
      return 0;

   tell_object( TP(), "Hey, I was a gift, you cant junk me!\n");
   return 1;
}
ball_sell(str)
{
   if(!str)
      return 0;

   if(str!="ball")
      return 0;

   tell_object( TP(), "Aha, nice try, but didnt work!\n");
   say( TPN + " tries to sell a ball, but fails!\n");
   command( "grin", TP() );
   return 1;
}

ball_throw(str)
{
   if (!str)
      return 0;

   if( str != "ball")
      return 0;

   tell_object( TP(), "Bertl laughs evily at you and says: You cant throw that!\n");
   return 1;
}

ball_drop(str)
{
   if (!str) 
      return 0;

   if( str != "ball")
      return 0;


   tell_object( TP(), "You drop the ball.\n");
   say( TPN + " drops a funny ball made of rubber.\n");
   tell_object( TP(), "You see the ball bouncing around in the room.\n");
   say( "Suddenly the ball starts to bounce around.\n");
   tell_object( TP(), ".... and finaly the ball gets tired and comes back to you!\n");
   say( "The ball bounces on your head and returns to " + TPN + "\n.");
  
   return 1;
}  

ball_deflate(str)
{
   if(!str)
      return 0;

   if( str != "ball")
      return 0;
   
   say( TPN + " makes strange noises, sounds like a ...pfffffffft....\n");
   say( "...pffft...pft.. like a fart!\n");
   tell_object( TP(),"You manage, somehow, to deflate the ball!\n");
   tell_object( TP(),"But there are strange noises while you do that!\n");
   command("laugh", TP()); 
 
   destruct(this_object());
   return 1;
}
