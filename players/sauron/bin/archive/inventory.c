#include "/sys/include/sys_defs.h"

#define INVENTORY_D	"/players/sauron/daemon/inventoryd"
#define CHK_IMM		(oTp->IMM || oTp->query_testchar())

int main(string sStr) {
    string sShort,sTmp,sFn;
    object oOb,oMe,oTp;

    oTp=TP;
    if(!oTp)
        return 0;
    else if(sStr && CHK_IMM) {
        if(sStr=="here") {
            oMe=ENV(oTp);
            if(!oMe) {
                notify_fail("You have no environment.\n");
                return 0;
            }
            else
                printf("Your environment (/%s) contains:\n\n",
                       file_name(oMe));
        }
        else {
            oMe=find_player(LOW(sStr));
            if(!oMe) {
                notify_fail(CAP(sStr)
                            +" is not playing at this time.\n");
                return 0;
            }
            else if(oMe!=oTp)
                printf("%s'%s inventory contains:\n\n",CAP(sStr),
                                                       (sStr[<1..<1]=="s"?
                                                           "":
                                                           "s"));
        }
    }
    else
        oMe=oTp;

    if(!oMe || (oMe->test_dark() && !CHK_IMM))
        return 1;
    else
        write(INVENTORY_D->longDisplay(oMe));
    if(oMe==oTp)
        say(sprintf("%s just checked %s inventory.\n",
                    oMe->TNAME,oMe->POS),
            0,oMe,"");
    return 1;
}

string help() {
    object oTp;

    oTp=TP;
    if(!oTp)
        return "";
    else
        return "\
Command:\tinventory"+(CHK_IMM?" <player>":"")+"\n\
Arguments:\tnone"+(CHK_IMM?", here, or an on-line player":"")+".\n\
See also:\tlook\n\
\n\
This command allows you to check your inventory and see what you are \
carrying, assuming that you have enough light to see that is."+
(CHK_IMM?
     " As a"+(oTp->query_testchar()?" testplayer":"n immortal")
    +" you can also look at your environment's inventory using the \
argument \"here\", or another player's inventory by specifying their \
name as the argument.":
     "")+"\n";
}
