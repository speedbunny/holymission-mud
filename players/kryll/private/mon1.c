inherit "/players/kryll/private/monster";
 
void reset(int arg) {
 
  ::reset(arg);
  if(arg) return;
 
  set_level(10);
  set_name("jonesy");
  set_long("A test monster.\n");
  set_alias("man");
  set_alt_name("my_man");
  set_race("human");
}
 
