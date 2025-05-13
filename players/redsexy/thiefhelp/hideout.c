/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Hideout =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/

int main() {
  object thief;
  string hideout;

  thief=this_player();
  if(present("thiefsoul",thief)->query_renegade()){
    write("The Guild of Thieves has banished you from the hideout.\n");
    return 1;
  }
  
  if (file_name(environment(thief)) == "players/blade/guild/hideout")  {
    write("Your keen thief senses compel you to examine your "
          + "surroundings.\n");
    return 1;
  }
  
  if (environment(thief)->has_drink(thief)) {
    write("You are not allowed to leave with drinks!\n");
    return 1;
  }
  
  if (environment(thief)->query_property("no_teleport")) {
    write("You are unable to find a way out of this place.\n");
    return 1;
  }
  
  present("thiefsoul",thief)->prev_environment(environment(thief));
  if(!thief->query_invis())
    say(thief->query_name()+" leaves suddenly.\n");
  move_object(thief,"/players/blade/guild/hideout");
  write("You sneak off to the hideout.\n");
  return 1;
}





