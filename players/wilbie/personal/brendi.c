inherit "obj/monster";
#include "/players/wilbie/break_str.h"
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
        set_name("Tuppence");
        set_race("girl");
        set_short("Tuppence");
        set_long("This is Wilbie's bodyguard.  She's REALLY tough so "+
                 "don't even THINK about fighting her unless you're "+
                 "an immortal...  She is NEVER allowed outside Wilbie's "+
                 "workroom!!\n");
        set_level(50);
	set_al(1000);
        set_ac(10);
	set_wc(20);

        set_spell_mess2("Tuppence strikes you with a perfect nukite!!");
        set_spell_mess1("Tuppence uses an Isshinryu nukite stike!!");
        set_chance(99);
        set_spell_dam(100);
	if (!chats) {
            chats=allocate(20);
            chats[0]="Tuppence says: This place is funky!!\n";
            chats[1]="Tuppence smiles at you real cute like...\n";
            chats[2]="Tuppence giggles for no particular reason...\n";
            chats[3]="Tuppence polishes her guitar...\n";
            chats[4]="Tuppence happlily tunes her guitar...\n";
chats[5]="Tuppence cranks out some Megadeth on her Ice Blue Ibanez!!\n";
chats[6]="Tuppence says: How do I advance my level??\n";
chats[7]="Tuppence looks at you.\n";
chats[8]="Tuppence plays a happy little tune on her guitar.\n";
chats[9]="Tuppence says: What guild should I join??\n";
chats[10]="Tuppence yawns.";
chats[11]="Tuppence says: Want to hear a song?\n";
chats[12]="Tuppence plays a sad melody...\n";
chats[13]="Tuppence says: You look silly!\n";
chats[14]="Tuppence giggles.\n";
chats[15]="Tuppence laughs.\n";
chats[16]="Tuppence says: I need to do some quests!\n";
chats[17]="Tuppence smiles.\n";
chats[18]="Tuppence sighs.\n";
chats[19]="Tuppence says: Like my new guitar??\n";
	}
        load_chat(10,chats);
    }
}

