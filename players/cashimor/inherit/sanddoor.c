inherit "players/cashimor/inherit/door";

go_door() {
string str,place;

  if(is_closed) {
    write("You can't do that, the door is closed.\n");
    return 1;
  }
  if(!partner_door) return 1;
  place=partner_door->query_room();
  if(place->query_full()) {      
    write("You can't enter the door, there is too much\n"
        + "sand on the other side.\n");
    return 1;
  }
  str=this_player()->query_name();
  partner_door->player_enters(str);
  write("You go through the "+direction+" door.\n");
  this_player()->move_player(direction+"#"+place);
  return 1;
}

init() {
  ::init();
  add_action("dig_it","dig");
}

dig_it(str) {
string place;

  if((!str)||(str!=direction)) {
    notify_fail("Dig where?\n");
    return 0;
  }
  if(!partner_door) return 1;
  place=partner_door->query_room();
  if(place->subtract_sand()) {
    notify_fail("There is no sand in that direction!\n");
    return 0;
  }
  if(environment(this_object())->add_sand()) {
    place->add_sand();
    notify_fail("There is no room for more sand here!\n");
    return 0;
  }
  write("You dig a way "+str+".\n");
  say(this_player()->query_name()+"digs "+str+".\n");
  return 1;
}
