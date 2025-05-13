#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/tatsuo/guild/nweap/ninja_weapon";

query_auto_load() {
  if(this_player()->query_guild()==8){
   return "/players/tatsuo/guild/nweap/katana:"; }
   }
void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
	set_name("daito");
	set_short("A daito");
	set_long("A daito is a long, slighty curved, sword. It is a ninja " +
		 "weapon.\nThe daito looks extremely sharp.\n");
	set_class(20);
	set_value(0);
	set_weight(8);

	set_critical_hit_factor(6);
	set_parry_class(7);
    }
}

drop(){
  tell_object(this_player(),"You would never dishonor yourself by dropping this.\n");
  return 1;
}
