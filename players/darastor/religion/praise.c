
int praise(string arg)
{
   object fo;

    if (this_player()->query_religion()!="Quercus"){
      write("Shit.\n");
      return 1;
    }
    if (arg!="quercus")
    {
       write("Quercus sniffs sadly at you.\n");
       return 1;
    }
    else if (!this_player()->eat_food(2))
    {
       write("Quercus tells you: You are too full to eat more holy wafer.\n");
       return 1;
    }
    write("Quercus sends you a holy wafer.\n"); 
    tell_room(environment(this_player()),
              "A holy wafer appears on the ground.\n");
    fo = clone_object("/obj/food");
    fo->set_name("holy wafer");
    fo->set_alias("wafer");
    fo->set_short("A holy wafer.\n");
    fo->set_long("A holy wafer from: Quercus.\n");
    fo->set_strength(2);
    fo->set_weight(1);
    move_object(fo,environment(this_player()));
    return 1;
}


