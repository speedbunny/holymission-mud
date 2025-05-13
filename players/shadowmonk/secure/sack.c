inherit "obj/container";

reset(arg) 
{
 ::reset(arg);
 if (!arg) 
   {
    set_weight(1);
    set_max_weight(99999);
    set_value(35);
    set_name("Shadowmonk's magic sack");
    set_alias("sack");
    set_can_close(1);
   }
}

long()
{
 if (environment(this_player())==this_object())
   {
    write("You have been taken out of your known world, and placed into a\n");
    write("dreamily seventh heaven sphere. You feel weightless!.\n");
    write("         Sack contains:\n");
    see_objs();
   }
 else write("Lovely lil magic sack 8*).\n");
 return 1;
}

int see_objs()
{
 int    i, j, sz;
 object *inv;
 if (!first_inventory(this_object())) return 0;
 inv = all_inventory(this_object());
 for (j=sizeof(inv), i = 0; i < j; i++)
    {
     if (inv[i]->query_name() != this_player()->query_name())
        write(inv[i]->query_name()+"\n");
    }
 return 1;
}

init()
{
 ::init();
 if (!this_player()->query_immortal()) 
   {
    notify_fail("Only immortals can use this item.\n");
    add_action("do_quit","quit");
    return 0;
   }
 add_action("do_stuff","stuff");
 add_action("do_unstuff","unstuff");
}

int do_stuff(string str_arg)
{
 object ob;
 string player_name;
 if (ob=present(str_arg,environment(this_player())))
   {
    player_name=(ob->query_name());
    write("You place "+player_name+" into your sack!\n");
    move_object(ob,this_object());
log_file("SACK", this_player()->query_real_name() + " used sack on " +
                 ob->query_real_name() + ".\n");
//    ob->look();
    say(this_player()->query_name()+" places "+player_name+" into his  magic sack.\n", this_player());
    tell_object(ob,this_player()->query_name()+" places you into his magic sack.\n");
    return 1;
   }
 notify_fail("That person is not here with you right now!\n");
 return 0;
}

int do_unstuff(string str_arg)
{
 object ob;
 string player_name;
 if (ob=present(str_arg, this_object()))
   {
    player_name=(ob->query_name());
    write("You withdraw "+player_name+" from your magic sack.\n");
    say(this_player()->query_name()+" withdraws "+player_name+" from his magic sack.\n");
    tell_object(ob,this_player()->query_name()+" withdraws you from his magic sack.\n");
    move_object(ob,environment(this_player()));
    return 1;
   }
 notify_fail("You cannot find that person in your sack!\n");
 return 0;
}

status do_quit()
{
 if (this_player()->query_name() != "shadowmonk")
   {
    write("You cannot quit when in Shadowmonks sack!\n");
    write("Ask Shadowmonk if he will let you out... NICELY! 8*)\n");
    return 1;
   }
 return 1;
}

drop() { return 1; }

mixed query_auto_load()
{ return "players/shadowmonk/mess/sack:";  }
