#include <sys_defs.h>
#include <sys_levels.h>

#pragma strict_types
#pragma save_types

#define FILTER(x)	filter_array(users(), x, TO);
#define L_LEGEND	50

int iIdleC, iImmortal, iMortal;

int Mortal(object oOb) {
    return !(int)oOb->IMM;
}

int Immortal(object oOb) {
    return (int)oOb->IMM;
}

int Male(object oOb) {
    return (int)oOb->query_gender() == 1;
}

int Female(object oOb) {
    return (int)oOb->query_gender() == 2;
}

int Legendary(object oOb) {
#ifdef NEWLEVELSYSTEM
    return (int)oOb->query_level() > L_LEGEND;
#else
    return (int)oOb->query_legend_level() ? 1 : 0;
#endif // NEWLEVELSYSTEM
}

int Arena(object oOb) {
    return ((int)(environment(oOb) && environment(oOb)->query_arena()));
}

int whosort(object oOb1, object oOb2) {
    int l1, l2;

    l1 = (int)oOb1->query_wiz_level();
    l2 = (int)oOb2->query_wiz_level();
    if(l1)
        l1 *= 100;
    else
#ifdef NEWLEVELSYSTEM
        l1 = (int)oOb1->query_level();
#else
        l1 = (int)oOb1->query_level()+(int)oOb1->query_legend_level();
#endif // NEWLEVELSYSTEM
    if(l2)
        l2 *= 100;
    else
#ifdef NEWLEVELSYSTEM
        l2 = (int)oOb2->query_level();
#else
        l2 = (int)oOb2->query_level()+(int)oOb2->query_legend_level();
#endif // NEWLEVELSYSTEM

    return l1 < l2;
}

string makeIdle(int iIdle) {
    string sStr;
    int    i;

    switch(iIdle) {
        case 0..59:
            sStr = "";
            break;
        case 60..3599:
            i = iIdle/60;
            sStr = sprintf(" %dm", i);
            break;
        default:
            i = iIdle/3600;
            sStr = sprintf(" %dh", i);
            break;
    }
    return sStr;
}

varargs string makeTitle(object oOb, int iFlag) {
    string sTmp;
    int    iAfk, iIdle;

    if(iFlag)
        return (string)oOb->query_presentation();
    else {
        sTmp = (string)oOb->query_name_info();
        iAfk = (int)oOb->is_afk();
        iIdle = (int)query_idle(oOb);
        if(iIdle > 60 || iAfk)
            iIdleC++;
    }

    if(iAfk)
        sTmp = sprintf("%s (afk%s)", sTmp, makeIdle(iIdle));
    else if(iIdle >= 60)
        sTmp = sprintf("%s (idle%s)", sTmp, makeIdle(iIdle));

    return sTmp;
}

string makeLevel(object oOb) {
    string sTestchar;
    int    iLegend, iLevel;

    sTestchar = (string)oOb->TESTP;
    iLevel = (int)oOb->query_level();
    switch((int)oOb->query_wiz_level()) {
        case WL_PLAYER..WL_SOCWIZ-1:
            iMortal++;
            if((iLegend = (int)oOb->query_legend_level()))
                return sprintf("  [%s %:03d]",
                               sTestchar ? "T" : "L", iLegend);
            else
                return sprintf("  [%s %:03d]",
                               sTestchar ? "T" : "P", iLevel);
            break;
        case WL_SOCWIZ..WL_APPR-1:
            iImmortal++;
            return "[Social]";
            break;
        case WL_APPR..WL_NEWWIZ-1:
            iImmortal++;
            return "[Appr]";
            break;
        case WL_NEWWIZ..WL_WIZ-1:
            iImmortal++;
            return "[NewWiz]";
            break;
        case WL_WIZ..WL_SAGE-1:
            iImmortal++;
            return "[Wizard]";
            break;
        case WL_SAGE..WL_RETD-1:
            iImmortal++;
            return "[Sage]";
            break;
        case WL_RETD..WL_ELDER-1:
            iImmortal++;
            return "[Retd]";
            break;
        case WL_ELDER..WL_ARCH-1:
            iImmortal++;
            return "[Elder]";
            break;
        case WL_ARCH..WL_GOD-1:
            iImmortal++;
            return "[ArchWiz]";
            break;
        case WL_GOD:
            iImmortal++;
            return "[God]";
            break;
        default:
            iImmortal++;
            return "[ArchWiz]";
            break;
    }
}

int main(string sStr) {
    string sInd;
    int    i, iSize, iObj, iTitles, iAddSplit;
    object *oUs;

    if(!sStr || sStr == "" || sStr == "obj" || sStr == "title") {
        oUs = users();
        iObj = (sStr && sStr == "obj");
        iTitles = (sStr && sStr == "title");
        iAddSplit = 1;
        printf("%|'='79s\n",
               sprintf(" %s: %s ", MUD_NAME, ctime()));
    }
    else {
        switch(sStr) {
            case "mortal":
                oUs = FILTER("Mortal");
                break;
            case "immortal":
                oUs = FILTER("Immortal");
                break;
            case "male":
                oUs = FILTER("Male");
                iAddSplit = 1;
                break;
            case "female":
                oUs = FILTER("Female");
                iAddSplit = 1;
                break;
            case "legendary":
                oUs = FILTER("Legendary");
                break;
            case "arena":
                oUs = FILTER("Arena");
                break;
            default:
                write("Usage: who \
[mortal|immortal|male|female|legendary|arena|obj|title]\n");
                return 1;
                break;
        }
        if(!sizeof(oUs)) {
            printf("There are no %s players currently on %s.\n",
                   sStr,MUD_NAME);
            return 1;
        }
        else
            printf("%|'='79s\n",
                   sprintf(" %s players on %s %s ",
                           CAP(sStr), MUD_NAME, ctime()));
    }

    oUs = sort_array(oUs, "whosort", TO);
    iSize = sizeof(oUs);
    iIdleC = iImmortal = iMortal = 0;

    for(i = 0; i < iSize; i++) {
        sInd = "  ";
        if(query_editing(oUs[i]))
            sInd = "E ";
        else if(query_input_pending(oUs[i]))
            sInd = "I ";
        else if(Arena(oUs[i]))
            sInd = "A ";
        if(iObj)
            printf("%2=s%10=s %s (%s)\n",
                   sInd, makeLevel(oUs[i]),
                   (string)oUs[i]->CRNAME, print_var(oUs[i]));
        else if(iTitles)
            printf("%2=s%10=s %s\n",
                   sInd, makeLevel(oUs[i]), makeTitle(oUs[i], 1));
        else
            printf("%2=s%10=s %-66=s\n",
                   sInd, makeLevel(oUs[i]), makeTitle(oUs[i]));
    }
    printf("%|'='79s\n",
           sprintf(" %d player%s online (%d active)%s ",
                   iSize, (iSize == 1 ? "" : "s"), iSize-iIdleC,
                   iAddSplit ?
                       sprintf(": %s immortal%s, %s mortal%s",
                               (iImmortal ? ""+iImmortal : "no"),
                               (iImmortal == 1 ? "" : "s"),
                               (iMortal ? ""+iMortal : "no"),
                               (iMortal == 1 ? "" : "s")) :
                       ""));
    return 1;
}
