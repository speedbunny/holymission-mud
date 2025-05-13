
#define TP     this_player()
#define TPL    TP->query_level()
#define TPStr  TP->query_str()
#define TPDex  TP->query_dex()
#define TPWis  TP->query_wis()
#define TPInt  TP->query_int()
#define TPCha  TP->query_cha()
#define TPCon  TP->query_con()

#define VALID_SKILLS {"Karate","Defense","Weapon","Ninjitsu"}

string getSkillTitle(string skill);

status main()
{
    int loop;
    printf("Your Ninja skills are:\n\n");   
    printf("Defense: "+getSkillTitle("Defense")+" ");
    printf("	Karate: "+getSkillTitle("Karate")+"\n");
    printf("Weapon: "+getSkillTitle("Weapon")+" ");
    printf("	Ninjitsu: "+getSkillTitle("Ninjitsu")+"\n");
    return 1;
}

string getSkillTitle(string skill)
{
    int main, sub;
    int total;
    string ret;

    total=0;
    switch(skill) 
    {
    case "Karate":
	total+=TPL*TPDex*3/4;
	total+=TPL*TPStr/4;
	break;

    case "Defense":
	total+=(TPDex/5+(TPL/(5+TPL/25)))*91;
	break;

    case "Weapon":
	total+=TPL*TPDex/2;
	total+=TPL*TPStr/2;
	break;

    case "Ninjitsu":
	total+=TPL*TPDex/6;
	total+=TPL*TPWis/6;
	total+=TPL*TPInt/6;
	total+=TPL*TPCon/6;
	total+=TPL*TPStr/6;
	total+=TPL*TPCha/6;
	break;
    default:
	printf("Bad skill\n");
	break;
    }
    main = (total) / 116;
    if ( main == 11 )
	return( "guru" );

    sub = (total) % 9;

    switch( sub ) {
    case 0:  ret = "novice "; break;
    case 1:  ret = "apprentice "; break;
    case 2:  ret = ""; break;
    case 3:  ret = "confident "; break;
    case 4:  ret = "seasoned "; break;
    case 5:  ret = "expert "; break;
    case 6:  ret = "eminent "; break;
    case 7:  ret = "brilliant "; break;
    case 8:  ret = "superior "; break;
    default: ret = "";
    }
    switch( main ) {
    case 0:  ret += "beginner"; break;
    case 1:  ret += "student"; break;
    case 2:  ret += "amateur"; break;
    case 3:  ret += "layman"; break;
    case 4:  ret += "acolyte"; break;
    case 5:  ret += "journeyman"; break;
    case 6:  ret += "craftsman"; break;
    case 7:  ret += "professional"; break;
    case 8:  ret += "veteran"; break;
    case 9:  ret += "master"; break;
    case 10: ret += "teacher"; break;
    default: ret += "";
    }

    return( ret );
}

