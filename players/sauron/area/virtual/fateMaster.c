inherit "/players/sauron/inherit/fated";

void reset(int iArg) {
    if(!iArg) {
        setFate("/players/sauron/npc/beggar","give",
                "/players/sauron/workroom","goodFate");
        setFate("/players/sauron/npc/beggar","kill",
                "/players/sauron/workroom","badFate");
    }
}
