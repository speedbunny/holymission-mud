inherit "obj/food";

reset( arg )
{
   if( arg )
      return;
      
   set_name("almond");
   set_short("a delicious almond");
   set_long("The almond looks very delicious.\n");
   
   set_value(2);
   set_weight(1);
   set_eater_mess( "Krack...krack...krack...mmmmmhhhh.\n" );
   set_strength(3);
}
