inherit "/players/whisky/obj/std_dragon";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_colour("white");
       set_age(10);
       move_object(clone_object("/players/whisky/seaworld/obj/silver_star"),this_object());
     }
 }
