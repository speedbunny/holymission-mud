
/* whip */

inherit "/obj/weapon";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("black whip");
       set_alias("whip");
       set_long(  
       "A long black leather whip, polished with vaseline. ** grin **\n"+
       "It looks like the Witch uses that for her special bed massages.\n"); 
       set_class(0);
       set_value(300);
       set_hit_func(this_object());
     }
}

int magic_hit(object mob)
{
    if (!random(8))
    {
        write("You slowly swing your whip !\n");
        command("groan",this_player());
        say(this_player()->query_name()+" slowly swings "+
            this_player()->query_possessive()+" whip !\n");
       command("groan",mob);   
    }
    return (random(26));
}
