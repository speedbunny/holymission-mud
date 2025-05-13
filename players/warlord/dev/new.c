// A new idea for a new mud.. Copyrighted by me for here

#define BaseStat 0 // for each stats, WON"T be modified
#define ModStat 1 // Only get affected by equip/items or spells
#define Holder 2 // this is for futire expansion
#define STATS ({ "str","int","wis","dex","con","cha" })

inherit "/obj/treasure";


void init_stats();
int ShowStats();
void SetStats(string stat, int amount);

mixed *stats;

reset() {
    set_name("new");
    set_short("new");
    set_long("Really new V1.0\n");
    return;
}

init() {
    ::init();
    add_action("ShowStats","blah");
    add_action("SetStats","bub");
}
void init_stats() {
    int i;
    if(stats) return;
    printf("Inside Init_stats, setting up I hope.\n");
    stats= allocate(sizeof(STATS));
    for (i=0;i<sizeof(STATS);i++)
    {
	stats[i]=allocate(3);
	stats[i][BaseStat]=0;
	stats[i][ModStat]=0;
	stats[i][Holder]=0;
    }
    return 0;
}
int ShowStats() {
    int i;
    if(!stats) {
	printf("Stats not defined, going to init_stats().\n");
	init_stats();
	return 1;
    }
    for(i=0;i<sizeof(STATS);i++) {
	write("I="+i+"\n");
	printf("Stat:%s=%d\n",STATS[i],stats[i][BaseStat]);
    }
    return 1;
}

void SetStats(string str , int amount) {
    if(!str) notify_fail("No string.\n");
    if(!amount) notify_fail("No amount.\n");
    write("string:"+str+"Amount"+amount+"\n");
    if(str=="str") {
	write("Got here!\n");
	stats[0][0]=amount;
	return;
    }
}
