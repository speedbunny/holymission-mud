
/* captain */

inherit "/obj/monster";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("captain");
       set_short("The captain of the commuter to Death Island");
       set_long( 
       "You see an old, grey bearded seabear bringing his commuter\n"+
       "from the vikings shore to the Death Island.\n");
       set_level(30);
       set_race("human");
       set_gender(1);
     }
}

int attack()
{
    if (::attack() && environment() == environment(attacker_ob))
    {
        say("The Captain takes "+attacker_ob->query_name()+" and throws "+
        attacker_ob->query_objective()+" into the sea !\n",attacker_ob);
        attacker_ob->move_player(
        "with a loud SPLAH#players/whisky/seaworld/room/sw25");
        return 1;
    }
   return 0;
}
       

