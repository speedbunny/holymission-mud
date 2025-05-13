/* Changed by Ethereal Cashimor, 150493, for lowering the maxstat of undefined
   races. */

inherit "room/room";

#define TP this_player()

int *xpcost;
int *guildbon;

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Allport Stat advance room";
    long_desc=
"This is a strange, clean room. The floor, the ceiling, and all walls are\n"+
"colored white. A small mystic person sits behind a desk, and above the\n"+
"desk you can make out the following text:\n"+
"   You can gain information about the <cost> of advancing your stats,\n"+
"   and you can try to <improve> one of your stats here.\n"+
"The text is written in shining yellow letters which are levitating above\n"+
"the table.\n"+
"The new stat limits for levels was intended by Herp!\n";
    dest_dir=({ "players/topaz/rooms/cont/to_stats","north" });
    items=({ "desk","A big table shining in bright white",
             "person","The person looks very powerful",
             "wall","It is white",
             "walls","They are white",
             "floor","It is white",
             "ceiling","It is white",
             "text","The same text as before",
             "letters","They are shining in beautiful yellow" });
    xpcost=({	   488,	   570,	   665,	   776,	   906,	  1057,	
		  1234,	  1440,	  1680,	  1961,	  2288,	  2670,
		  3116,	  3636,	  4242,	  4950,	  5775,	  6738,
		  7861,	  9172,	 10701,	 12485,	 14566,	 16994,
	  	 19827,	 23132,	 26988,	 31486,	 36734,	 42857,
		 50000,	 55000,	 60000,	 65000,	 70000,	 75000,
		 80000,	 85000,	 90000,  95000,	100000, 105000,
                110000 });
    guildbon= ({ ({  0,  0,  0,  0,  0,  0 }),
                 ({ -2,  2,  0,  0, -2,  2 }),
                 ({  0,  0,  0,  0,  0,  0 }),
                 ({  2,  0,  2, -2, -2,  0 }),
                 ({ -1,  0, -1,  0,  1,  1 }),
                 ({ -2,  0, -2,  2,  2,  0 }),
		 ({ -2,  0, -2,  2,  0,  2 }),
                 ({  0,  2,  0, -2,  2, -2 }),
  		 ({  0,  2,  0,  0,  0, -2 }),
                 ({ -2, -1, -2,  2,  1,  2 }),
		 ({  0,  0,  0,  0,  0,  0 }),
		 ({  2,  0,  2, -2, -2,  0 }),
 });
}

init() {
    ::init();
    add_action("cost","cost");
    add_action("improve","improve");
}

max_imp() { return this_player()->query_level()*5/4+3; }  /* changed: Herp */

calc_cost(stat) {
    int m,r,s;
    s=TP->query_stats(stat);
    m="race/master"->query_max_stat(TP->query_race(),stat);
    if(!m) m=20; /* Changed: Cashimor */
    if(s>=m) return 0;
    return xpcost[s+1-guildbon[TP->query_guild()][stat]];
}

cost() {
    int i,s;
    string *snam;
    snam=({ "Str","Dex","Con","Int","Wis","Chr" });
    i=TP->query_exp()-"guild/master"->query_exp(TP->query_guild(),
                                                TP->query_level()); 
    write("You have "+(i>0 ? i : "no")+" XP you can use for improvement.\n");
    write("Stat Costs: \n");
    for(i=0;i<6;i++) {
       if(TP->query_stats(i)>=max_imp())
           write(snam[i]+"\t\tYou have to improve your level first.\n");
       else
           write(snam[i]+"\t\t"+
                 ((s=calc_cost(i)) ? s+" XP\n" : "at your limit\n"));
    }
    return 1;
}

improve(arg) {
    int snr,c;
    if(this_player()->query_race()=="frog") {
        write("Sorry, you can't improve your stats as frog.\n");
        return 1;
    }
    if(!arg) {
        write("You can improve: str, dex, con, int, wis or chr.\n");
        return 1;
    }
    snr=0;
    switch(arg) {
        case "chr": snr++;
        case "wis": snr++;
        case "int": snr++;
        case "con": snr++;
        case "dex": snr++;
        case "str": break;
        default: write("Sorry, I don't know how to improve '"+arg+"'.\n");
            return 1;
    }
    if(!(c=calc_cost(snr))) {
        write("You can not improve this stat any further!\n");
        return 1;
    }
    if(TP->query_stats(snr)>=max_imp()) {
        write("You have to improve your level first.\n");
        return 1;
    }
    if(TP->query_exp()-"guild/master"->query_exp(TP->query_guild(), 
       TP->query_level())<c) {
        write("You don't have enough XP to improve that stat.\n");
        return 1;
    }
    TP->add_exp(-c);
    TP->set_stats(snr,TP->query_stats(snr)+1);
    write("You raised your stat.\n");
    say(TP->query_name()+" just raised a stat.\n");
    return 1;
}
             
