/* generic note for qquest old man note of requested objects */
/* contains a list of standard-lists of items+nr.wanted*/

int nr_wanteditems;
int nr_wantedlists;
string wanteditems;
string wantedlists;
/* possibly wanted items all have a nr. (being the index to next array) */

get_names(i, names) {
	int t;
	int nnames;
	nnames = sizeof(wantedlists[i])/2;
	for (t=0; t<nnames; t++) {
		names[t] = wantedlists[i][t*2];
	}
	return 1;
}

nr_list_items(i) { return ( sizeof(wantedlists[i])/2); }
wanted_items(i ) { return wanteditems[i]; }

get_amounts(i, amounts) {
	int t;
	int nnames;
	nnames = sizeof(wantedlists[i])/2;
	for (t=0; t<nnames; t++) {
		amounts[t] = wantedlists[i][(t*2)+1];
	}
	return 1;
}

reset(arg) {
	if (arg) return;
	wanteditems = ({
			"diagnoser", "tomato", "spinach", "bean", "lettuce",
			"nettle", "stinkhorn", "fungus", "mildew",
			"skunk tail", "viper teeth", "rat claws", "hyena claws",
			"jackal claws", "gall mite bag", "greenbug teeth", "moth mantle", 
			"cockroach shield", "acorn", "beechnut", "grabbit claws",
				});
	nr_wanteditems = sizeof(wanteditems);
	nr_wantedlists = 10;
	wantedlists = allocate(nr_wantedlists);
	if (!wantedlists) {
		write("can't allocate wantedlists.\n");
		return 0;
	}
	/* fomrat of a wantedlist:   itemnr, nrwanted, ... */
	wantedlists[0] = ({ 0,4,  1,1, 7,1, 11,1, 15,1, 19,1, 9,1 });
	wantedlists[1] = ({ 0,4,  2,1, 8,1, 10,1, 16,1, 18,1, 20,1 });
	wantedlists[2] = ({ 0,4,  3,1, 6,1, 9,1, 14,1, 17,1, 13,1 });
	wantedlists[3] = ({ 0,4,  4,1, 5,1, 12,1, 15,1, 20,1, 17,1 });
	wantedlists[4] = ({ 0,4,  4,1, 6,1, 13,1, 19,1, 18,1, 16,1 });
	wantedlists[5] = ({ 0,4,  3,1, 7,1, 10,1, 15,1, 16,1, 8,1 });
	wantedlists[6] = ({ 0,4,  2,1, 5,1, 11,1, 14,1, 20,1, 8,1 });
	wantedlists[7] = ({ 0,4,  1,1, 8,1, 9,1, 19,1, 18,1, 17,1 });
	wantedlists[8] = ({ 0,4,  1,1, 5,1, 13,1, 14,1, 16,1, 10,1 });
	wantedlists[9] = ({ 0,4,  2,1, 7,1, 9,1, 15,1, 17,1, 20,1 });
}
