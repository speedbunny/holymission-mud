
/* ################################################################
   #								  #
   #    		Mage continual light spell                #
   #                                          		          #
   ###############################################(C) Llort######## */

#include "mage.h"

#define SPELL_COST    100

level() { return 6; }
help () { return HDIRO+"cont_light/cont_light"; }
cost () { return SPELL_COST; }

speed(lev)
{
   if(lev > 20) return 0;
   return 1;
}

do_spell( arg, skill )
{
   object ob;
   int ll;

   if(!arg)
   {
       write("On which object whould you like to cast the spell?\n");
       return 1;
   }

   CHK_SKILL();
   CHK_GHOST();
   CHK_LIGHT();
   CHK_ATT();
   CHK_SP(SPELL_COST);

   if(!ob=present(arg,TP))
   {
       write("You don't have such an item.\n");
       return 1;
   };
 
   CHK_FAIL(SPELL_COST, "continual light");

   ADDSP( -1 * SPELL_COST );

   ll=ob->_light_level();
   if(ll>0)
   {
      write("This item ("+ob->query_name()+") is already lighted.\n");
      return 1;
   };

   if(ll<0)
   {
      write("The "+ob->query_name()+" seems to be a bit less dark now.\n");
      ob->_set_light_level(ll+1);
   };

   ob->_set_light_level(1);
   if(!ob->_light_level())
   {
      write("The "+ob->query_name()+
            " withstood your attempt to brighten it!\n");
      return 1;
   }
   
   ob->set_short(ob->short()+"(glowing)");
   OTHERS(({TP}),TPN+"'s "+ob->query_name()+" glows brighter now.\n");
   write("Your "+ob->query_name()+" starts emmitting bright light.\n");

   return( 1 );
}

query_name()
{
   return( "Continula light" );
}

query_command()
{
   return( "cast 'continual light'" );
}

cast_info()
{
   return(
      ({ "start to concentrate..." }) +
      ({ "utters the words 'rifuyfmet tyrah'" }) +
      ({ 0 })
   );
}

