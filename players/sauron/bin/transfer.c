#include "/players/sauron/include/include.h"

int main(string sStr) {
    string sWhat, sWho;
    int    iRet;
    object oWhat, oWho;

    if(!sStr || sscanf(sStr, "%s to %s", sWhat, sWho) != 2) {
        notify_fail("Syntax: transfer <object> to <player>\n");
        return 0;
    }

    else if(!(oWhat = present(sWhat, TP))) {
        notify_fail("You are not carrying an object which answers to '"
                    +sWhat+"'.\n");
        return 0;
    }

    else if(!(oWho = find_player(sWho))) {
        notify_fail(CAP(sWho)+" is not currently logged on.\n");
        return 0;
    }

    else {
        iRet = transfer(oWhat, oWho);
         if(!iRet) {
            printf("You trasnfered your %s to %s.\n",
                   sWhat, CAP(sWho));
            TELLO(oWho, sprintf("%s just transfered %s to you.\n",
                                CRNAME(TP), CAP(sWhat)));
        }
        else
            printf("transfer: transfer(%s, %s) returned %d.\n",
                   sWhat, sWho, iRet);
        return 1;
    }
}

