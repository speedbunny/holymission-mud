/*coded by tatsuo for ishikawa*/
inherit "/obj/monster";
void reset (int flag)
{
::reset(flag);
if (flag==0)   /*the creation can be 0 || 1 */
{
set_name("serpent");
set_alt_name("deadly serpent");
set_short("A Deadly Serpent");
	set_long("You see a sleek and powerful dragon coiled for attack!.\n");
set_level(30);
set_hp(1800);
set_wc(85);
set_ac(10);
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
