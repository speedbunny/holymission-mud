/* 040996 Saffrin: coded the Love Charm */
inherit "obj/treasure";

#include "/players/saffrin/defs.h"

reset(arg) {
    if(arg) return;
    set_id("Saffrin's Love Charm");
    set_alias("charm");
    set_weight(1);
    set_value(8);
    set_short(TPQN +"'s Love Charm");
    set_long("Saffrin's Love Charm.  This is a special love charm casted\n"+
      "for you by Saffrin.  It is said to bring love closer to your heart.\n"+
      "For its best use type 'helpcharm'.\n");
}
init()
{
    ::init();
    AA("coil", "coil");
    AA("_helpcharm", "helpcharm");
    AA("click", "click");
    AA("cslurp", "cslurp");
    AA("cmoan", "cmoan");
    AA("ctackle", "ctackle");
    AA("cpounce", "cpounce");
    AA("cwrap", "cwrap");
    AA("cclose", "cclose");
    AA("clove", "clove");
    AA("cheart", "cheart");
    AA("cgasp", "cgasp");
    AA("cpant", "cpant");
    AA("clive", "clive");
    AA("csing", "csing");
    AA("cgrope", "cgrope");
    AA("cfondle", "cfondle");
    AA("ccheek", "ccheek");
}

coil(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no " + capitalize(str) + " on the game!\n");
    write("You massage "+ CAP(str) +"'s body with exotic oils!\n");
    TELL(victim,CAP(TPRN) +" massages your body with exotic oils!\n");
    return 1;
}
cheart(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+CAP(str)+" on the game!\n");
    write("You send "+CAP(str)+" a lovely:\n");
    write("\n");
    write("        ** **  \n");
    write("       ******* \n");
    write("       ******* \n");
    write("        *****  \n");
    write("         ***   \n");
    write("          *    \n");
    TELL(victim,CAP(TPRN) +" sends you a lovely:\n"+
      "\n"+
      "        ** **   \n"+
      "       *******  \n"+
      "       *******  \n"+
      "        *****   \n"+
      "         ***    \n"+
      "          *    \n");
    return 1;
}
click(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no " +CAP(str) + " on the game!\n");
    write("You lick "+ CAP(str) +" from head to toe!\n");
    TELL(victim,CAP(TPRN) +" licks you from head to toe!\n");
    return 1;
}
cslurp(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no "+ CAP(str) +" on the game!\n");
    write("You slurp "+ CAP(str) +" lustfully!\n");
    TELL(victim,CAP(TPRN) +" slurps you lustfully!\n");
    return 1;
}
cmoan(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no "+ CAP(str) +" on the game!\n");
    write("You moan passionately at "+ CAP(str) +".\n");
    TELL(victim,CAP(TPRN) +" moans passionately at you.\n");
    return 1;
}
ctackle(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no "+ CAP(str) +" on the game!\n");
    write("You lovingly tackle "+ CAP(str) +" to the ground!\n");
    TELL(victim,CAP(TPRN) +" lovingly tackles you to the ground!\n");
    return 1;
}
cpounce(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no "+ CAP(str) +" on the game!\n");
    write("You pounce playfully on top of "+ CAP(str) +"!\n");
    TELL(victim,CAP(TPRN) +" playfully pounces on top of you!\n");
    return 1;
}
cwrap(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write("There is no "+ CAP(str) +" on the game!\n");
    write("You wrap your arms around "+ CAP(str) +".\n");
    TELL(victim,CRN+" wraps "+TPOSS+" arms around you.\n");
    return 1;
}
cclose(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You pull "+ CAP(str) +" close in a tight embrace.\n");
    TELL(victim,CAP(TPRN) +" pulls you close in a tight embrace.\n");
    return 1;
}
clove(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You look at "+ CAP(str) +" with love in your eyes.\n");
    TELL(victim,CRN+" looks at you with love in "+TPOSS+" eyes.\n");
    return 1;
}
cgasp(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You gasp is delight at "+CAP(str) +".\n");
    TELL(victim,CAP(TPRN) +" gasps in delight at you.\n");
    return 1;
}
cpant(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You pant at "+ CAP(str) +" passionately.\n");
    TELL(victim,CAP(TPRN) +" pants passionately at you.\n");
    return 1;
}
clive(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You tell "+ CAP(str) +" that you cannot live without them.\n");
    TELL(victim,CRN+" tells you that "+TPRO+" cannot live without you.\n");
    return 1;
}
csing(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You sing a love ballad to "+ CAP(str) +".\n");
    TELL(victim,CAP(TPRN) +" sings you a love ballad.\n");
    return 1;
}
ccheek(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You caress "+ CAP(str) +"'s cheek softly.\n");
    TELL(victim,CAP(TPRN) +" caresses your cheek softly.\n");
    return 1;
}
cgrope(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You grope "+ CAP(str) +" tenderly.\n");
    TELL(victim,CAP(TPRN) +" gropes you tenderly.\n");
    return 1;
}
cfondle(str)
{
    object victim;
    victim=FP(str);
    if(!victim) return write ("There is no "+ CAP(str) +" on the game!\n");
    write("You fondle "+ CAP(str) +" seductively.\n");
    TELL(victim,CAP(TPRN) +" fondles you seductively.\n");
    return 1;
}
_helpcharm()
{
    write("This special love charm enables you to woo a person from anwhere\n");
    write("on the mud.  The syntax is '<action> <name>'.\n");
    write("\n");
    write("Actions:\n");
    write("          coil    click   cslurp  cmoan   \n");
    write("          cwrap   cclose  clove   ctackle \n");
    write("          cgasp   cpant   csing   cpounce \n");
    write("          ccheek  cgrope  cfondle  cheart \n");
    write("\n");
    write("If you have any suggestions, mail them to Saffrin.\n");
    return 1;
}

query_auto_load() {
    return "/players/saffrin/fun/inv/charm:";
}
drop() {
    return 1;
}
