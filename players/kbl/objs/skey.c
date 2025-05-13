/* dedicated to Kbl, my dear friend, 2.10.92 */
/* Kbl's modified version of Helenettes original housekey.c
   This key will go to my love SUNSHINE, my lover forever
   Love her always
*/
#define SilentMove(x,y) say (capitalize(this_player()->query_real_name()) \
  + y + ".\n"); transfer(this_player(),x); \
  say (capitalize(this_player()->query_real_name()) + " enters and smiles at you.\n"); \
  write ("Welcome back!\n"); command("l",this_player())

id (str) { return str=="housekey" ; }
short () { return "Housekey"; }
long ()  { write
  ("A shiny golden Housekey\n"+
   "Just go 'kbl'\n");
}
query_light () { return 1; /* The key glows in the dark *grin*  */ }
init () {
    add_action ("goto_home",       "kbl");
    add_action ("keyto",           "keyto");
    }

get ()  { return 1; }  /* no get & no drop, either you have it you you have it not */
drop () { return 1; }
query_auto_load()
{
  return "players/kbl/objs/skey:";
}

goto_home()
{
  SilentMove("players/kbl/workroom"," goes to hideaway");
  return 1;
}


keyto (who) { /* To send my key to my friend Kbl */
    object key, player;
    if(this_player()->query_real_name() != "kbl")
      return;
      /* it's MY house & housekey, my guest is not allowed to duplicate the key */
    if (!who) return;
    player=find_living(who);
    if (!player) return;
    if(!(player->query_level()>29 || player->query_testchar()) &&
          player->query_real_name() != "sunshine")
      {
      write ("Give your housekey to players???\n"); return 1; }
    key=(transfer(clone_object("players/kbl/objs/skey"),player));
    return 1;
}
