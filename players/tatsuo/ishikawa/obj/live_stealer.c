
/* live stealer */

inherit "/obj/weapon";

void reset(int flag)
{
     if (flag == 0)
     {
         set_name("grey blade");
         set_alias("blade");
         set_short("A grey, bloodcovered blade");
         set_hit_func(this_object());
         set_long( 
         "This is the famous sword of livestealing.\n");
     }
}

int weapon_hit(object mob)
{
    int steal, align;
   
    align = this_player()->query_alignment();
    
    if (align > 0)
        steal = 40;      
    else if (align < - 10000)
    {
        steal = 1;
        call_out("dest_me",2);
    }
    else if (align < -1000)
        steal = 10;
    else if (align < 100)
        steal = 20;
    else 
        steal = 30;

   if (random(100) < random((steal * 3)) )
   {
       write("Your black blade sucks the poor live out of "+mob->query_name());
       write("\n");
       tell_object(mob,
       "You feel a boned reaching into your chest.\n");
       this_player()->heal_self(steal);
       this_player()->set_al(align - steal);
   }
 return (10 + random(steal/2));
}
      
void dest_me()
{
  write("You hear a voice saying: MUhaahaaaa MY MISSION IS FULLFILLED\n");
  write("\nYour blade vanishes !\n\n");                                       
  destruct(this_object());
}

int un_wield()
{
      
    if (interactive(this_player()) && this_player()->query_alignment() < -100)
        return 0;
    else 
        return 1;
}

int drop() 
{
    if (interactive(this_player()) && this_player()->query_alignment() < -100)
        return 1;
    else 
        return 0;
}
       
         
