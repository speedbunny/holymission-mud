#define OBJECTS "/players/patience/guild/nobj/"

/* =============================================================== 
   Userdoc: clean (as in spirit) - NINJA GUILD SKILL
   ---------------------------------------------------------------
   Restores spellpoints and hitpoints faster than normal heal rate
   Heal: depends on level, wiz, int, cha see under: /guild/obj/blocker.c
   Cost: none
   Special: innate for ninja / just a better rest
   =============================================================== */

int main(string str)
{
    object victim;
    object blocker;

    if((!str)||(str!="spirit"))
        return 0;

    if (this_player()->query_ghost())
        return 1;
    else if (objectp(victim = call_other(this_player(),"query_attack")) && 
        environment(this_player())==environment(victim))
    {
        tell_object(this_player(), "You can't concentrate enough to clean "+
          "your spirit while you are fighting.\n");
        return 1;
    }

    if (!present("clean_blocker",this_player()))
    {
        tell_object(this_player(),"You sit down in the lotus position and "+
          "begin to meditate.\n");
        say(capitalize(this_player()->query_real_name())+" sits down in the "+
          "lotus position.\n",this_player());
        blocker = clone_object(OBJECTS + "clean_blocker");
        move_object(blocker,this_player());
        call_other(blocker,"add_heal");
        return 1;
    }
    return 0;
}
