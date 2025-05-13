mixed query_hit_msg(int tmp,string name,object att,object def) 
{
    return _query_hit_msg(tmp,name,att,def); 
}

static mixed _query_hit_msg(int tmp,string name,object att,object def) 
{
    string what,how;

    switch (tmp) 
    {
    case 1:     
	how = " in the stomach";
	what= "tickled";
	break;
    case 2:	
	how = "";
	what= "grazed";
	break;
    case 3..4:   
	how = "";
	what= "hit";
	break;
    case 5..9:	
	how = " hard";
	what= "hit";
	break;
    case 10..14: 
	how = " pretty hard";
	what = "hit";
	break;
    case 15..19: 
	how = " very hard";
	what= "hit";
	break;
    case 20..29: 
	how = " extremely hard";
	what = "hit";
	break;
    case 30..39: 
	how = " with a bone crushing sound";
	what = "smashed";
	break;
    case 40..49: 
	how = " to small fragments";
	what = "massacred";
	break;
    case 50..59: 
	how = " into a puddle of blood and body parts";
	what = "pounded";
	break;
    case 60..69:
	how = " with a hit";
	what = "obliterated";
	break;
    case 70..79:
	how = " with a ferocious hit";
	what = "annihilated";
	break;
    case 80..89:
	how = "";
	what = "did an insane amount of damage to";
	break;
    default: 
	how = " with a devastating blow";
	what = "massacred";
	break;
    }
    return ({ what + " " + name + how + ".",
      what + " you" + how + ".",
      what + " " + name + how + "." });
}
