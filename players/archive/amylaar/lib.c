enrune3(str)
{
	int c;

    string run1,run2,run3,delim,delim2;
    int i,j;
    run1=run2=run3= "";
    delim=delim2="";
    if (!str) str="";
    for(j=0;c=str[j];j++)
    {
	if (str[j] > 64 )
		i=({0,0,0,0,1,0,0,0,0,0,0,0,0,2,0,0,0,0,0,3,0,0,0,0,0,0,
		0,0,0,0,0,0,
		4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,		
		21,22,23,24,25,26,27,28,29
		})[str[j]-65];
	else
        { delim2="*"; continue; }
run1=run1+delim+({
    "","V|V","\\/","| ",
    "|\\",
    "|\\",
    "| ","| |","|V|","|/","  ","|\\|","|"," ","| ","|\\",
    "|X|","\\| ","|V","|V","","|\\",
    "|/","/|\\",
    "|\\",
    "/\\",
    "|\\",
    "\\|/","/-\\",
    ""
})[i];
run2=run2+delim2+({
    ""," | ","<>","|>",
    "|\\",
    "|<","|\\",
    "|>|","| |","|/","\\/","|\\|","|","+","|\\",
    "| ","| |"," | ","|V","| ","","|/","| "," | ",
    "||","||","|/"," | ","| |",""
})[i];
run3=run3+delim+({
    ""," | ","/\\",
    "| ",
    "| ","|/","||","| |","| |","| ","/\\",
    "| |","|"," ","||","| ","| |"," |\\",
    "| ","|^","","|\\",
    "| "," | ","||","||","| "," | ","|x|",""
})[i];
        delim=delim2=" ";
    }
    return ({run1,run2,run3});
}

xenrune(str,d1,d2)
{
    string arr;
    arr=enrune3(str);
    return arr[0]+d1+arr[1]+d2+arr[2];
}

enrune(str) { 
return xenrune(str,"\n","\n")+"\n" ; }

make_sign(str,dest)
{
    object sign;

    move_object(sign=clone_object("players/amylaar/sign"),dest);
    sign->set_name("sign");
    sign->set_text(str);
    return sign;
}

query_rnumbers(i) { return({
	"xero","one","two","Tree","four","five","six","seven","eight",
	"nine","ten","eleven","twelve","Tirteen","fourteen","fiveteen","sixteen"
	})[i]; }

query_number(i) {
    int j;
    string s;

    if ( i < 0 ) return "minus "+query_number(-i);
    if ( i < 20 ) return({
	"zero","one","two","three","four","five","six","seven","eight",
	"nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
	"sixteen","seventeen","eighteen","nineteen",
	})[i];
    if ( i < 100 ) {
	s=({
	    0,0,"twenty","thirty","fourty","fifty",
	    "sixty","seventy","eighty","ninety",
	})[j=i/10];
	if ( i=i-10*j ) return s+"-"+query_number(i);
	else return s;
    }
    return "many";
}

can_carry(obj) {
int i;

    for(i=30;i>=0;i--)
	if ( obj->add_weight(i) ) {
	    obj->add_weight(-i);
	    return i;
	}
}

referent(obj) {
int	i;
string	s;

	if (!obj) obj=this_object();
	if ( sscanf(file_name(obj),"%s#%d",s,i) == 2 ) {
		for(i=0,s=s+"#";!find_object(s+i);i++) 0;
		return find_object(s+i);
	}
}

uref(str) {
int	i;
string	u;

	u=users();
	for(i=0;i<sizeof(u);i++)
		if(present(u[i],str)) return present(u[i],str);
}

a_thing(str)
{
	int c;

	c=str[0];
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return "an "+str;
	else
		return "a "+str;
}

tell_others(str,p,p2) {
object	o,n;
    for(o=first_inventory(environment(p));o;o=n) {
	n=next_inventory(o);
	if ( o!=p && o!=p2 ) tell_object(o,str);
    }
}
