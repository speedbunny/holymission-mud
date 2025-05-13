#include <sys_defs.h>

#define maxnamechr 10
#define maxenvchr  40

int main(string sStr) {
    string sEnv, sSht, sTmp;
    int    i, iSz;
    object *oaUs, oOb, oEnv;

    if(!sStr || sStr == "") {
        oaUs = sort_array(users(),
                          lambda(({'ob1, 'ob2}),
                                 ({#'<,
                                     ({#'call_other, 'ob1, "query_real_name"}),
                                     ({#'call_other, 'ob2, "query_real_name"})
                                 })));
        i = iSz = sizeof(oaUs);
        printf("%|'='79s\n",
               sprintf(" %s: %s ", MUD_NAME, ctime()));
        while(i--) {
            if(!oOb = environment(oaUs[i]))
                sEnv = "-";
            else
                sEnv = print_var(oOb);
            if(sEnv == "-")
                sSht = "No Environment (probably login)";
            else if(oOb)
                sSht = (string)oOb->SHORT;
            if(!sSht || sSht == "")
                sSht = "-";
            else if(sSht[<1..<1] == "\n")
                sSht = sSht[0..<2];
            printf("%-10s: %-40s %-23=s\n",
                   (string)oaUs[i]->CRNAME, sEnv, sprintf("\"%s\"",sSht));
        }
        printf("%|'='79s\n",
               sprintf("%d player%s online ", iSz, iSz ==  1 ? "" : "s"));
        return 1;
    }
    else {
        sTmp = match_name(sStr);
        if(sTmp) {
            oOb = find_player(sTmp);
            if(!oOb)
                printf("%s is not playing at this time.\n", CAP(sTmp));
            else if(!(oEnv = ENV(oOb)))
                printf("%s has no environment... probably at login.\n",
                       CAP(sTmp));
            else
                printf("%s is in '%s': %s\n",
                       CAP(sTmp), print_var(oEnv), oEnv->SHORT);
            return 1;
        }
    }
}
