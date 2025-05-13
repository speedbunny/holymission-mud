inherit "obj/food";

reset(arg){
  if (!arg) {
   set_name("herb");
   set_alias("green");
   set_alt_name( "_antidodes_herb_" );
   set_short("a herb");
   set_long("A green herb.\n");
   set_strength(1);
   set_value(2);
   set_weight(1);
  }
 }

init()
{
   ::init();

   add_action( "do_eat", "eat" );
}

int do_eat( string what )
{
   if ( id(what) ) {
      write( "You eat the herb and feel poison running through your veins !\n");
      say( this_player()->query_name()+" eats a green herb.\n" );
      this_player()->add_poison(6+random(5));
      destruct( this_object() );
      return( 1 ); 
   }

   return( 0 );
}
