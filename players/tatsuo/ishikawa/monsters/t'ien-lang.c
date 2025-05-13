/*coded by tatsuo for ishikawa*/
inherit "/obj/monster";
void reset (int flag)
{
::reset(flag);
if (flag==0)   /*the creation can be 0 || 1 */
{
set_name("T'ien Lung, the Celestial Dragon");
set_alias("t'ien lung");
set_alt_name("dragon");
set_short("T'ien-lang");
set_long("T'ien-lang is a great typhoon serpent, it is 45 feet long and \n"+
         "is coiled in the sand resting.\n");
set_level(30);
set_hp(1200);
set_wc(32);
set_ac(6);
set_aggressive(1);
}
}
int attack()
{
if (::attack() && !random(3))
{
if ( attacker_ob && living(attacker_ob))
{
tell_object(attacker_ob,
"The serpent blasts you with it's golden fire.\n");
say ("The serpent blasts "+attacker_ob->query_name()+
" with its golden fire.\n",attacker_ob);
attacker_ob->hit_player(40 +random(40),5);
}
return 1;
}
return 0;
}
