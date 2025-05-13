/*
 * This is the guild master.
 * 
 * This object is not designed for cloning or inheriting.
 * Use it by calling the functions listed below.
 * You can assume that the object is loaded in room/init_file,
 * so don't load it yourself but refer to the funtions in a style like:
 *
 * value = "obj/guild_master"->query_function_value(params); 
 *
 * Refer to a specific guild only via the guildnumber.
 * The adventurers guild is number 0 by default. 
 *
 * It is needed that both, the guild room and the guild soul path name
 * are name according to the following conventions:
 *
 * guild_room: "/players/<responsive_wiz>/guild/guild.c"
 * guild_soul: "/players/<responsive_wiz>/guild/soul.c"
 *
 * If you want to establish your own guild, contact the adminstrators.
 * Your guild will be assigned a number, and all your guild's information
 * has to be stored in this file.
 *
 * These are the functions defined in the guild_master:
 * ===================================================
 * 
 * query_name		... returns the name of the guild 
 * query_soul		... returns the pathname to the guildsoul
 * query_room		... returns the pathname to the guildroom
 * query_wiz		... returns the name of responsible wiz
 * query_levels		... returns the number of levels in this guild
 * query_pretitle	... returns the pretitle for a level in a guild
 * query_title		... returns the title for a level in a guild
 * query_exp		... returns the base exp for a level in a guild
 *
 */

#define ADV_GUILD	"room/adv_guild"
#define NUM_GUILDS	5

string gd_info;
string gd_defines;

short() { return "The Guild Master"; }

long() { write(short()+".\n"); }

init() { add_action("dump","dump"); }

dump(str) {
int i,gd,gnd;

  if (!str) {
    for (i=0;i<NUM_GUILDS;i++) {
	write("["+i+"] ");
	write(gd_info[i][0]+"\t"+gd_info[i][1]+"\t"+gd_info[i][2]+"\t"+gd_info[i][3]+"\n");
    }
    return 1;
  }

  if (str) sscanf(str,"%d %d",gd,gnd);
  write("You typed "+gd+" and "+gnd+"\n");
  for (i=0;i<query_levels(gd);i++) {
    write("["+i+"] ");
    if (gd_info[gd][3]) {	/* Gender support supplied */
       write(gd_defines[gd][i][0][gnd]+", ");
       write(gd_defines[gd][i][1][gnd]+", ");
    }
    else {
       write(gd_defines[gd][i][0]+", ");
       write(gd_defines[gd][i][1]+", ");
    }
    write(gd_defines[gd][i][2]);
    write("\n");
  }
  return 1;
}

reset(arg) {
int i;

  if (arg) return;	/* Allocate not needed anymore */
  set_light(1);		/* Oh well :-) */
  gd_info = ({
    
    /* Name		Wiz		Levels  Genders */

    ({ "adventurer",	0,		20,	1	}),
    ({ "thief",		"herp",		30,	0	}),
    ({ "mage",		0,		0,	0	}),
    ({ "fighter",	"capablanca",	30,	0	}),
    ({ "jedi",		"kelly",	30,	0	})

  });

  gd_defines = ({ query_defines(0) }); 
  for (i=1;i<NUM_GUILDS;i++) 
      gd_defines = gd_defines + ({ query_defines(i) }); 
}

/* These routines must be called when the player logs on */

query_name(gd) { return gd_info[gd][0]; }

query_wiz(gd) { return gd_info[gd][1]; }

query_room(gd) { 
  if (!gd) return ADV_GUILD;
  else return "players/"+gd_info[gd][1]+"/guild/guild"; }

query_soul(gd) { if (gd) return "players/"+gd_info[gd][1]+"/guild/soul"; }

query_levels(gd) { return gd_info[gd][2]; }

query_pretitle(gd,lvl,gender) {
  lvl=gd_info[gd][2]-lvl;		/* reverted array sequence */ 
  if (lvl<0) return 0;
  if (gd_info[gd][3]) 			/* Gender supported */
     return gd_defines[gd][lvl][0][gender];
  else
     return gd_defines[gd][lvl][0];	/* Gender not supported */
}

query_title(gd,lvl,gender) {
  lvl=gd_info[gd][2]-lvl;		/* reverted array sequence */
  if (lvl<0) return 0;
  if (gd_info[gd][3])			/* Gender supported */
     return gd_defines[gd][lvl][1][gender];
  else
     return gd_defines[gd][lvl][1];	/* Gender not supported */
}

query_exp(gd,lvl) {
  lvl=gd_info[gd][2]-lvl;		/* reverted array sequence */ 
  if (lvl>-1) return gd_defines[gd][lvl][2];
}

query_defines(gd) {

  switch (gd) {

  case 0 : /* Adventurer Guild , Gender is supported */

  return ({

  ({ ({ 0,0,0 }), /* this is the pretitle field, 0 if on pretitle */
     ({ "the apprentice Wizard", "the apprentice Wizard",
	"the apprentice Wizard" }) ,		1000000 }),	/* 20 */
  ({ ({ 0,0,0 }),
     ({ "the grand master sorcerer", "the grand master sorceress",
	"the ferocious tyrannosaur" }),		666666 }),	/* 19 */
  ({ ({ 0,0,0 }),
     ({ "the master sorcerer", "the master sorceress", 
	"the small tyrannosaur" }),		444444 }),	/* 18 */
  ({ ({ 0,0,0 }),
     ({ "the apprentice sorcerer", "the apprentice sorceress", 
	"the vicious dragon" }),		296296 }),	/* 17 */
  ({ ({ 0,0,0 }), 
     ({ "the warlock", "the witch", "the devicious dragon" }),
						197530 }),	/* 16 */
  ({ ({ 0,0,0 }), 
     ({ "the enchanter", "the enchantress", "the small dragon"}),
						131687 }),	/* 15 */
  ({ ({ 0,0,0 }), 
     ({ "the magician", "the magicienne", "the powerful demon" }),
						97791 }),	/* 14 */
  ({ ({ 0,0,0 }),
     ({ "the apprentice magician", "the apprentice magicienne",
	"the small demon" }),			77791 }),	/* 13 */
  ({ ({ 0,0,0 }),
     ({ "the conjurer", "the conjuress", "the beholder" }),
						58527 }),	/* 12 */
  ({ ({ 0,0,0 }),
     ({ "the champion", "the deadly amazon", "the great monster" }),
						39018 }),	/* 11 */
  ({ ({ 0,0,0 }),
     ({ "the warrior", "the amazon", "the experienced monster" }),
						26012 }),	/* 10 */
  ({ ({ 0,0,0 }),
     ({ "the great adventurer", "the great adventuress",
	"the medium monster" }),		17341 }),	/*  9 */
  ({ ({ 0,0,0 }),
     ({ "the experienced adventurer", "the experienced adventuress",
	"the small monster" }),			11561 }),	/*  8 */
  ({ ({ 0,0,0 }),
     ({ "the small adventurer", "the small adventuress", 
	"the threathening shadow" }),		7707 }),	/*  7 */
  ({ ({ 0,0,0 }),
     ({ "the experienced fighter", "the charming siren", "the shadow" }),
						5138 }),	/*  6 */
  ({ ({ 0,0,0 }),
     ({ "the small fighter", "the siren", "the wraith" }),
						3425 }),	/*  5 */
  ({ ({ 0,0,0 }),
     ({ "the master ranger", "the master ranger", "the bugbear" }),
						2283 }),	/*  4 */
  ({ ({ 0,0,0 }),
     ({ "the lowrank ranger", "the lowrank ranger",
	"the furry creature" }),		1522 }),	/*  3 */
  ({ ({ 0,0,0 }),
     ({ "the simple wanderer", "the simple wanderer",
	"the simple creature" }),		1014 }),	/*  2 */
  ({ ({ 0,0,0 }),
     ({ "the utter novice", "the utter novice", "the utter creature" }),
						676 })		/*  1 */
  });


  case 1 : /* Thieves Guild, Gender is not supported */

  return ({

  ({ 0,		"the Apprentice Wizard",	12000000 }),	/* 30 */
  ({ 0,		"the Prince of Thieves",	11000000 }),
  ({ "Sultan",	"the Flamboyant Thief",		10000000 }),
  ({ "Shah",	"the Extraordinary Thief",	9000000 }),
  ({ "Mufti",	"the Marvelous Thief",		8000000 }),
  ({ "Grand Vizier", "the Splendid Thief",	7000000 }),
  ({ "Pasha",	"the Dazzling Thief",		6000000 }),
  ({ "Sheik",	"the Brilliant Thief",		5000000 }),
  ({ "Padisha",	"the Polished Thief",		4000000 }),
  ({ "Vizier",	"the Remarkable Thief",		3000000 }),
  ({ "Valis",	"the Talanted Thief",		2200000 }),	/* 20 */
  ({ "Amir",	"the Accomplished Thief",	1600000 }),
  ({ 0,		"the Grand Master Thief",	1000000 }),
  ({ 0,		"the Master Thief",		700000 }),
  ({ 0,		"the Expert Thief",		450000 }),
  ({ 0,		"the Master Rogue",		300000 }),
  ({ 0,		"the Expert Rogue",		215000 }),
  ({ 0,		"the Apprentice Rogue",		180000 }),
  ({ 0,		"the Veteran Buccaneer",	130000 }),
  ({ 0,		"the Master Burglar",		90000 }),
  ({ 0,		"the Professional Robber",	60000 }), 	/* 10 */
  ({ 0,		"the Expert Swindler",		40000 }),
  ({ 0,		"the Marauder",			25000 }),
  ({ 0,		"the Brigand",			17000 }),
  ({ 0,		"the Experienced Pickpocket",	11000 }),
  ({ 0,		"the Simple Thug",		7500  }),	/*  5 */
  ({ 0,		"the Footpad",			5000  }),
  ({ 0,		"the Prankster",		1600  }),
  ({ 0,		"the Novice Sneak",		800   }),
  ({ 0,		"the Neophyte Thief",		0     })	/*  1 */

  });

  case 2 : /* Mages guild, nothing supported, arch banished */

  return ({ 0 }); 

  case 3 : /* Fighters guild, gender not supported */

  return ({
 
  ({ 0,  "the Apprentice Wizard", 12000000 }),
  ({ "War Lord",  "of Holy mission", 11000000 }),
  ({ "Overlord", "of Fighters Guild",  10000000 }),
  ({ "Lord", "of Fighters Guild", 9000000 }),
  ({ "Commandant", "of Fighters Guild", 8000000 }),
  ({ "Captain", "of Fighters Guild", 7000000 }),
  ({ "Fighter", "the Fighter Commandant",  6000000 }),
  ({ "Fighter", "the Fighter Captain",  5000000 }),
  ({ "Fighter", "the training Lord",  4000000 }),
  ({ "Fighter", "the training Commandant",  3000000 }),
  ({ "Fighter", "the training Captain",  2200000 }),
  ({ "Fighter", "the Vicount", 1600000 }),
 
  ({ "Fighter",  "the Duke", 1000000 }),
  ({ "Fighter",  "the Baron",  700000 }),
  ({ "Fighter",  "the Earl",  450000 }),
  ({ "Fighter",  "the Count",  300000 }),
  ({ "Fighter",  "the Knight",  215000 }),
  ({ "Fighter",  "the Champion",  180000 }),
  ({ "Fighter",  "the Warrior", 130000 }),
  ({ "Fighter",  "the Conqueror",  90000 }),
  ({ "Fighter",  "the Weapons Master", 60000 }),
  ({ 0,  "the greater Fighter",  40000 }),
  ({ 0,  "the Soldier",   25000 }),
  ({ 0,  "the Fighter",   17000 }),
  ({ 0,  "the Trooper", 11000 }),
  ({ 0,  "the Myrmidon",  7500  }),
  ({ 0,  "the Combantant",  5000  }),
  ({ 0,  "the Peacemaker",  1600  }),
  ({ 0,  "the Squire",  800   }),
  ({ 0,  "the Hopefull Squire",  0     })
 
  });

  case 4 : /* Jedi guild, Kelly, what ya doin ? */
  return ({ 0 });

  } /* End switch */
 
}
