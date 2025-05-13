/* The camouflaged region controller for the tidal zone */
#define TO 0
#define FROM 1

string Direction;
string Height;
string Width;
string Guideto;
string Guidefrom;

id(str) { return str == "sign" || str == "regionmaster"; }
short() { return "A WARNING sign"; }
long()  { write("It looks important, maybe you should read it.\n"); }
get()	{ return 0; } /* controller should stay in its place */
query_weight() { return 100; }
init()  { 
	add_action("read", "read" ); 
	/* add_action("print_heights", "print_heights" ); */
	add_action("init_heights", "init_heights" ); 
}

the_height( col, row ) { return Height[col][row]; }

read(str) {
	if (!id(str)) return 0;
	write(
 "                             WARNING!!!\n\n"
+"To the north you enter the Misty Wadden. This is an ever-misty tidal area.\n"
+"The sea in it is biting cold and hard to swim in. Few have the health and\n"
+"power to swim more than a short while in it. The tides change very fast.\n"
+"There are some sandbanks in this area, but they are very slowly moving\n"
+"around, making it impossible to say where they are currently located.\n"
+"Depending on the tide and your equipment, skills, and luck, you may be able\n"
+"to cross the Wadden, but the risks are high. Be warned! THIS AREA KILLS!.\n"
		);	
	return 1;
}

direction( i ) {	/* i should be 0..7 (north..northeast */
	return Direction[i];
}

guide_dir(col, row, wdir) {
	int adir;
	adir = (wdir==TO) ? Guideto[col][row] : Guidefrom[col][row];

	/* say("adir is: "+adir+"\n"); */
	return Direction[adir];
}

reset(arg) {
	if (arg) return;
	/* For service providing function direction(), init. array */
	Direction = ({ "north", "northwest", "west", "southwest", "south",
					"southeast", "east", "northeast", });
	/* 'halve width' for 19 rows */
	Width = ({1,2,2,2,3,3,4,4,4,4,4,3,3,3,2,2,1,1,1,});
	init_heights( 0 );
}

init_heights( arg ) {
	int i, j, k, ic, cdiff, d, prevcol, offset;
	if (Height) return; /* safety first */
	Height = allocate(7);
	if (!Height) return error("Can't allocate Height.\n");
	for (i=0; i<7; i++) {
		Height[i] = allocate(19);
		if (!Height[i]) return error("Can't allocate Height[i].\n");
	}
	if (Guideto) return; /* safety first */
	Guideto = allocate(7);
	if (!Guideto) return error("Can't allocate Guideto.\n");
	for (i=0; i<7; i++) {
		Guideto[i] = allocate(19);
		if (!Guideto[i]) return error("Can't allocate Guideto[i].\n");
	}
	Guidefrom = allocate(7);
	if (!Guidefrom) return error("Can't allocate Guidefrom.\n");
	for (i=0; i<7; i++) {
		Guidefrom[i] = allocate(19);
		if (!Guidefrom[i]) return error("Can't allocate Guidefrom[i].\n");
	}
	for (j=0; j<19; j++) {
		d = 4 - Width[j]; /* how many rooms aside center not in leaf */
		for (i=0; i<d; i++) {
			Height[i][j] = -1;
			Height[6-i][j] = -1;
		}
	}
	prevcol = 3; /* first row has no choice on column of bank */
	grow(prevcol, 0, 5);
	Guidefrom[3][0] = 4;
	for (j=2; j<17; j+=2) {
		offset = random(5) - 2; 
		if (!offset) offset = random(5) - 2; /* redraw once if 1st time 0 */
		i = prevcol + offset;
		if (i<0) i=0;		/* clip against region boundaries */
		else if (i>6) i=6;
		if ( i < 3 - (Width[j]-1) ) i = 3 - (Width[j]-1);
		else if ( i > 3 + (Width[j]-1) ) i = 3 + (Width[j]-1);
		grow(i, j, 5);
		for (k=0; k<i; k++) {
			Guideto[k][j] = 6;
			Guidefrom[k][j] = 6;
		}
		for (k=i+1; k<7; k++) {
			Guideto[k][j] = 2;
			Guidefrom[k][j] = 2;
		}
		/* determine intermediate column between i and prevcol */
		cdiff = i - prevcol; /* -2..+2 */
		switch (cdiff) {
			case 2:
				ic = prevcol + 1;
				Guidefrom[i][j] = 3;
				Guidefrom[ic][j-1] = 3;
				Guideto[ic][j-1] = 7;
				Guideto[prevcol][j-2] = 7;
				break;
			case 1:
				if (j>8) {
					ic = i;
					Guidefrom[i][j] = 4;
					Guidefrom[ic][j-1] = 3;
					Guideto[ic][j-1] = 0;
					Guideto[prevcol][j-2] = 7;
				}
				else {
					ic = prevcol;
					Guidefrom[i][j] = 3;
					Guidefrom[ic][j-1] = 4;
					Guideto[ic][j-1] = 7;
					Guideto[prevcol][j-2] = 0;
				}
				break;
			case -2:
				ic = prevcol - 1;
				Guidefrom[i][j] = 5;
				Guidefrom[ic][j-1] = 5;
				Guideto[ic][j-1] = 1;
				Guideto[prevcol][j-2] = 1;
				break;
			case -1:
				if (j>8) {
					ic = i;
					Guidefrom[i][j] = 4;
					Guidefrom[ic][j-1] = 5;
					Guideto[ic][j-1] = 0;
					Guideto[prevcol][j-2] = 1;
				}
				else {
					ic = prevcol;
					Guidefrom[i][j] = 5;
					Guidefrom[ic][j-1] = 4;
					Guideto[ic][j-1] = 1;
					Guideto[prevcol][j-2] = 0;
				}
				break;
			case 0:
			default:	
				ic = prevcol;
				Guidefrom[i][j] = 4;
				Guidefrom[ic][j-1] = 4;
				Guideto[ic][j-1] = 0;
				Guideto[prevcol][j-2] = 0;
		}
		for (k=0; k<ic; k++) {
			Guideto[k][j-1] = 6;
			Guidefrom[k][j-1] = 6;
		}
		for (k=ic+1; k<7; k++) {
			Guideto[k][j-1] = 2;
			Guidefrom[k][j-1] = 2;
		}
		prevcol = i;
	}
	Guidefrom[3][18] = 4;
	Guidefrom[3][17] = 4;
	Guideto[3][17] = 0;
	Guideto[3][18] = 0;
	Guideto[prevcol][16] = 0;
	grow(prevcol, 18, 5);	/* precol has been forced to be 3 in j==16 */
	return 1;
}

grow(i, j, n) {
	Height[i][j] += n;
	if (j>0) add_Height(i,j-1,2);
	if (j<18) add_Height(i,j+1,2);
	if (i>0) {
		add_Height(i-1,j,2);
		if (j>0) add_Height(i-1,j-1,1);
		if (j<18) add_Height(i-1,j+1,1);
	}
	if (i<6) {
		add_Height(i+1,j,2);
		if (j>0) add_Height(i+1,j-1,1);
		if (j<18) add_Height(i+1,j+1,1);
	}
}

add_Height(i, j, n) { if (Height[i][j]>=0) Height[i][j] += n; }

print_heights() {
	int i, j;
	for (j=18; j>=0; j--) {
		for (i=0; i<7; i++) 
			if (Height[i][j]>=0) write( " " + Height[i][j] );
			else write( "  " );
		write("\n");
	}
	return 1;
}

roomname(col,row) {
	string name;
	if (row<0 || row>18) {
		return "whirlpool";
	}
	if (col<0 || col>6) {
		name = "wp_"+row;
		return name;
	}
	if (Height[col][row]<0) {
		name = "wp_"+row;
		return name;
	}
	name = "t_"+col+"_"+row;
	return name;	
}

error(str) {
	say(str);
	return 0;
}
