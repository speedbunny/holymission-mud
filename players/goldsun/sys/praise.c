
int praise(string arg)
{
   object fo;

   
    if (this_player()->query_religion()!="urimuri")
    {
        write("But you are no follower of urimuri.\n");
        return 1;
    } 
    else if (arg!="urimuri")
    {
       write("Urimuri sniffs sadly at you.\n");
       return 1;
    }
    else if (!this_player()->eat_food(5))
    {
       write("Urimuri tells you: You are too full to eat more holy wafer.\n");
       return 1;
    }
    write("Urimuri sends you a holy wafer.\n"); 
    tell_room(environment(this_player()),
              "A holy wafer appears on the ground.\n");
    fo = clone_object("/obj/food");
    fo->set_name("holy wafer");
    fo->set_alias("wafer");
    fo->set_short("A holy wafer.\n");
    fo->set_long("A holy wafer from: Urimuri.\n");
    fo->set_strength(5);
    fo->set_weight(1);
    move_object(fo,environment(this_player()));
    return 1;
}


