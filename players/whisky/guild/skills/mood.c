

/* =============================================================== 
   Userdoc: Mood           /players/whisky/guild/skills/mood.c
   ---------------------------------------------------------------
   Art: Changing the way to combat a victim
   Damage || Heal: none
   Cost: none
   Special: This is no skill its just a feature. A player can change
            the mood in 3 ways (defensive, moderate or aggressive).
            The normal way is moderate which gives an amount of 
            attacks, some armourclass and some weaponclass. Defensive
            means less attacks less weaponclass but more armourclass.
            Aggressive is more attacks more weaponclass but less 
            armour class and less dodge. 
   =============================================================== */

mixed mood(string arg)
{
    this_player()->set_mode(arg);
}

