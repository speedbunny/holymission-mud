inherit "obj/treasure";

reset(arg) {
   if (arg)
      return;
      
   set_id("selfdisc");
   set_weight(0);
}

drop( )
{
   return( 1 );
}
