#define OWNERS         "/players/tatsuo/guild/nweap/weap_owners"

inherit "/players/tatsuo/guild/nweap/ninja_weapon";

query_auto_load() {
  if(this_player()->query_guild()==8){
   return "/players/tatsuo/guild/nweap/shidoshi_katana:"; }
   }
void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
     set_name("katana");
      set_short("The Katana of the Shidoshi "+capitalize(this_player()->query_real_name()) );
       set_long("The Katana of the leader of the Ninja clan, that being YOU.\n");
	set_class(20);
	set_value(0);
	set_weight(8);

        set_critical_hit_factor(7);
	set_parry_class(7);
    }
}

drop(){
  tell_object(this_player(),"You would never dishonor yourself by dropping this.\n");
  return 1;
}
