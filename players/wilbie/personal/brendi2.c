inherit "obj/monster";
#include "/players/wilbie/break_str.h"
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("brendi");
        set_race("girl");
        set_short("brendi");
        set_long("This is Wilbie's bodyguard.  She's REALLY tough so "+
                 "don't even THINK about fighting her unless you're "+
                 "an immortal...  She is NEVER allowed outside Wilbie's "+
                 "workroom!!\n");
        set_level(99);
	set_al(1000);
        set_ac(10);
	set_wc(20);

        set_spell_mess2("Brendi strikes you with a perfect nukite!!");
        set_spell_mess1("Brendi uses an Isshinryu nukite stike!!");
        set_chance(99);
        set_spell_dam(-300);
	if (!chats) {
            chats=allocate(20);
            chats[0]="Brendi says: This place is funky!!\n";
            chats[1]="Brendi smiles at you real cute like...\n";
            chats[2]="Brendi giggles for no particular reason...\n";
            chats[3]="Brendi polishes her guitar...\n";
            chats[4]="Brendi happlily tunes her guitar...\n";
chats[5]="Brendi cranks out some Megadeth on her Ice Blue Ibanez!!\n";
chats[6]="Brendi says: How do I advance my level??\n";
chats[7]="Brendi looks at you.\n";
chats[8]="Brendi plays a happy little tune on her guitar.\n";
chats[9]="Brendi says: What guild should I join??\n";
chats[10]="Brendi yawns.";
chats[11]="Brendi says: Want to hear a song?\n";
chats[12]="Brendi plays a sad melody...\n";
chats[13]="Brendi says: You look silly!\n";
chats[14]="Brendi giggles.\n";
chats[15]="Brendi laughs.\n";
chats[16]="Brendi says: I need to do some quests!\n";
chats[17]="Brendi smiles.\n";
chats[18]="Brendi sighs.\n";
chats[19]="Brendi says: Like my new guitar??\n";
	}
        load_chat(10,chats);
    }
}

