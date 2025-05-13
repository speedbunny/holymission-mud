
/* whisky: code changes, because there where build bugs in */

#define ETO     environment(this_object())
#define ROOM    environment(ETO)

int max; /* maximal amount of time */
int oac, nac;


void init()
{
   add_action( "do_block", "", 1 );
}

int id(string str)
{
   return( str == "wkn1" || str == "waskannom1" );
}

int drop()
{
   destruct( this_object() );
   return( 1 );
}

string query_name()
{
   return( "waskannom" );
}

do_block()
{
   write( "You are froozen, don't even think that you can do something.\n" );
   return( 1 );
}

void free_chance(int ch)
{
   max = 20;
   if (ETO)
   {
       oac = ETO->query_n_ac();
       nac = oac/4;
       ETO->set_n_ac(nac);  /* less defence while frozen */
   }
   call_out( "free_try", 4);
   call_out( "free_myself", ch);
}

void free_myself()
{
     tell_room( ROOM,
     ETO->query_name()+" tries to break out of the ice and succeeds !\n");
     ETO->set_n_ac(oac);  /* old defence */
     destruct(this_object());
     return;
}

void free_try()
{
     tell_room( ROOM,
     ETO->query_name()+" tries to break out of the ice but fails !\n");
     max--;
     if (!max)
         free_myself();
     else 
        call_out("free_try", 4);
}
