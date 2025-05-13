#include "/sys/include/sys_defs.h"

#define FILE_WIDTH	45
#define CHK_IMM		(oTp->IMM || oTp->TESTP)

// This will be a simul_efun eventually.
string getNumStr(int iNum) {
    string *saNumStrs, sRet;

    sRet = "";
    if(iNum < 0) {
        sRet = "minus ";
        iNum = -iNum;
    }
    saNumStrs =({
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine","many"
    });
    sRet += iNum < 10 ? saNumStrs[iNum] : saNumStrs[10];
    return sRet;
}

// This will be a simul_efun eventually.
varargs string pluralise(string sWord, int iNoun) {
    string sTmp, sCap, sFull, *saArr, sLast, sSndLast;

    sCap = CAP(sWord);

    if(strlen(sWord) > 2) {
        if(sCap[0..1] == "A ")
            sWord = sWord[2..<1];
        else if(sCap[0..2] == "An ")
            sWord = sWord[3..<1];
    }

    saArr = explode(sWord, " ");

    if(sizeof(saArr) > 1) {
        sFull = implode(saArr[0..<2], " ")+" ";
        sWord = CAP(saArr[<1]);
    }
    else {
        sFull = "";
        sWord = sCap;
    }

    switch(sWord) {
        case "Tooth":
            return sFull+"Teeth";
            break;
        case "Foot":
            return sFull+"Feet";
            break;
        case "Mouse":
            return sFull+"Mice";
            break;
        case "Louse":
            return sFull+"Lice";
            break;
        case "Man":
            return sFull+"Men";
            break;
        case "Woman":
            return sFull+"Women";
            break;
        case "Child":
            return sFull+"Children";
            break;
        case "Coin":
        case "Coins":
            return sFull+"Coins";
            break;
        case "Sheep":
            return sFull+"Sheep";
            break;
    }
    if(strlen(sWord) <= 2)
        return sFull+sWord;
    else {
        sLast = sWord[<1..<1];
        sSndLast = sWord[<2..<2];
        sTmp = sWord[0..<3];
    }
    switch(sLast) {
        case "s":
            return sFull+sTmp+sSndLast+"ses";
            break;
        case "x":
            return sFull+sTmp+sSndLast+"xes";
            break;
        case "h":
            if(!iNoun)
                return sFull+sTmp+sSndLast+"hes";
            break;
        case "y":
            switch(sSndLast) {
                case "a":
                case "e":
                case "i":
                case "o":
                case "u":
                    break;
                default:
                    return sFull+sTmp+sSndLast+"ies";
                    break;
            }
            break;
        case "e":
            if(sSndLast == "f")
                return sFull+sTmp+"ves";
    }
    return sFull+sWord+"s";
}

varargs int filterInv(object oOb, object oTp, int iFlag) {
    if(iFlag)
        return !interactive(oOb) ||
               (oOb != oTp && !oOb->is_invis_for(oTp));
    else
        return !interactive(oOb) ||
               !oOb->is_invis_for(oTp);
}

int filterLiving(object oOb, int iFlag) {
    return living(oOb) != iFlag;
}

int inventorySize(object oOb) {
    object oTp, *oaInv;

    oTp = TP;
    if(!oOb)
        return 0;
    else
        oaInv = filter_array(all_inventory(oOb), "filterInv",
                             this_object(), oTp);
    return sizeof(oaInv);
}

varargs string longDisplay(object oOb,int iNumber) {
    string sShort, sTmp, sFn, sRet;
    int    i, iScreenWidth;
    object oTp, *oaInv;

    oTp = TP;
    sRet = "";
    iScreenWidth = SCREEN_WIDTH;
    if(!oOb)
        return "";
    else
        oaInv = filter_array(all_inventory(oOb), "filterInv",
                             this_object(), oTp);
    for(i = 0; i < sizeof(oaInv); i++) {
        if(interactive(oaInv[i]))
            sTmp = oaInv[i]->query_name_info();
        else if(living(oaInv[i]))
            sTmp = oaInv[i]->SHORT;
        else {
            sTmp = oaInv[i]->SHORT;
//            if(!sTmp || sTmp == "")
//                sTmp = oaInv[i]->NAME;
        }
        if(sTmp && sTmp != "") {
            sShort = sTmp;
            if(sShort[<1..<1] != ".")
                sShort += ".";
        }
        else
            sShort = (string)0;
        if(CHK_IMM) {
            sFn = "/"+file_name(oaInv[i]);
            if(sFn[0..8] == "/players/")
                sFn = "~"+sFn[9..<1];
            else
                sFn += ((sTmp = creator(oaInv[i]))?
                            " - "+CAP(sTmp):
                            "");
            if(!sShort)
                sShort = "<Invisible>";
            if(iNumber)
                sRet += sprintf("%2d: %-=*s (%-=*s\n",
                                i, (iScreenWidth-FILE_WIDTH-6),
                                capitalize(sShort),
                                FILE_WIDTH,
                                sFn+")");
            else
                sRet += sprintf("%-=*s (%-=*s\n",
                                (iScreenWidth-FILE_WIDTH-2),
                                capitalize(sShort),
                                FILE_WIDTH,
                                sFn+")");
        }
        else if(sShort)
            sRet += sprintf("%-=*s\n",
                            iScreenWidth,
                            capitalize(sShort));
    }
    return sRet;
}

string shortDisplay(object oOb) {
    string sRet, sLiving, sObj, sShort;
    int    iScreenWidth, iSize, iNum;
    object *oaInv, *oaLiving, *oaObj, oTp;
    mixed  *xaLiving, *xaObj;

    oTp = TP;
    sRet = "";
    iScreenWidth = SCREEN_WIDTH;
    if(!oOb)
        return "";
    else
        oaInv = filter_array(all_inventory(oOb), "filterInv",
                             this_object(), oTp, 1);

    if(!sizeof(oaInv))
        return "";

    oaInv = filter_objects(oaInv, "short");
    oaLiving = filter_objects(oaInv, "query_hp");
    oaObj = oaInv-oaLiving;

    xaLiving = unique_array(oaLiving, "query_name_info");
    iSize = sizeof(xaLiving);
    sLiving = "";

    while(iSize) {
        iSize--;
        iNum = sizeof(xaLiving[iSize]);
        sShort = xaLiving[iSize][0]->short();

        if(!sShort || !xaLiving[iSize][0]->query_show_short())
            sShort = xaLiving[iSize][0]->query_name_info();

        if(sShort == "Someone")
            continue;
        else if(iNum == 1)
            sLiving = sprintf("%s%s, ", sLiving, sShort);
        else
            sLiving = sprintf("%s%s %s, ", sLiving,
                              getNumStr(iNum), pluralise(sShort));
    }

    if((iSize = strlen(sLiving)) > 2) {
        sLiving = sLiving[0..<3];
        sLiving = CAP(sLiving)+".\n";
        sRet += sLiving;
    }

    xaObj = unique_array(oaObj,"query_name");
    iSize = sizeof(xaObj);
    sObj = "";

    while(iSize) {
        iSize--;
        iNum = sizeof(xaObj[iSize]);
        sShort = xaObj[iSize][0]->short();

        if(sShort) {
            if(!xaObj[iSize][0]->query_show_short())
                sShort = xaObj[iSize][0]->query_name();

            if(iNum == 1)
                sObj = sprintf("%s%s, ", sObj, CAP(sShort));
            else
                sObj = sprintf("%s%s %s, ",
                               sObj,
                               getNumStr(iNum),
                               CAP(pluralise(sShort)));
            oaObj -= xaObj[iSize];
        }
    }
    if(sizeof(oaObj)) {
        xaObj = unique_array(oaObj,"short");
        iSize = sizeof(xaObj);
        while(iSize) {
            iSize--;
            iNum = sizeof(xaObj[iSize]);
            sShort = xaObj[iSize][0]->short();

            if(sShort) {
                if(iNum == 1)
                    sObj = sprintf("%s%s, ", sObj, CAP(sShort));
                else
                    sObj = sprintf("%s%s %s, ",
                                   sObj,
                                   getNumStr(iNum),
                                   CAP(pluralise(sShort)));
            }
        }
    }
    if(strlen(sObj) > 2) {
        sObj = sObj[0..<3];
        sObj = CAP(sObj)+".\n";
        sRet += sObj;
    }
    return sprintf("%-=*s", iScreenWidth, sRet);
}
