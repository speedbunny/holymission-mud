inherit "/obj/board";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_file("players/redsexy/logfiles/guildboard");
  set_name("summoners board");
  set_short("Summoners Guild Board");
}
