inherit "obj/armour";

object owner;

reset(arg) {

   if(!arg) {

      set_short("Darkmaster's ruby ring");
      set_long("\nUsage: players [-awpmfil#].\n\n" +
	       "   a: show only the active people.\n" +
	       "   w: show wizards only (except when 'p' also used).\n" +
	       "   p: show players only (except when with 'w').\n" +
	       "   m: show males only (except when with 'f').\n" +
	       "   f: show females only (except when with 'm').\n" +
	       "   i: drop the IP address from the list.\n" +
	       "  l#: example: l22 (lists only those who are at level 22).\n" +
	       "      Any number will be accepted but only valid\n" +
	       "      levels are meaningful.\n\n");
      set_alias("ring");
      set_value(0);
      set_ac(0);
   }
}


init() {

    ::init();
    owner = this_player();
    add_action("list_players", "players");
}


list_players(str) {	/* Usage: players [-apwfmil#] */

    object list;
    string strings;
    int inactive, players, wizards, females, males;
    int ip, level;
    int i, total;

    players = 0; wizards = 0; females = 0; males = 0;
    inactive = 0; ip = 0; level = 0;

    if (str && extract(str, 0, 0) == "-") {

	string temp;
	 
	if (sscanf(str, "%sa", temp)) { inactive = 1; }/* A value here      */
	if (sscanf(str, "%sp", temp)) { wizards = 1; }	/* means don't print */
	if (sscanf(str, "%sw", temp)) { players = 1; }	/* out any player    */
	if (sscanf(str, "%sf", temp)) { males = 1; }	/* that meets this   */
	if (sscanf(str, "%sm", temp)) { females = 1; }  /* condition.        */
	if (sscanf(str, "%si", temp)) { ip = 1; } /* don't show ip addresses */
	sscanf(str, "%sl%d", temp, level); /*if level show only those at that*/
/* not implemented as of yet 
	sscanf(str, "%sd%d", temp, domain);/* level.  Ditto for domain.      */
    }
    if (males && females)   { females = 0;   males = 0; }
    if (wizards && players) { wizards = 0; players = 0; }

    list = users();
    if (sizeof(list) == 1) {
	write ("There is 1 person on the Holy Mission. ");
    }
    else {
        write ("There are " + sizeof(list) + " people on the Holy Mission. ");
    }
    write (query_load_average() + "\n");

    if (!ip) write (" IP address     ");
    write ("  Name       Lvl Sex Age Idle   Location\n");
    if (!ip) write ("=============== ");
    write (" ======      === === === ===== ==========\n");

    for (i=0; i < sizeof(list); i++) {
	string host, name, stats, location;
	int num_lvl;
	int age;

	host = "";
	stats = 0;

	if (inactive && query_idle(list[i]) > 300)    continue;
	if (wizards  && list[i]->query_level() > 29)    continue;
	if (players  && list[i]->query_level() < 30)    continue;
	if (males    && list[i]->query_gender() == 1)   continue;
	if (females  && list[i]->query_gender() == 2)   continue;
	if (level  && list[i]->query_level() != level)  continue;
/*
	if (domain && list[i]->query_level() != domain) continue;
*/

	if (!ip) {					/* host */
	    host = query_ip_number(list[i]);
	    while (strlen(host) < 16)
		host = host + " ";
	    if (strlen(host) > 16)
		host = extract(host, 0, 15);
	}

	name = list[i]->query_real_name();		/* name */
	if (!name) name = list[i]->query_name();
	if (!name) name = "logon";
	name = capitalize(name);
	if (list[i]->short() == 0)
	    name = "(" + name + ")";
	else
	    name = " " + name;
	while (strlen(name) < 13)
	    name = name + " ";

	num_lvl = list[i]->query_level();		/* level */
	if (num_lvl > 25)                 stats = "---";
	if (num_lvl == 1000)                stats = "God";
        if (num_lvl == 666)               stats = "Eld";
	if (num_lvl == 50)                stats = "Arc";
        if (num_lvl == 40)                stats = "Lor";
        if (num_lvl == 35)                stats = "Sen";
        if (num_lvl == 33)                stats = "Wiz";
	if (num_lvl == 31)                stats = "New";
	if (num_lvl == 30)                stats = "App";
	if (num_lvl < 30)                 stats = " " + num_lvl;
	if (num_lvl > -1 && num_lvl < 10) stats = " " + stats;
	stats = stats + " ";

							/* sex */
	stats = stats+"("+extract(list[i]->query_gender_string(),0 ,0)+") ";

	age = list[i]->query_age();			/* age */
	if (age / 43200 > 9)      stats = stats + age / 43200 + "D";
	else if (age / 43200 > 0) stats = stats + " " + age / 43200 + "D";
	else if (age / 1800 > 9)  stats = stats + age / 1800 + "h";
	else if (age / 1800 > 0)  stats = stats + " " + age / 1800 + "h";
	else if (age / 30 > 9)    stats = stats + age / 30 + "m";
	else                      stats = stats + " " + age / 30 + "m";

	stats = stats + " I";					/* idle */
	if (query_idle(list[i]) > 999)
	    stats = stats + "dlng ";
        else {
	    stats = stats + ":";
	    if (query_idle(list[i]) < 0)
		stats = stats + "0";
	    else
		stats = stats + query_idle(list[i]);
	    if (query_idle(list[i]) < 100)
	        stats = stats + " ";
	    if (query_idle(list[i]) < 9)
		stats = stats + " ";
	    stats = stats + " ";
	}
	
	if (environment(list[i]))			/* location */
	    location = file_name(environment(list[i]));
	else
	    location = "The Ethereal Plane";

	write(host + name + stats + location + "\n");
	total++;
    }
    write("Total number of ");
    if (inactive)             write ("active ");
    if (males)                write ("female ");
    if (females)              write ("male ");

    /* race here ("'race' ") */

    if (wizards)              write ("players ");
    if (players)              write ("wizards ");
    if (!wizards && !players) write ("persons ");

    /* domain here ("in 'domain' ") */

    if (level)                write ("at level: " + level + " ");
                              write ("shown is " + total + "\n");
    return 1;
}
