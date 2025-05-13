
/* robe */

#define FILE "/players/whisky/guild/obj/robe"

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("silk robe");
         set_alias("robe");
         set_weight(1); 
         set_value(15);
         set_long(
         "The famous robe of the Monks of the blue order.\n"+
         "The robe is made of soft silk with the symbol of\n"+
         "the blue order on its back.\n");
         set_type("robe");
         set_ac(1);
     }
}

int query_monk_wear()
{
    return 1;
}

void init()
{
   int lev;

    ::init();

     if (interactive(this_player()) && this_player()->query_guild()!=7)
     {
         write("Your robe vanishes.\n");
         destruct(this_object());
     }
}

string short()
{
  string col, gen;


  if ( objectp(environment()) && living(environment()) )
       gen = environment()->query_gender();

   switch(gen)
   {
     case 0:
      col = "violet";
     break;
     case 1:
      col = "blue";
     break;
     default:
      col = "red";
      break;
   }  

   col = "a "+col;
   if (query_worn())
       return col + " "+query_name()+" (worn)";
   return col + " "+query_name();
}
 
drop()
{
   write("If you want to get rid of your robe type 'junk robe'.\n");
  return 1;
}

void dest_me(object mob)
{
   if ( !environment() || !living(environment()) )
   {
     write("Your robe vanishes.\n");
     destruct(this_object());
   }
}

string query_auto_load()
{
    return FILE+":";
}
