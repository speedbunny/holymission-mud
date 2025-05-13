
/* headband */

#define FILE "/players/whisky/guild/obj/headband"

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_name("headband");
         set_weight(1); 
         set_value(15);
         set_long(
         "The famous headband of the Monks of the blue order.\n");
         set_type("helmet");
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
         write("Your headband vanishes.\n");
         destruct(this_object());
     }
}

string short()
{
  int lev;
  string col;

  lev = 0;

  if ( objectp(environment()) && living(environment()) )
       lev = environment()->query_level();
  
  if (lev < 5)        
      col = "white";
  else if (lev < 10)
      col = "green";
  else if (lev < 15)
      col = "blue";
  else if (lev < 20) 
      col = "red";
  else if (lev < 23)
      col ="black";
  else  if (lev < 26) 
      col = "silver";
  else 
      col = "golden";

   if (query_worn())
       return col + " "+query_name()+" (worn)";
   return col + " "+query_name();
}
 
drop()
{
  /*
   if (objectp(this_player()) && interactive(this_player()) )
  {
    call_out("dest_me",0,this_object());
   return 0;
   */
   write("If you want to get rid of your headband type 'junk headband'.\n");
  return 1;
}

void dest_me(object mob)
{
   if ( !environment() || !living(environment()) )
   {
     write("Your headband vanishes.\n");
     destruct(this_object());
   }
}

string query_auto_load()
{
    return FILE+":";
}
