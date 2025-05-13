int move(string str) {
  object ob;

  if(!str)
    str = query_verb();
  if((str == "east" || str == "west") && (ob=present("gamorrean guard", this_object())) &&
      !this_player()->query_immortal() && this_player()->query_invis() <
      ob->query_level() + 10) {
    write("The guard laughs at your attempt to pass him!\n");
    ob->attack_object(this_player());
    return 1;
  }
  return ::move(str);
}
