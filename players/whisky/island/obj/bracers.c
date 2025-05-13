
inherit "/obj/armour";

void reset(int arg)
{
  ::reset(arg);
  
   set_name("bracers");
   set_alias("golden bracers");
   set_short("golden bracers");
   set_long("You see a pair of beautiful golden bracers\n"+
            "build for a pretty gnome woman.\n");
   set_ac(2);
   set_weight(1);
   set_value(2000);
   set_type("arm/armour");
}

query_mage_wear()
{
   return 1;
}

query_monk_wear()
{
  return 1;
}

int wear(string str)
{
  ::wear(str);
  if (this_player()->query_gender() == 1)
      this_player()->set_gender(2);
    return 1;
}

/* Uglymouth: remove those from play. original ones will remain,
   although not autoload anymore.
query_auto_load()
{
 return "/players/whisky/island/obj/bracers:";
}
*/
drop()
{
/* Uglymouth: no longer needed, coz no longer autoload.
 if (!this_player()->query_npc()) return 1;
*/
     return 0;
}
get()
{
  return 1;
}
