    if(str!="lightning") return 1;
    if(!preparing) {
        write("That would have no effect.\n");
        return 1;
    }
    write("You quickly turn around spreading the lightning all across the area.\
n");
    say(TP->NAME+" turns around a spreads a lightning all across the area.\n");

    enemys = 0;
    ob=all_inventory(ENV(TP));
    gr = TP->grmems_in_room();
    for (i=0,j=sizeof(ob); i < j; i++) {
        if ((ob[i]->query_npc() || ob[i]->query_player())
            && ob[i]->query_guild()!=4 && ob[i]!=TP && member_array(ob[i],gr)==-
1) {
            enemys++;
More: (line 177) [u|d|q|enter]
        }
    }

    if(!enemys) dam=0;
    else dam=3*lightdam/enemys/2+random(7);

    for(i=0;i<sizeof(ob);i++)
        if((ob[i]->query_npc() || ob[i]->query_player()) &&
            ob[i]->query_guild()!=4 && ob[i]!=TP && member_array(ob[i],gr)==-1)
